#include "ofApp.h"




ofPixels pixels;
ofVideoGrabber grabber;
ofColor averageColor;
ofImage  imageInProcess;
ofRectangle tempSample;
ofRectangle sample;
ofImage imageCroped;
string hue,sat,bri;
bool isCroping;
int scale;
bool renameFile,setArea,editArea;
int area;
int ip;
bool  completePic;
int px;
int py;
float avgHue = 0.0;
float avgSaturation = 0.0;
float avgBrightness = 0.0;
float hue2 = 0.0;
float saturation = 0.0;
float brightness = 0.0;
bool s;
vector<string> words;
int actualV;
int staticV;

float avgR = 0.0;
float avgG = 0.0;
float avgB = 0.0;
float r = 0.0;
float g = 0.0;
float b = 0.0;
int frameNum  ;


void ofApp::setup() {
	actualV = 1;
    scale = 3;
	staticV = 1;
}

void ofApp::update() {
	if (staticV != actualV) {
		s = true;
		staticV = actualV;
	}

	if (s == true) {

		string seq1;
		ofDirectory dir2;
		vector <ofImage> images;

		dir2.listDir("");

     //Path to the comma delimited file
		string filePath = "csv/hsbFull.csv";
		//Load file placed in bin/data
		ofFile file(filePath);

		if (!file.exists()) {
			ofLogError("The file " + filePath + " is missing");
		}
		ofBuffer buffer(file);

		//Read file line by line

		vector <string> result = ofSplitString(dir2.getName(actualV), "+");

////////////////////// this commented code was my first try i try to make a loop inside a loop

   /* for (int i = 0; i < dir2.size(); i++) {
		vector <string> result = ofSplitString(dir2.getName(i), "+");*/
	  	//	actualValue = ;
	//	cout << dir2.getName(i) << endl;
		for (ofBuffer::Line it = buffer.getLines().begin(), end = buffer.getLines().end(); it != end; ++it) {
			string line = *it;
			words = ofSplitString(line, ",");

			cout << words[0] << endl;
			//cout << actualV << endl;
			cout << result[0] << endl;

		if (words[0] == result[0]) {
                             
			imageInProcess.load(dir2.getName(actualV));
		    ofSaveImage(imageInProcess, "sorted/""frame" + ofToString(frameNum) + dir2.getName(actualV) + ".jpg");
			frameNum ++;
			}

		      ////////////////////////  1-0-255  is the last value of the list when it match it runs again the loop with next file
			
		if (words[0] == "1-0-255") {
				actualV ++;
				//actualV - 1;
			}
		
		  }
       }

    }




void ofApp::draw() {

	

  

}

//--------------------------------------------------------------


void ofApp::keyPressed(int key) {

}

void ofApp::keyReleased(int key){



}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){



}





//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
