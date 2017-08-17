#include "ofApp.h"
#include "zfun.h"
#include "miWebcam.h"
#include "ofAppGLFWWindow.h"

///ventanas
bool mostrarVentana1 = true;
bool estaVisibleVentana1 = false;
bool mostrarVentana2 = true;
bool estaVisibleVentana2 = false;


///webcam
miWebcam webcam1;
miWebcam webcam2;

///globales
int gIndex = 0;

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(51);

	///ocultar consola
	FreeConsole();

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

	///OSC
	// listen on the given port
	cout << "listening for osc messages on port " << PORT << "\n";
	receiver.setup(PORT);
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

	///OSC
	// check for waiting messages
	while (receiver.hasWaitingMessages()) {
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage(m);

		// checkear /ibera/index
		if (m.getAddress() == "/ibera/index") {
			// both the arguments are int32's
			gIndex = m.getArgAsInt32(0);
		}
		//else {
		//	// unrecognized message: display on the bottom of the screen
		//	string msg_string;
		//	msg_string = m.getAddress();
		//	msg_string += ": ";
		//	for (int i = 0; i < m.getNumArgs(); i++) {
		//		// get the argument type
		//		msg_string += m.getArgTypeName(i);
		//		msg_string += ":";
		//		// display the argument - make sure we get the right type
		//		if (m.getArgType(i) == OFXOSC_TYPE_INT32) {
		//			msg_string += ofToString(m.getArgAsInt32(i));
		//		}
		//		else if (m.getArgType(i) == OFXOSC_TYPE_FLOAT) {
		//			msg_string += ofToString(m.getArgAsFloat(i));
		//		}
		//		else if (m.getArgType(i) == OFXOSC_TYPE_STRING) {
		//			msg_string += m.getArgAsString(i);
		//		}
		//		else {
		//			msg_string += "unknown";
		//		}
		//	}
		//	// add to the list of strings to display
		//	msg_strings[current_msg_string] = msg_string;
		//	timers[current_msg_string] = ofGetElapsedTimef() + 5.0f;
		//	current_msg_string = (current_msg_string + 1) % NUM_MSG_STRINGS;
		//	// clear the next line
		//	msg_strings[current_msg_string] = "";
		//}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(255);

	///VIDEO: draw
	float escala = 0.3;
	float videoW = 1280;
	float videoH = 720;
	//for (int i = 0; i < cantidadDeVideos; i++) {
	//	video[i].draw(20 + (500 * i), 20, videoW * escala, videoH * escala);
	//}
	if (!mostrarVentana1) {
		video[0].draw(20 + (500 * 0), 20, videoW * escala, videoH * escala);
	}
	if (!mostrarVentana2) {
		video[1].draw(20 + (500 * 1), 20, videoW * escala, videoH * escala);
	}


	///webcam
	webcam1.draw();
	webcam2.draw();

	///OSC
	string msj = "Index: ";
	msj += ofToString(gIndex);
	ofDrawBitmapString(msj, 20, ofGetHeight() - 30);
}

///VENTANA 11111111111111 -------------------------------------------------------------------------
void ofApp::setupVentana1() {

}

void ofApp::drawVentana1(ofEventArgs & args) {
	if (mostrarVentana1)
	{
		///parametros de tamaño
		float escala = 0.3;
		float videoW = 1280;
		float videoH = 720;

		///si no esta visible, agrandar ventana
		if (!estaVisibleVentana1) {
			ofSetWindowShape(videoW*escala, videoH*escala);
			estaVisibleVentana1 = true;
		}

		///DRAW propiamente dicho

		///VIDEO: draw
		//video[1].draw(20 + (500 * i), 20, videoW * escala, videoH * escala);
		video[0].draw(0, 0, ofGetWidth(), ofGetHeight());

	}
	else {
		if (estaVisibleVentana1)
		{

			ofSetWindowShape(0, 0);
			estaVisibleVentana1 = false;
		}
	}
}
void  ofApp::keyPressedVentana1(ofKeyEventArgs & args) {
	//string k = ofToString(args.key);
	//cons(k);
	if (args.key == 'f') {
		//cons("fullscreen");
		ofToggleFullscreen();

	}

}
//void ofApp::mouseDraggedVentana1(ofMouseEventArgs & args) {
//	cout << "test   " << args.x << " , " << args.y << endl;
//	//cons("test");
//}

///VENTANA 2222222222222222 -------------------------------------------------------------------------
void ofApp::setupVentana2() {

}

void ofApp::drawVentana2(ofEventArgs & args) {
	if (mostrarVentana2)
	{
		///parametros de tamaño
		float escala = 0.3;
		float videoW = 1280;
		float videoH = 720;

		///si no esta visible, agrandar ventana
		if (!estaVisibleVentana2) {
			ofSetWindowShape(videoW*escala, videoH*escala);
			estaVisibleVentana2 = true;
		}

		///DRAW propiamente dicho

		///VIDEO: draw
		//video[1].draw(20 + (500 * i), 20, videoW * escala, videoH * escala);
		video[1].draw(0, 0, ofGetWidth(), ofGetHeight());

	}
	else {
		if (estaVisibleVentana2)
		{
			ofSetWindowShape(10, 10);
			estaVisibleVentana2 = false;
		}
	}
}
void  ofApp::keyPressedVentana2(ofKeyEventArgs & args) {

}
///-------------------------------------------------------------------------

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	///ventanas
	if (key == '1')
	{
		mostrarVentana1 = !mostrarVentana1;
	}
	if (key == '2')
	{
		mostrarVentana2 = !mostrarVentana2;
	}

	///webcam
	if (key == '3')
	{
		webcam1.siguiente();
	}
	if (key == '4')
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

void ofApp::close() {
	ofExit();
}