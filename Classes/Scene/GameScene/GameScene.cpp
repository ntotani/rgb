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
    //Point origin = Director::getInstance()->getVisibleOrigin();
    field = new FieldModel(visibleSize.width, visibleSize.height, 3, 32, -100);
    field->addListener(this);
    scheduleUpdate();
    return true;
}

void GameScene::update(float tick) {
    field->update(tick);
}

void GameScene::onBallCreate(BallModel *ball) {
    Sprite* sprite = Sprite::create("red.png");
    sprite->setPosition(Point(ball->getX(), ball->getY()));
    addChild(sprite);
    ball->addListener(new BallListenerImpl(sprite, this));
}

BallListenerImpl::BallListenerImpl(cocos2d::Sprite* sprite, GameScene* parent):sprite(sprite),parent(parent) {
}

void BallListenerImpl::onBallMove(float x, float y) {
    sprite->setPosition(x, y);
}

void BallListenerImpl::onBallDelete() {
    parent->removeChild(sprite);
}
