#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "IPVideoGrabber.h"
#include "ofxOpenCv.h"
#include "ofxGui.h"
#include "ofxImageSampler.h"
#include "ofxXmlSettings.h"
#include "SmartGlass.h"
#include "ofxOsc.h"
#include "ofxNetwork.h"
#include "ofxGenericDmx.h"



using ofx::Video::IPVideoGrabber;
using ofx::Video::SharedIPVideoGrabber;


class testApp : public ofBaseApp {
    
#define NUMSAMPLES 6
#define DMX_DATA_LENGTH 512
    
public:
	void setup();
	void update();
	void draw();
    void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
    
    void sendOscMessages();
    void sendDMX();
    
    void setDMXtoZero();
    
    void loadCellsFromXml();
    void saveCellsToXml();
    
    void exit();
    
    //imageSampler
    ofxImageSampler cells[NUMSAMPLES];
    ofxXmlSettings pointsXML;
    vector <int> brightVals;
    ofPoint startPoint;
    ofPixels threshPix;
    
    //ofxCV declarations
	ofxCv::ContourFinder contourFinder;
    ofxCv::RunningBackground background;
    ofImage thresholded;
    
    //IPvideograbber
    SharedIPVideoGrabber grabber;
    ofImage grabFrame;
    float* grabH;
    float* grabW;
    
    //smartglass stuff
    vector<SmartGlass> sg;
    int panelW, panelH;
    
    //GUI
    ofxToggle bShowThresh;
    ofxToggle bShowContour;
    ofxIntSlider backgroundThresh;
    ofxIntSlider minArea;
    ofxIntSlider maxArea;
    ofxIntSlider blurAmount;
    ofxIntSlider erodeAmount;
    ofxIntSlider dilateAmount;
    ofxIntSlider learningTime;
    ofxButton resetbkgnd;
    ofxButton resetCells;
    ofxButton bLoadCells;
    ofxButton bSaveCells;
    ofxToggle bReady;
    ofxIntSlider glassThresh;
    ofxIntSlider stateChangeWait;
    ofxToggle sendtoGlass;
    ofxPanel gui;
    
    
    //OSC messages
    ofxOscSender sender;
    vector <int> prevVals;
    
    ofxUDPManager udpConnection;
    
    //DMX interface
    //pointer to our Enntec DMX USB Pro object
    DmxDevice* dmxInterface_;
    
    //our DMX packet (which holds the channel values + 1st byte for the start code)
    unsigned char dmxData_[DMX_DATA_LENGTH];
    
};
