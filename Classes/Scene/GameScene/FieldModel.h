//
//  FieldModel.h
//  rgb
//
//  Created by ntotani on 2014/03/05.
//
//

#ifndef __rgb__FieldModel__
#define __rgb__FieldModel__

#include <vector>
#include "BallModel.h"
#include "IFieldListener.h"
#include "../../Common/IRandom.h"

using namespace std;

class FieldModel {
    vector<BallModel*> balls;
    vector<IFieldListener*> listeners;
    float spawnTimer;
    float wid;
    float hei;
    float spawnSpan;
    float ballLen;
    float ballDy;
    float restTime;
    float timeLimit;
    IRandom* random;
    int score;
    BallColor currentTarget;
public:
    FieldModel(float wid, float hei, float spawnSpan, float ballLen, float ballDy, float timeLimit, IRandom* random);
    vector<BallModel*> getBalls();
    void addListener(IFieldListener* listener);
    void update(float tick);
    void touch(float x, float y);
};

#endif /* defined(__rgb__FieldModel__) */
