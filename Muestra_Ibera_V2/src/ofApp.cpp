#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	//ofBackground(255, 255, 255);
	ofBackground(51);
	ofSetVerticalSync(true);

	// Uncomment this to show movies with alpha channels
	// fingerMovie.setPixelFormat(OF_PIXELS_RGBA);

	///VIDEO: load
	//video[0].load("video1a.mp4");
	//video[1].load("video1b.mp4");
	video1.load("video1b.mp4");
	//video2.load("video1b.mp4");
	//video1.load("zvideo1a.avi");
	//video2.load("zvideo1b.avi");
	//video1.load("zvideo1a.avi");
	video2.load("zvideo1b.avi");

	//video1.setLoopState(OF_LOOP_NORMAL);
	//video1.setUseTexture(false);

	///VIDEO: play
	//for (int i = 0; i < cantidadDeVideos; i++) {
	//	video[i].play();
	//}
	video1.play();
	video2.play();

}

//--------------------------------------------------------------
void ofApp::update() {
	///VIDEO: update
	//for (int i = 0; i < cantidadDeVideos; i++) {
	//	video[i].update();
	//}
	video1.update();
	video2.update();

	///window: titulo, fps
	std::stringstream strm;
	strm << "Muestra Ibera V2 - fps: " << ofGetFrameRate();
	ofSetWindowTitle(strm.str());
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(255);

	///VIDEO: draw
	float escala = 0.3;
	float videoW = 1280;
	float videoH = 720;
	//for (int i = 0; i < cantidadDeVideos; i++) {
	//	video[i].draw(20 + (videoW * i), 20, videoW * escala, videoH * escala);
	//}
	video1.draw(20, 20, videoW * escala, videoH * escala);
	video2.draw(500, 20, videoW * escala, videoH * escala);


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

