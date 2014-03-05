//
//  FieldListenerMock.cpp
//  rgb
//
//  Created by ntotani on 2014/03/06.
//
//

#include "FieldListenerMock.h"

FieldListenerMock::FieldListenerMock():called(false),createdBall(NULL) {
}

void FieldListenerMock::onBallCreate(BallModel* ball) {
    called = true;
    createdBall = ball;
}
