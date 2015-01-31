//
//  SmartGlass.cpp
//  ofApp
//
//  Created by Jakob Marsico on 9/5/14.
//
//

#include "SmartGlass.h"


SmartGlass::SmartGlass(){}

void SmartGlass::init(int _h, int _w, int _x, int _y){
    h = _h;
    w = _w;
    x = _x;
    y = _y;
    curState = false;
    rampTimeMillis = 100;
    thresh = 0;
    
    rect.set(x, y, w, h);
}

//------------------ SET LOCATION -------------------------
void SmartGlass::setLocation(int _x, int _y){
    x = _x;
    y = _y;
    rect.set(x, y, w, h);
}

//------------------ SET OPACITY -------------------------
void SmartGlass::setOpacity(int _opacityVal){
    
    prevState = curState;
     
    //if the opacity is over 0, turn glass on (true);
    if(_opacityVal > thresh)
    {
        curState = true;
    } else if(_opacityVal <= thresh)
    {
        curState = false;
    }
}

//------------------ SET RAMP TIME -------------------------
void SmartGlass::setRampTimeMillis(int _millis = 800)
{
    rampTimeMillis = _millis;
}

//------------------ SET THRESHOLD -------------------------
void SmartGlass::setThreshold(int _thresh)
{
    thresh = _thresh;
}

//------------------ UPDATE -------------------------
void SmartGlass::update(){
    
    
    //if the glass was OFF before, AND current state is ON turn on ramping
    if(prevState == false && curState == true)
    {
        isRamping = true;
    }
    
    
    //should we start ramping?
    if(prevState == false && isRamping == true)
    {
        startTime = ofGetElapsedTimeMillis();
    }
    
    
    //ramping mode
    if(isRamping)
    {
        rampCounter = ofGetElapsedTimeMillis() - startTime;
        opacity = ofMap(rampCounter, 0, rampTimeMillis, 0, 200);
        
        //once opacity is greater than 255
        if(opacity > 200)
        {
            opacity = 200;          //limit opacity to 255
            isRamping = false;      //turn off ramping
        }
    }
    
    if (curState == false)
    {
        opacity = 30;
    }
    /*
    ofLog() << "opacity: " << opacity << " prevState: " << prevState
    << " curState: " << curState << " isRamping: " << isRamping;
    */
    
}

//------------------ DISPLAY -------------------------
void SmartGlass::display(){
    ofFill();
    ofSetColor(139, 132, 132, opacity);
    ofRect(rect);
}

//------------------ RAMP ON -------------------------
void SmartGlass::rampOn(){
    
}