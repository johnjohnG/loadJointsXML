#pragma once

#include "ofMain.h"
#include<fstream>
#include "ofxXmlSettings.h"
#define NUM_PTS 220
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    ofxXmlSettings settings;
    string message;
 
    ofPoint h[NUM_PTS],n[NUM_PTS],b[NUM_PTS],al[NUM_PTS],ar[NUM_PTS],ll[NUM_PTS],rl[NUM_PTS],lf[NUM_PTS],rf[NUM_PTS];
    ofPoint points[10];
    
    vector<string> data;
    int numberOfSavedPoints,j;
    
    
    //x1,y1 is pivot point x2,y2 decide where to rotate
    void drawHead(int x1, int y1, int x2, int y2);
    void drawBody(int x, int y);
    void drawRightArm(int x1, int y1, int x2, int y2);
    void drawLeftArm(int x1, int y1, int x2, int y2);
    void drawRightLeg(int x1, int y1, int x2, int y2);
    void drawLeftLeg(int x1, int y1, int x2, int y2);
    
    ofImage head, body, arm,rightLeg,leftLeg;
};
