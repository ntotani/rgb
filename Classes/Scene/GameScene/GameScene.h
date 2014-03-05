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

class GameScene : public cocos2d::Layer, IBallListener
{
    BallModel* ballModel;
    cocos2d::Sprite* ball;
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);

    void update(float tick);
    virtual void onBallMove(float x, float y);
};

#endif /* defined(__rgb__GameScene__) */
