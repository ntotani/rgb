//
//  TitleScene.cpp
//  rgb
//
//  Created by ntotani on 2014/03/06.
//
//

#include "TitleScene.h"
#include "../GameScene/GameScene.h"
#include "cocosbuilder/CCNodeLoaderLibrary.h"

USING_NS_CC;
using namespace cocosbuilder;

Scene* TitleScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    NodeLoaderLibrary* nodeLoaderLibrary = NodeLoaderLibrary::getInstance();
    nodeLoaderLibrary->registerNodeLoader("TitleScene", TitleSceneLoader::loader());
    CCBReader* ccbReader = new CCBReader(nodeLoaderLibrary);
    ccbReader->autorelease();
    Node* layer = ccbReader->readNodeGraphFromFile("TitleScene.ccbi");

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool TitleScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    return true;
}

void TitleScene::onTouchEnded(Touch* touch, Event* event) {
    //
}

void TitleScene::onButtonPressed(Object* sender) {
    Director::getInstance()->replaceScene(TransitionFade::create(1.0f, GameScene::createScene()));
}

SEL_MenuHandler TitleScene::onResolveCCBCCMenuItemSelector(Object * pTarget, const char* pSelectorName) {
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onPressButton", TitleScene::onButtonPressed);
    return NULL;
}

Control::Handler TitleScene::onResolveCCBCCControlSelector(Object * pTarget, const char* pSelectorName) {
    return NULL;
}
