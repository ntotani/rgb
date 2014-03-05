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

void BallListenerMock::onBallDelete() {
}
