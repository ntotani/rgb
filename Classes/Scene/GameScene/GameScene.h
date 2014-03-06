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
#include "BallModel.h"
#include "IBallListener.h"
#include "FieldModel.h"
#include "IFieldListener.h"

class GameScene : public cocos2d::Layer, IFieldListener
{
    FieldModel* field;
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);

    void update(float tick);
    virtual void onBallCreate(BallModel* ball);
    void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
};

class BallListenerImpl : public IBallListener
{
    cocos2d::Sprite* sprite;
    GameScene* parent;
public:
    BallListenerImpl(cocos2d::Sprite* sprite, GameScene* parent);
    virtual void onBallMove(float x, float y);
    virtual void onBallDelete();
};

#endif /* defined(__rgb__GameScene__) */
