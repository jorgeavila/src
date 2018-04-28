#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void sortFiles();
    
        ofRectangle tempSample;

 ofDirectory dir;
    vector<ofImage> images;
    
    int currentImage;
    bool bFirst;
    string typeStr;
    
    ofTrueTypeFont  franklinBook14;
    ofTrueTypeFont    verdana14;
    ofTrueTypeFont    verdana30;
    
    ofTrueTypeFont  franklinBook14A;
    ofTrueTypeFont    verdana14A;

    
};
