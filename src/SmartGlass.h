

#ifndef __ofApp__SmartGlass__
#define __ofApp__SmartGlass__

#include <iostream>
#include "ofMain.h"

class SmartGlass{
public:
    SmartGlass();
    
    void init(int _h, int _w, int _x, int _y);
    void rampOn();
    void update();
    void display();
    void setRampTimeMillis(int _millis);
    void setOpacity(int _opacityVal);
    
    void setThreshold(int _thresh);
    void setLocation(int _x, int _y);
    
    int opacity;
    int thresh;
    int h, w, x, y;
    ofRectangle rect;
    int rampCounter, startTime;
    int rampTimeMillis;
    bool curState, isRamping, prevState;
    
    
};



#endif /* defined(__ofApp__SmartGlass__) */
