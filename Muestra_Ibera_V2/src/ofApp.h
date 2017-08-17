#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxWMFVideoPlayer.h"
#include "zfun.h"

//#include "miWebcam.h"

///OSC
#define PORT 12345

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
		void close();
		//void event
		
		///ventanas
		void setupVentana1();
		void drawVentana1(ofEventArgs & args);
		//void mouseDraggedVentana1(ofMouseEventArgs & args);
		void keyPressedVentana1(ofKeyEventArgs & args);
		void keyPressedVentana2(ofKeyEventArgs & args);
		void setupVentana2();
		void drawVentana2(ofEventArgs & args);


		//ofVideoPlayer video1;
		//ofDirectShowPlayer video1;
		//ofxWMFVideoPlayer video1;
		
		///VIDEOS
		ofxWMFVideoPlayer video[2];
		int cantidadDeVideos = 2;

		//ofxWMFVideoPlayer video1;
		//ofxWMFVideoPlayer video2;

		//ofVideoPlayer video1;
		//ofVideoPlayer video2;

		
		//ofVideoGrabber webcam1;
		//ofVideoGrabber webcam2;
		//int camWidth;
		//int camHeight;

		///OSC
		ofxOscReceiver receiver;
};
