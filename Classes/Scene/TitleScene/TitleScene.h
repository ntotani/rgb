//
//  TitleScene.h
//  rgb
//
//  Created by ntotani on 2014/03/06.
//
//

#ifndef __rgb__TitleScene__
#define __rgb__TitleScene__

#include "cocos2d.h"
#include "cocosbuilder/CCLayerLoader.h"
#include "cocosbuilder/CCBSelectorResolver.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocosbuilder;

class TitleScene : public Layer, public CCBSelectorResolver
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(TitleScene);
    
    void onTouchEnded(Touch* touch, Event* event);
    void onButtonPressed(Object* sender);
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(Object * pTarget, const char* pSelectorName);
    virtual Control::Handler onResolveCCBCCControlSelector(Object * pTarget, const char* pSelectorName);
};

class TitleSceneLoader : public LayerLoader {
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(TitleSceneLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(TitleScene);
};

#endif /* defined(__rgb__TitleScene__) */
