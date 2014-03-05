//
//  BallModel.cpp
//  rgb
//
//  Created by ntotani on 2014/03/04.
//
//

#include "BallModel.h"

BallModel::BallModel(BallColor color, float x, float y, float dx, float dy):color(color),x(x),y(y),dx(dx),dy(dy) {
}

BallColor BallModel::getColor() {
    return color;
}

float BallModel::getX() {
    return x;
}

float BallModel::getY() {
    return y;
}

float BallModel::getDx() {
    return dx;
}

float BallModel::getDy() {
    return dy;
}

void BallModel::addListener(IBallListener* listener) {
    listeners.push_back(listener);
}

void BallModel::update(float tick) {
    x += dx * tick;
    y += dy * tick;
    for (auto it = this->listeners.begin(); it != this->listeners.end(); it++)
        (*it)->onBallMove(x, y);
}
