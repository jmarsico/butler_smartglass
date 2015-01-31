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

using ofx::Video::IPVideoGrabber;
using ofx::Video::SharedIPVideoGrabber;


class testApp : public ofBaseApp {
    
#define NUMSAMPLES 12
    
public:
	void setup();
	void update();
	void draw();
    void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
    
    void sendOscMessages();
    
    void loadCellsFromXml();
    void saveCellsToXml();
    
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
    ofxPanel gui;
    
    
    //OSC messages
    ofxOscSender sender;
    vector <int> prevVals;
    
};
