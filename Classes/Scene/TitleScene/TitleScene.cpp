//
//  TitleScene.cpp
//  rgb
//
//  Created by ntotani on 2014/03/06.
//
//

#include "TitleScene.h"

USING_NS_CC;
using namespace cocosbuilder;

Scene* TitleScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = TitleScene::create();

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
    log("tap");
}

SEL_MenuHandler TitleScene::onResolveCCBCCMenuItemSelector(Object * pTarget, const char* pSelectorName) {
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onPressButton", TitleScene::onButtonPressed);
    return NULL;
}

Control::Handler TitleScene::onResolveCCBCCControlSelector(Object * pTarget, const char* pSelectorName) {
    return NULL;
}
