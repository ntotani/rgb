//
//  IBallListener.h
//  rgb
//
//  Created by ntotani on 2014/03/05.
//
//

#ifndef rgb_IBallListener_h
#define rgb_IBallListener_h

class IBallListener {
public:
    virtual void onBallMove(float x, float y) = 0;
    virtual void onBallDelete() = 0;
};

#endif
