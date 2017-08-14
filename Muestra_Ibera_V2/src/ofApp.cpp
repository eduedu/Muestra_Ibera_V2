#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	//ofBackground(255, 255, 255);
	ofBackground(0);
	//ofSetVerticalSync(true);

	// Uncomment this to show movies with alpha channels
	// fingerMovie.setPixelFormat(OF_PIXELS_RGBA);

	video1.load("video1b.mp4");
	//video1.load("zvideo1a.avi");

	//ofDirectShowPlayer dPlayer = new ofDirectShowPlayer();
	//ofPtr <ofBaseVideoPlayer> ptr(dPlayer);
	//video1.setPlayer(ptr);
	//


	
	//video1.setLoopState(OF_LOOP_NORMAL);
	//video1.setUseTexture(false);
	video1.play();
}

//--------------------------------------------------------------
void ofApp::update() {
	///update videos
	video1.update();
	//for (int i = 0; i<10; i++) {
	//	videoPlayer[i].draw();
	//}

	std::stringstream strm;
	strm << "Muestra Ibera V2 - fps: " << ofGetFrameRate();
	ofSetWindowTitle(strm.str());
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(255);
	float escala = 0.3;
	//video1.draw(0, 0);
	video1.draw(20, 20, 1280 * escala, 720 * escala);
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

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

