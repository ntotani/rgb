//
//  GameScene.h
//  rgb
//
//  Created by ntotani on 2014/03/04.
//
//

#ifndef __rgb__GameScene__
#define __rgb__GameScene__

#include "cocos2d.h"
#include "cocosbuilder/CCLayerLoader.h"
#include "cocosbuilder/CCBSelectorResolver.h"
#include "cocosbuilder/CCBMemberVariableAssigner.h"
#include "cocosbuilder/CCBAnimationManager.h"
#include "GUI/CCControlExtension/CCControl.h"

#include "BallModel.h"
#include "IBallListener.h"
#include "FieldModel.h"
#include "IFieldListener.h"

#define TIME_LIMIT 10

USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocosbuilder;

class GameScene :
public Layer,
public IFieldListener,
public CCBSelectorResolver,
public CCBMemberVariableAssigner,
public CCBAnimationManagerDelegate
{
    FieldModel* field;
    LabelTTF* timerLabel;
    LabelTTF* scoreLabel;
    LabelTTF* countDown;
    Node* balls;
    CCBAnimationManager* animationManager;
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);

    void update(float tick);
    virtual void onBallCreate(BallModel* ball);
    virtual void onRestTimeUpdate(float percent);
    virtual void onScore(int score);
    void onTouchEnded(Touch* touch, Event* event);
    
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(Object * pTarget, const char* pSelectorName);
    virtual SEL_CallFuncN onResolveCCBCCCallFuncSelector(Object * pTarget, const char* pSelectorName);
    virtual Control::Handler onResolveCCBCCControlSelector(Object * pTarget, const char* pSelectorName);
    virtual bool onAssignCCBMemberVariable(Object* pTarget, const char* pMemberVariableName, Node* pNode);
    virtual void completedAnimationSequenceNamed(const char *name);

    void onCountDownOne(Node* node);
    void onCountDownTwo(Node* node);
    void onTimeupOk(Object* sender, Control::EventType type);
    void setAnimationManager(CCBAnimationManager* animationManager);
};

class BallListenerImpl : public IBallListener
{
    Sprite* sprite;
    Node* parent;
public:
    BallListenerImpl(Sprite* sprite, Node* parent);
    virtual void onBallMove(float x, float y);
    virtual void onBallDelete();
};

class GameSceneLoader : public LayerLoader {
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(GameSceneLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(GameScene);
};

#endif /* defined(__rgb__GameScene__) */
