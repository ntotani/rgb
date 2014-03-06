//
//  GameScene.cpp
//  rgb
//
//  Created by ntotani on 2014/03/04.
//
//

#include "GameScene.h"
#include "../../Common/RandomImpl.h"

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
    field = new FieldModel(visibleSize.width, visibleSize.height, 3, 32, -100, TIME_LIMIT, new RandomImpl());
    field->addListener(this);

    timerLabel = LabelTTF::create(StringUtils::format("TIME:%d.0", TIME_LIMIT), "Arial", 48.0f);
    Size timerSize = timerLabel->getContentSize();
    timerLabel->setPosition(visibleSize.width - timerSize.width / 2, visibleSize.height - timerSize.height / 2);
    addChild(timerLabel);

    scoreLabel = LabelTTF::create("SCORE:0", "Arial", 48);
    Size scoreSize = scoreLabel->getContentSize();
    scoreLabel->setPosition(scoreSize.width / 2, visibleSize.height - scoreSize.height / 2);
    addChild(scoreLabel);

    auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [](Touch* touch, Event* event) { return true; };
    listener->onTouchMoved = [](Touch* touch, Event* event) {};
    listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
    listener->onTouchCancelled = [](Touch* touch, Event* event) {};
    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    scheduleUpdate();
    return true;
}

void GameScene::update(float tick) {
    field->update(tick);
}

void GameScene::onBallCreate(BallModel *ball) {
    Sprite* sprite = NULL;
    switch (ball->getColor()) {
        case RED:
            sprite = Sprite::create("red.png");
            break;
        case GREEN:
            sprite = Sprite::create("green.png");
            break;
        case BLUE:
            sprite = Sprite::create("blue.png");
            break;
        default:
            break;
    }
    sprite->setPosition(Point(ball->getX(), ball->getY()));
    addChild(sprite);
    ball->addListener(new BallListenerImpl(sprite, this));
}

void GameScene::onRestTimeUpdate(float percent) {
    timerLabel->setString(StringUtils::format("TIME:%.1f", TIME_LIMIT * percent));
}

void GameScene::onTouchEnded(Touch* touch, Event* event) {
    Point p = touch->getLocation();
    //log("%f, %f", p.x, p.y);
    field->touch(p.x, p.y);
}

BallListenerImpl::BallListenerImpl(cocos2d::Sprite* sprite, GameScene* parent):sprite(sprite),parent(parent) {
}

void BallListenerImpl::onBallMove(float x, float y) {
    sprite->setPosition(x, y);
}

void BallListenerImpl::onBallDelete() {
    parent->removeChild(sprite);
}
