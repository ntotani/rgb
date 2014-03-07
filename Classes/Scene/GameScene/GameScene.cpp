//
//  GameScene.cpp
//  rgb
//
//  Created by ntotani on 2014/03/04.
//
//

#include "cocosbuilder/CCNodeLoaderLibrary.h"
#include "GameScene.h"
#include "../../Common/RandomImpl.h"
#include "../TitleScene/TitleScene.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocosbuilder;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    NodeLoaderLibrary* nodeLoaderLibrary = NodeLoaderLibrary::getInstance();
    nodeLoaderLibrary->registerNodeLoader("GameScene", GameSceneLoader::loader());
    CCBReader* ccbReader = new CCBReader(nodeLoaderLibrary);
    ccbReader->autorelease();
    Node* layer = ccbReader->readNodeGraphFromFile("GameScene.ccbi");
    static_cast<GameScene*>(layer)->setAnimationManager(ccbReader->getAnimationManager());

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
    field = new FieldModel(visibleSize.width, visibleSize.height, 1, 32, -100, TIME_LIMIT, new RandomImpl());
    field->addListener(this);

    auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [](Touch* touch, Event* event) { return true; };
    listener->onTouchMoved = [](Touch* touch, Event* event) {};
    listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
    listener->onTouchCancelled = [](Touch* touch, Event* event) {};
    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

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
    balls->addChild(sprite);
    ball->addListener(new BallListenerImpl(sprite, balls));
}

void GameScene::onRestTimeUpdate(float percent) {
    if (percent > 0) {
        timerLabel->setString(StringUtils::format("TIME:%.1f", TIME_LIMIT * percent));
    } else {
        timerLabel->setString("TIME:0");
        animationManager->runAnimationsForSequenceNamed("timeup");
        unscheduleUpdate();
    }
}

void GameScene::onScore(int score) {
    scoreLabel->setString(StringUtils::format("SCORE:%d", score));
}

void GameScene::onTouchEnded(Touch* touch, Event* event) {
    Point p = touch->getLocation();
    field->touch(p.x, p.y);
}

SEL_MenuHandler GameScene::onResolveCCBCCMenuItemSelector(Object * pTarget, const char* pSelectorName) {
    return NULL;
}

SEL_CallFuncN GameScene::onResolveCCBCCCallFuncSelector(Object * pTarget, const char* pSelectorName) {
    CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "onCountDownOne", GameScene:: onCountDownOne);
    CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "onCountDownTwo", GameScene:: onCountDownTwo);
    return NULL;
}

Control::Handler GameScene::onResolveCCBCCControlSelector(Object * pTarget, const char* pSelectorName) {
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onTimeupOk", GameScene::onTimeupOk);
    return NULL;
}

bool GameScene::onAssignCCBMemberVariable(Object* pTarget, const char* pMemberVariableName, Node* pNode) {
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "balls", Node*, balls);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "countDown", LabelTTF*, countDown);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "score", LabelTTF*, scoreLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "time", LabelTTF*, timerLabel);
    return true;
}

void GameScene::completedAnimationSequenceNamed(const char *name) {
    if (strcmp(name, "countDown") == 0) {
        scheduleUpdate();
    }
}

void GameScene::setAnimationManager(CCBAnimationManager* animationManager) {
    CC_SAFE_RELEASE_NULL(this->animationManager);
    this->animationManager = animationManager;
    CC_SAFE_RETAIN(this->animationManager);
    this->animationManager->setDelegate(this);
}

void GameScene::onCountDownOne(Node* node) {
    countDown->setString("1");
}

void GameScene::onCountDownTwo(Node* node) {
    countDown->setString("2");
}

void GameScene::onTimeupOk(Object* sender, Control::EventType type) {
    Director::getInstance()->replaceScene(TransitionFade::create(1.0f, TitleScene::createScene()));
}

BallListenerImpl::BallListenerImpl(Sprite* sprite, Node* parent):sprite(sprite),parent(parent) {
}

void BallListenerImpl::onBallMove(float x, float y) {
    sprite->setPosition(x, y);
}

void BallListenerImpl::onBallDelete() {
    parent->removeChild(sprite);
}
