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
    float totalTime;
public:
    FieldModel();
    vector<BallModel*> getBalls();
    void addListener(IFieldListener* listener);
    void update(float tick);
};

#endif /* defined(__rgb__FieldModel__) */
