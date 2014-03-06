//
//  BallModel.cpp
//  rgb
//
//  Created by ntotani on 2014/03/04.
//
//

#include "BallModel.h"

BallModel::BallModel(BallColor color, float x, float y, float wid, float hei, float dx, float dy):color(color),x(x),y(y),wid(wid),hei(hei),dx(dx),dy(dy) {
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

float BallModel::getWid() {
    return wid;
}

float BallModel::getHei() {
    return hei;
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

void BallModel::deleteFromField() {
    for (auto it = this->listeners.begin(); it != this->listeners.end(); it++)
        (*it)->onBallDelete();
}

bool BallModel::intersect(float x, float y) {
    float lx = this->x - wid / 2;
    float rx = lx + wid;
    float ty = this->y + hei / 2;
    float by = ty - hei;
    return x >= lx && x <= rx && y <= ty && y >= by;
}
