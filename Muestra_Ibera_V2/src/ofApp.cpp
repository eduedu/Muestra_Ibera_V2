#include "ofApp.h"
#include "zfun.h"
#include "miWebcam.h"
#include "ofAppGLFWWindow.h"

///DIMENSIONES
float escala = 0.3;
int videoW = 1280 * escala;
int videoH = 720 * escala;


///ventanas
bool mostrarVentana1 = false;
bool estaVisibleVentana1 = false;
bool mostrarVentana2 = false;
bool estaVisibleVentana2 = false;


///webcam
miWebcam webcam1;
miWebcam webcam2;

///globales
int gIndex = 0;

//--------------------------------------------------------------
void ofApp::setup() {
	//ofBackground(51);
	ofBackground(50, 0, 0);

	///ocultar consola
	//FreeConsole();

	///VIDEO: load
	videoA[0].load("video1a.mp4");
	videoB[0].load("video1b.mp4");
	videoA[1].load("video2a.mp4");
	videoB[1].load("video2b.mp4");

	videoA[2].load("video3a.mp4");
	videoB[2].load("video3b.mp4");
	videoA[3].load("video4a.mp4");
	videoB[3].load("video4b.mp4");

	videoA[4].load("video5a.mp4");
	videoB[4].load("video5b.mp4");
	videoA[5].load("video6a.mp4");
	videoB[5].load("video6b.mp4");

	videoA[6].load("video7a.mp4");
	videoB[6].load("video7b.mp4");
	videoA[7].load("video8a.mp4");
	videoB[7].load("video8b.mp4");

	videoA[8].load("video9a.mp4");
	videoB[8].load("video9b.mp4");

	///video: loop
	for (int i = 0; i < cantidadDeVideos; i++) {
		videoA[i].setLoopState(OF_LOOP_NORMAL);
		videoB[i].setLoopState(OF_LOOP_NORMAL);
	}
	//video1.setUseTexture(false);

	///VIDEO: play
	//for (int i = 0; i < cantidadDeVideos; i++) {
	//	videoA[i].play();
	//}
	videoA[gIndex].play();
	videoB[gIndex].play();

	///VIDEO: otras configuraciones
	//ofSetVerticalSync(true);
	// Uncomment this to show movies with alpha channels
	// fingerMovie.setPixelFormat(OF_PIXELS_RGBA);

	///WEBCAMS
	//webcam1.setup(20, 300, 0);
	//webcam2.setup(20 + 500, 300, 1);

	///OSC
	// listen on the given port
	cout << "listening for osc messages on port " << PORT << "\n";
	receiver.setup(PORT);

	///efectos
	// Create resources to store and display another copy of the data
	efecto1 = new unsigned char[videoW * videoH * 3];
	textura1.allocate(videoW, videoH, GL_RGB);

}


//--------------------------------------------------------------
void ofApp::update() {
	///VIDEO: update
	//for (int i = 0; i < cantidadDeVideos; i++) {
	//	video[i].update();
	//}
	videoA[gIndex].update();
	videoB[gIndex].update();

	///efectos
	//for (int i = 0; i < cantidadDeVideos; i++) {
	//	if (video[i].isFrameNew())
	//	{
	//		// Obtain a pointer to the grabber's image data.
	//		ofPixels pixelData = video[i].getPixels();

	//		// Reckon the total number of bytes to examine. 
	//		// This is the image's width times its height,
	//		// times 3 -- because each pixel requires 3 bytes
	//		// to store its R, G, and B color components.  
	//		int nTotalBytes = videoW * videoH* 3;

	//		// For every byte of the RGB image data,
	//		for (int i = 0; i<nTotalBytes; i++) {

	//			// pixelData[i] is the i'th byte of the image;
	//			// subtract it from 255, to make a "photo negative"
	//			efecto1[i] = 255 - pixelData[i];
	//		}

	//		// Now stash the inverted data in an ofTexture
	//		textura1.loadData(efecto1, videoW, videoH, GL_RGB);
	//	}  
	//}



	///window: titulo, fps
	std::stringstream strm;
	strm << "Muestra Ibera V2 - fps: " << ofGetFrameRate();
	ofSetWindowTitle(strm.str());

	///webcam
	//webcam1.update();
	//webcam2.update();

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
		else {
			// unrecognized message: display on the bottom of the screen
			string msg_string;
			msg_string = m.getAddress();
			msg_string += ": ";
			for (int i = 0; i < m.getNumArgs(); i++) {
				// get the argument type
				msg_string += m.getArgTypeName(i);
				msg_string += ":";
				// display the argument - make sure we get the right type
				if (m.getArgType(i) == OFXOSC_TYPE_INT32) {
					msg_string += ofToString(m.getArgAsInt32(i));
				}
				else if (m.getArgType(i) == OFXOSC_TYPE_FLOAT) {
					msg_string += ofToString(m.getArgAsFloat(i));
				}
				else if (m.getArgType(i) == OFXOSC_TYPE_STRING) {
					msg_string += m.getArgAsString(i);
				}
				else {
					msg_string += "unknown";
				}
			}
			//// add to the list of strings to display
			//msg_strings[current_msg_string] = msg_string;
			//timers[current_msg_string] = ofGetElapsedTimef() + 5.0f;
			//current_msg_string = (current_msg_string + 1) % NUM_MSG_STRINGS;
			//// clear the next line
			//msg_strings[current_msg_string] = "";
			cons(msg_string);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	//ofSetColor(0, 0, 100);
	ofSetColor(255);

	///VIDEO: draw


	//for (int i = 0; i < cantidadDeVideos; i++) {
	//	video[i].draw(20 + (500 * i), 20, videoW * escala, videoH * escala);
	//}
	if (!mostrarVentana1) {
		videoA[gIndex].draw(20 + (500 * 0), ofGetWindowHeight() - videoH - 20, videoW, videoH);
	}
	if (!mostrarVentana2) {
		videoB[gIndex].draw(20 + (500 * 1), ofGetWindowHeight() - videoH - 20, videoW, videoH);
	}

	///webcam
	//webcam1.draw();
	//webcam2.draw();

	///efectos
	//textura1.draw(20, 20);


	///efecto2
	//ofSetHexColor(0x000000);
	//ofPixels & pixels = video[1].getPixels();
	//int vidWidth = pixels.getWidth();
	//int vidHeight = pixels.getHeight();
	//int nChannels = pixels.getNumChannels();
	//// let's move through the "RGB(A)" char array
	//// using the red pixel to control the size of a circle.
	//for (int i = 4; i < vidWidth; i += 8) {
	//	for (int j = 4; j < vidHeight; j += 8) {
	//		unsigned char r = pixels[(j * 320 + i)*nChannels];
	//		float val = 1 - ((float)r / 255.0f);
	//		ofDrawCircle(400 + i, 20 + j, 10 * val);
	//	}
	//}


	///TEXTOSSSSS
	ofSetColor(210);
	string lineas[20];
	lineas[0] = "<ESC> Salir";
	lineas[1] = "<P> Preview/ventanas";
	lineas[2] = "<F> Fullscreen (desde las ventanas)";
	lineas[3] = "FPS: " + ofToString(ofGetFrameRate());

	///OSC
	lineas[4] = "------------";
	string msj = "INDEX: ";
	msj += ofToString(gIndex);
	lineas[5] = msj;

	///loop impresion de array de texto(lineas)
	int elementos = sizeof(lineas) / sizeof(lineas[0]);
	for (int i = 0; i < elementos; i++)
	{
		if (lineas[i] != "")
		{
			ofDrawBitmapString(lineas[i], 20, 20 * (i + 1));
		}
	}
}

///VENTANA 11111111111111 -------------------------------------------------------------------------
void ofApp::setupVentana1() {

}

void ofApp::drawVentana1(ofEventArgs & args) {
	if (mostrarVentana1)
	{
		///si no esta visible, agrandar ventana
		if (!estaVisibleVentana1) {
			ofSetWindowShape(videoW, videoH);
			ofSetWindowPosition(150, 50);
			estaVisibleVentana1 = true;
		}

		///DRAW propiamente dicho

		///VIDEO: draw
		//video[1].draw(20 + (500 * i), 20, videoW * escala, videoH * escala);
		//video[0].draw(0, 0, ofGetWidth(), ofGetHeight());
		videoA[gIndex].draw(0, 0, ofGetWidth(), ofGetHeight());

	}
	else {
		if (estaVisibleVentana1)
		{
			ofSetWindowShape(0, 0);
			//ofSetWindowPosition(0, -50);
			ofSetWindowPosition(150, 10);
			estaVisibleVentana1 = false;
		}
	}
}
void  ofApp::keyPressedVentana1(ofKeyEventArgs & args) {
	///este evento sirve para las 2 ventanas!!

	///FULLSCREEN
	if (args.key == 'f') {
		//cons("fullscreen");
		ofToggleFullscreen();

	}

	///ventanas
	if (args.key == 'p')
	{
		mostrarVentana1 = !mostrarVentana1;
		mostrarVentana2 = !mostrarVentana2;
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
		///si no esta visible, agrandar ventana
		if (!estaVisibleVentana2) {
			ofSetWindowShape(videoW, videoH);
			ofSetWindowPosition(videoW+ 150, 50);
			estaVisibleVentana2 = true;
		}

		///DRAW propiamente dicho

		///VIDEO: draw
		//video[1].draw(20 + (500 * i), 20, videoW * escala, videoH * escala);
		//video[1].draw(0, 0, ofGetWidth(), ofGetHeight());
		videoB[gIndex].draw(0, 0, ofGetWidth(), ofGetHeight());

	}
	else {
		if (estaVisibleVentana2)
		{
			ofSetWindowShape(10, 10);
			//ofSetWindowPosition(0, -50);
			ofSetWindowPosition((videoW) + 150, 10);
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
	if (key == 'p')
	{
		mostrarVentana1 = !mostrarVentana1;
		mostrarVentana2 = !mostrarVentana2;
	}

	///webcam
	//if (key == '1')
	//{
	//	webcam1.siguiente();
	//}
	//if (key == '2')
	//{
	//	webcam2.siguiente();
	//}

	///salir
	if (key == 'q')
	{
		ofExit(0);
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
	//cons("CHAUUUUUUUUUUUUU");
	//ofExit(0);
	//ofExitCallback();

}
void ofApp::exit() {
	//cons("CHAUUUUUUUUUUUUU");
	//ofExit(0);
	//ofExitCallback();

}