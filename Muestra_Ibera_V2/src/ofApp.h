#pragma once

#include "ofMain.h"
#include "ofxFilterLibrary.h"
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
		void exit();
		//void event
		

		///ventanas
		void setupVentana1();
		void drawVentana1(ofEventArgs & args);
		//void mouseDraggedVentana1(ofMouseEventArgs & args);
		void keyPressedVentana1(ofKeyEventArgs & args);
		void keyPressedVentana2(ofKeyEventArgs & args);
		void setupVentana2();
		void drawVentana2(ofEventArgs & args);

		
		///VIDEOS
		const static int cantidadDeVideos = 9;
		ofxWMFVideoPlayer videoA[cantidadDeVideos];
		ofxWMFVideoPlayer videoB[cantidadDeVideos];
		//ofDirectShowPlayer videoA[cantidadDeVideos];
		//ofDirectShowPlayer videoB[cantidadDeVideos];
		//ofVideoPlayer videoA[cantidadDeVideos];
		//ofVideoPlayer videoB[cantidadDeVideos];

		string nombreA[cantidadDeVideos];
		string nombreB[cantidadDeVideos];


		///OSC
		ofxOscReceiver receiver;

		///efectos/filtros
		vector<AbstractFilter *>	filtros;
		int							filtroActual;
};
