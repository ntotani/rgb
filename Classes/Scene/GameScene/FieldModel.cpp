//
//  FieldModel.cpp
//  rgb
//
//  Created by ntotani on 2014/03/05.
//
//

#include "FieldModel.h"

FieldModel::FieldModel():totalTime(0) {
}

vector<BallModel*> FieldModel::getBalls() {
    return balls;
}

void FieldModel::addListener(IFieldListener* listener) {
    listeners.push_back(listener);
}

void FieldModel::update(float tick) {
    totalTime += tick;
    for (auto it = this->balls.begin(); it != this->balls.end(); it++) {
        (*it)->update(tick);
    }
    if ((int)totalTime % 3 == 0) {
        BallModel* ball = new BallModel(BallColor::RED, 0, 0, 0, 0);
        balls.push_back(ball);
        for (auto it = this->listeners.begin(); it != this->listeners.end(); it++) {
            (*it)->onBallCreate(ball);
        }
    }
}
