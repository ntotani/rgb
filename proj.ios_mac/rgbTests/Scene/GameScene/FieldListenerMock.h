//
//  FieldListenerMock.h
//  rgb
//
//  Created by ntotani on 2014/03/06.
//
//

#ifndef __rgb__FieldListenerMock__
#define __rgb__FieldListenerMock__

#include "IFieldListener.h"

class FieldListenerMock : public IFieldListener {
public:
    bool called;
    BallModel* createdBall;
    float percent;
    int score;
    FieldListenerMock();
    virtual void onBallCreate(BallModel* ball);
    virtual void onRestTimeUpdate(float percent);
    virtual void onScore(int score);
};

#endif /* defined(__rgb__FieldListenerMock__) */
