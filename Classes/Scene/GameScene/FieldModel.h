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

using namespace std;

class FieldModel {
    vector<BallModel*> balls;
    vector<IFieldListener*> listeners;
    float spawnTimer;
    float wid;
    float hei;
    int spawnSpan;
    float ballLen;
    float ballDy;
public:
    FieldModel(float wid, float hei, int spawnSpan, float ballLen, float ballDy);
    vector<BallModel*> getBalls();
    void addListener(IFieldListener* listener);
    void update(float tick);
    void touch(float x, float y);
};

#endif /* defined(__rgb__FieldModel__) */
