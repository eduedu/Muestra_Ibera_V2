#include "ofApp.h"
#include "zfun.h"
#include "miWebcam.h"


///webcam
miWebcam webcam1;
miWebcam webcam2;

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(51);

	///VIDEO: load
	video[0].load("video1a.mp4");
	video[1].load("video1b.mp4");
	//video1.load("zvideo1a.avi");
	//video2.load("zvideo1a.avi");
	//video1.load("zvideo1a.avi");
	//video2.load("zvideo1b.avi");

	///video: loop
	for (int i = 0; i < cantidadDeVideos; i++) {
		video[i].setLoopState(OF_LOOP_NORMAL);
	}
	//video1.setUseTexture(false);

	///VIDEO: play
	for (int i = 0; i < cantidadDeVideos; i++) {
		video[i].play();
	}

	///VIDEO: otras configuraciones
	ofSetVerticalSync(true);
	// Uncomment this to show movies with alpha channels
	// fingerMovie.setPixelFormat(OF_PIXELS_RGBA);

	///WEBCAMS
	webcam1.setup(20, 300, 0);
	webcam2.setup(20 + 500, 300, 1);

}

//--------------------------------------------------------------
void ofApp::update() {
	///VIDEO: update
	for (int i = 0; i < cantidadDeVideos; i++) {
		video[i].update();
	}

	///window: titulo, fps
	std::stringstream strm;
	strm << "Muestra Ibera V2 - fps: " << ofGetFrameRate();
	ofSetWindowTitle(strm.str());

	///webcam
	webcam1.update();
	webcam2.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(255);

	///VIDEO: draw
	float escala = 0.3;
	float videoW = 1280;
	float videoH = 720;
	for (int i = 0; i < cantidadDeVideos; i++) {
		video[i].draw(20 + (500 * i), 20, videoW * escala, videoH * escala);
	}


	//ofSetHexColor(0x000000);
	//ofPixels & pixels = video1.getPixels();

	//int vidWidth = pixels.getWidth();
	//int vidHeight = pixels.getHeight();
	//int nChannels = pixels.getNumChannels();

	//// let's move through the "RGB(A)" char array
	//// using the red pixel to control the size of a circle.
	//for (int i = 4; i < vidWidth; i += 8) {
	//	for (int j = 4; j < vidHeight; j += 8) {
	//		unsigned char r = pixels[(j * 320 + i)*nChannels];
	//		float val = 1 - ((float)r / 255.0f);
	//		ofDrawCircle(500 + i, 20 + j, 10 * val);
	//	}
	//}

	///webcam
	webcam1.draw();
	webcam2.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

	///webcam
	if (key == '1')
	{
		webcam1.siguiente();
	}
	if (key == '2')
	{
		webcam2.siguiente();
	}


}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

