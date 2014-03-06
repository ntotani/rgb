//
//  FieldListenerMock.cpp
//  rgb
//
//  Created by ntotani on 2014/03/06.
//
//

#include "FieldListenerMock.h"

FieldListenerMock::FieldListenerMock()
:called(false),
createdBall(NULL),
percent(100),
score(0){
}

void FieldListenerMock::onBallCreate(BallModel* ball) {
    called = true;
    createdBall = ball;
}

void FieldListenerMock::onRestTimeUpdate(float percent) {
    this->percent = percent;
}

void FieldListenerMock::onScore(int score) {
    this->score = score;
}
