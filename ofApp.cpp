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
	
	
	

		int frameNum = ;
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

   /* for (int i = 0; i < dir2.size(); i++) {
		vector <string> result = ofSplitString(dir2.getName(i), "+");*/
	  	//	actualValue = ;
	//	cout << dir2.getName(i) << endl;
		for (ofBuffer::Line it = buffer.getLines().begin(), end = buffer.getLines().end(); it != end; ++it) {
			string line = *it;
			//Split line into strings
			words = ofSplitString(line, ",");

			cout << words[0] << endl;
			//cout << actualV << endl;
			cout << result[0] << endl;

			if (words[0] == result[0]) {

				imageInProcess.load(dir2.getName(actualV));
		    	ofSaveImage(imageInProcess, "sorted/""frame" + ofToString(frameNum) + dir2.getName(actualV) + ".jpg");
				frameNum ++;
				


			}

		////////////////////////  1-0-255  is the last value of the list when it match it runs again the loop with nexgt file
			if (words[0] == "1-0-255") {
				actualV ++;
				//actualV - 1;
			}
		
		}




}



	

}




void ofApp::draw() {

	ofSetWindowTitle(dir.getName(ip));
	ofBackground(90);

	// Draw the webcam feed
	ofSetColor(ofColor::white);
	imageInProcess.draw(0, 0);
	imageCroped.draw(700, 50, 100, 100);

	// Draw a section over the webcam feed to show the region we are averaging
		if (completePic == true) {

			ofSetColor(ofColor::red);
			ofNoFill();
			ofRect(0, 0, imageInProcess.getWidth(), imageInProcess.getHeight());
			
	}
	if (completePic == false) {

		ofSetColor(ofColor::red);
		ofNoFill();
		ofRect(px, py, area, area);
	
	}
	// Draw a rectangle to show the average color of the region
	

	// We have a new frame from the webcam feed, so it's time to recalculate
	// the average color of our desired region
	imageInProcess.load("images/" + dir.getName(ip));

	imageCroped = imageInProcess;
	imageCroped.crop(px, py, area, area);
	pixels = imageCroped.getPixelsRef();


	// Get the pixels from the video grabber

	// Set up variables to calculate the sum of the r, g and b channels
	int rSum = 0;
	int gSum = 0;
	int bSum = 0;

	// Loop through a region of the video feed to get the color sums
	for (int x = 0; x < area; x++) {
		for (int y = 0; y < area; y++) {
			ofColor pixelColor = pixels.getColor(x, y);
			rSum += pixelColor.r;
			gSum += pixelColor.g;
			bSum += pixelColor.b;
		}
	}

	int samples = area * area; // The number of pixels we are averaging

							   // Update the average color
	averageColor.r = rSum / samples;
	averageColor.b = bSum / samples;
	averageColor.g = gSum / samples;






	ofSetColor(averageColor);
	ofFill();
	ofDrawRectangle(700, 250, 100, 100);


	////////////lista fotos

	ofSetColor(255);

	///hsb
	int r = avgHue;
	int g = avgSaturation;
	int b = avgBrightness;



	hue = ofToString(r);
	sat = ofToString(g);
	bri = ofToString(b);

   
    
    if(renameFile == true){
        
	size_t lastindex = dir.getName(ip).find_last_of(".");
            string rawname = dir.getName(ip).substr(0, lastindex);
            
            string fileInfo = "file " + ofToString(ip + 1) + " = " + rawname;
            ofDrawBitmapString(fileInfo, 50,ip * 40 + 400);
            
            ofSaveImage(imageInProcess, hue +"-"+ sat +"-"+ bri+ "+" +"["+ rawname+"]"+  +".jpg");
          
             ip ++;
          imageInProcess.load("images/"+dir.getName(ip));

           renameFile =false;
            }
    

	ofSetColor(255);
	int move = 100;
    ofDrawBitmapString("Press 'left' to  square" ,10 ,455 + move);
	ofDrawBitmapString("Press 'rigth'full pic", 10, 440 + move);


   ofDrawBitmapString("Rect Area",10 ,470 + move);
   ofDrawBitmapString("Press shift to set area", 10, 485 + move);
   ofDrawBitmapString(typeStr,100 , 470 + move);
   ofDrawBitmapString("Press 'alt' to analyse", 10, 510 + move);
   ofDrawBitmapString("Press 'S' to sort files", 10, 530 + move);

 


      //  setArea = false;


  

}

//--------------------------------------------------------------


void ofApp::keyPressed(int key) {

	if (key == OF_KEY_ALT) {
		renameFile = true;

		cout << " press c " << endl;
	}
	if (key == OF_KEY_LEFT) {

		completePic = false;

		cout << " press c " << endl;
	}   if (key == OF_KEY_RIGHT) {

		completePic = true;


		cout << " press c " << endl;
	}
	if (key == OF_KEY_SHIFT) {

		setArea = true;

	}

	if (key == OF_KEY_DEL || key == OF_KEY_BACKSPACE) {
		typeStr = typeStr.substr(0, typeStr.length() - 1);
	}
	else if (key == OF_KEY_RETURN) {
		typeStr += "\n";
	}
	else {
		if (bFirst) {
			typeStr.clear();
			bFirst = false;
		}
		ofAppendUTF8(typeStr, key);

	}

	if (key == 's') {
	
		s = true;


//
//
//
//		int sortingNum = 15;
//		int frameNum = 1;
//		string seq1;
//		ofDirectory dir2;
//		vector <ofImage> images;
//
//		dir2.listDir("");
//
//		for (int i = 0; i < dir2.size(); i++) {
//
//			vector <string> result = ofSplitString(dir2.getName(i), "+");
//		}
//
//		if (dir2.size()) {
//			images.assign(dir2.size(), ofImage());
//		}
//
//		// cout << seq1 << endl;
//
//	
//		//for (int i = 0; i < dir2.size(); i++) {
//		//	vector <string> result = ofSplitString(dir2.getName(i), "+");
//
//		//	if (seq1 == result[0]) {
//
//		//		imageInProcess.load(dir2.getName(i));
//		//		ofSaveImage(imageInProcess, "frame.jpg");
//		//		frameNum = +1;
//
//		//		//	cout << "same" << endl;
//		//	}
//		//}
//
//
//		/////////////////////////////////////////////////////
//
//
//		//Path to the comma delimited file
//		string filePath = "csv/seq1coma.csv";
//       //Load file placed in bin/data
//		ofFile file(filePath);
//
//		if (!file.exists()) {
//			ofLogError("The file " + filePath + " is missing");
//		}
//		ofBuffer buffer(file);
//
//		//Read file line by line
//
//
//		
//	///	for (int i = 0; i < dir2.size(); i++) {
//			vector <string> result = ofSplitString(dir2.getName(actualV), "+");
//	//	actualValue = ;
//
//
//		for (ofBuffer::Line it = buffer.getLines().begin(), end = buffer.getLines().end(); it != end; ++it) {
//			string line = *it;
//			//Split line into strings
//			words = ofSplitString(line, ",");
//		 //	cout << words[0] << endl;
//			cout << result[0] << endl;
//
//			if (words[0] == result[0]) {
//				
//				cout << "same" << endl;
//			
//
//             }
//
//		
//
//
//	
	}

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
	px = x;
	py = y;
	cout << "x" << x;
	cout << "y" << y;

	isCroping = true;
	  cout<< " hue" <<hue<<endl; 
            cout << " sat" << sat <<endl;
            cout << " bri" << bri<<endl;
            



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
