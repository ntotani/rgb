//
//  BallListenerMock.cpp
//  rgb
//
//  Created by ntotani on 2014/03/05.
//
//

#include "BallListenerMock.h"

void BallListenerMock::onBallMove(float x, float y) {
    called = true;
    lastX = x;
    lastY = y;
}

bool BallListenerMock::isCalled() {
    return called;
}

float BallListenerMock::getX() {
    return lastX;
}

float BallListenerMock::getY() {
    return lastY;
}
