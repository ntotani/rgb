//
//  FieldModel.cpp
//  rgb
//
//  Created by ntotani on 2014/03/05.
//
//

#include "FieldModel.h"

FieldModel::FieldModel(float wid, float hei, int spawnSpan, float ballLen, float ballDy):totalTime(0),wid(wid),hei(hei),spawnSpan(spawnSpan),ballLen(ballLen),ballDy(ballDy) {
}

vector<BallModel*> FieldModel::getBalls() {
    return balls;
}

void FieldModel::addListener(IFieldListener* listener) {
    listeners.push_back(listener);
}

void FieldModel::update(float tick) {
    totalTime += tick;
    auto it = balls.begin();
    while (it != balls.end()) {
        BallModel* ball = *it;
        ball->update(tick);
        if (ball->getY() - ball->getHei() / 2 < 0) {
            it = balls.erase(it);
            ball->deleteFromField();
        } else {
            it++;
        }
    }
    if ((int)totalTime % spawnSpan == 0) {
        BallModel* ball = new BallModel(BallColor::RED, 0, hei + ballLen / 2, ballLen, ballLen, 0, ballDy);
        balls.push_back(ball);
        for (auto it = this->listeners.begin(); it != this->listeners.end(); it++) {
            (*it)->onBallCreate(ball);
        }
    }
}
