//
//  FieldModel.cpp
//  rgb
//
//  Created by ntotani on 2014/03/05.
//
//

#include "FieldModel.h"

FieldModel::FieldModel(float wid, float hei, float spawnSpan, float ballLen, float ballDy, float timeLimit, IRandom* random):
spawnTimer(0),
wid(wid),
hei(hei),
spawnSpan(spawnSpan),
ballLen(ballLen),
ballDy(ballDy),
timeLimit(timeLimit),
restTime(timeLimit),
random(random),
score(0),
currentTarget(BallColor::RED)
{
}

vector<BallModel*> FieldModel::getBalls() {
    return balls;
}

void FieldModel::addListener(IFieldListener* listener) {
    listeners.push_back(listener);
}

void FieldModel::update(float tick) {
    restTime -= tick;
    for (auto it = this->listeners.begin(); it != this->listeners.end(); it++) {
        (*it)->onRestTimeUpdate(restTime / timeLimit);
    }
    if (restTime <= 0) {
        return;
    }
    auto it = balls.begin();
    while (it != balls.end()) {
        BallModel* ball = *it;
        ball->update(tick);
        if (ball->getY() + ball->getHei() / 2 < 0) {
            it = balls.erase(it);
            ball->deleteFromField();
        } else {
            it++;
        }
    }
    spawnTimer += tick;
    if (spawnTimer >= spawnSpan) {
        spawnTimer = 0;
        float x = random->next() % (int)(wid - ballLen) + ballLen / 2;
        BallModel* ball = new BallModel((BallColor)(random->next() % 3), x, hei + ballLen / 2, ballLen, ballLen, 0, ballDy);
        balls.push_back(ball);
        for (auto it = this->listeners.begin(); it != this->listeners.end(); it++) {
            (*it)->onBallCreate(ball);
        }
    }
}

void FieldModel::touch(float x, float y) {
    if (restTime <= 0) {
        return;
    }
    auto it = balls.begin();
    while (it != balls.end()) {
        BallModel* ball = *it;
        if (ball->intersect(x, y) && ball->getColor() == currentTarget) {
            it = balls.erase(it);
            ball->deleteFromField();
            score++;
            for (auto jt = this->listeners.begin(); jt != this->listeners.end(); jt++) {
                (*jt)->onScore(score);
            }
            switch(currentTarget) {
                case RED: currentTarget = GREEN; break;
                case GREEN: currentTarget = BLUE; break;
                case BLUE: currentTarget = RED;
            }
        } else {
            it++;
        }
    }
}
