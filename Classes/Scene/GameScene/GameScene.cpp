//
//  GameScene.cpp
//  rgb
//
//  Created by ntotani on 2014/03/04.
//
//

#include "GameScene.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    ballModel = new BallModel(BallColor::RED, visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y, 32, 32, 0, 10);
    ballModel->addListener(this);
    
    ball = Sprite::create("red.png");
    ball->setPosition(Point(ballModel->getX(), ballModel->getY()));
    this->addChild(ball, 0);
    
    this->scheduleUpdate();
    
    return true;
}

void GameScene::update(float tick) {
    ballModel->update(tick);
}

void GameScene::onBallMove(float x, float y) {
    ball->setPosition(x, y);
}

void GameScene::onBallDelete() {
}
