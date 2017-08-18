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
	ofDisableArbTex();
	//ofEnableSmoothing();
	//ofEnableAlphaBlending();

	//ofBackground(51);
	ofBackground(50, 0, 0);

	///ocultar consola
	//FreeConsole();

	///VIDEOS: nombres
	nombreA[0] = "video1b.mp4";
	nombreB[0] = "video1a.mp4";
	nombreA[1] = "video2a.mp4";
	nombreB[1] = "video2b.mp4";

	nombreA[2] = "video3a.mp4";
	nombreB[2] = "video3b.mp4";
	nombreA[3] = "video4a.mp4";
	nombreB[3] = "video4b.mp4";

	nombreA[4] = "video5a.mp4";
	nombreB[4] = "video5b.mp4";
	nombreA[5] = "video6a.mp4";
	nombreB[5] = "video6b.mp4";

	nombreA[6] = "video7a.mp4";
	nombreB[6] = "video7b.mp4";
	nombreA[7] = "video8a.mp4";
	nombreB[7] = "video8b.mp4";

	nombreA[8] = "video9a.mp4";
	nombreB[8] = "video9b.mp4";

	///video: load y seteo como loop
	for (int i = 0; i < cantidadDeVideos; i++) {
		videoA[i].load(nombreA[i]);
		videoB[i].load(nombreB[i]);

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

	filtroActual = 0;
	filtros.push_back(new PixelateFilter(videoW, videoH));
	filtros.push_back(new KuwaharaFilter(6));

}


//--------------------------------------------------------------
void ofApp::update() {
	///VIDEO: update
	for (int i = 0; i < cantidadDeVideos; i++) {
		if (i == gIndex)
		{
			if (!videoA[i].isPlaying())
			{
				videoA[i].play();
			}
			if (!videoB[i].isPlaying())
			{
				videoB[i].play();
			}
		}
		else
		{
			if (videoA[i].isPlaying())
			{
				videoA[i].stop();
			}
			if (videoB[i].isPlaying())
			{
				videoB[i].stop();
			}
		}
	}

	videoA[gIndex].update();
	videoB[gIndex].update();


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
			cons(msg_string);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	//ofSetColor(0, 0, 100);
	ofSetColor(255);

	///VIDEO: draw
	if (!mostrarVentana1) {
		videoA[gIndex].draw(20 + (500 * 0), ofGetWindowHeight() - videoH - 30, videoW, videoH);
		
		///efectos
		//ofSetColor(255);
		//ofPushMatrix();
		//ofScale(-1, 1);
		//ofTranslate(-videoW, 0);
		//filtros[filtroActual]->begin();
		////videoA[gIndex].draw(20 + (500 * 0), ofGetWindowHeight() - videoH - 30, videoW, videoH);
		//videoA[gIndex].draw(0, 0);
		//filtros[filtroActual]->end();
		//ofPopMatrix();

		//ofTexture * tex = videoA[gIndex].getTexturePtr();
		//ofTexture tex = videoA[gIndex].getTexture();
		//Rectangle(fill()

		///efecto1
		////ofSetHexColor(0x000000);
		////videoA[gIndex].unlockSharedTexture();
		//ofPixels & pixels = videoA[gIndex].getPixels();
		////videoA[gIndex].lockSharedTexture();

		//int vidWidth = pixels.getWidth();
		//int vidHeight = pixels.getHeight();
		//int nChannels = pixels.getNumChannels();

		//// let's move through the "RGB(A)" char array
		//// using the red pixel to control the size of a circle.
		//for (int i = 4; i < vidWidth; i += 8) {
		//	for (int j = 4; j < vidHeight; j += 8) {
		//		unsigned char r = pixels[(j * 320 + i)*nChannels];
		//		float val = 1 - ((float)r / 255.0f);
		//		ofDrawCircle(400 + i, 20 + j, 2 * val);
		//	}
		//}
	}
	if (!mostrarVentana2) {
		videoB[gIndex].draw(20 + (500 * 1), ofGetWindowHeight() - videoH - 30, videoW, videoH);
	}
	ofDrawBitmapString(nombreA[gIndex], 20, ofGetWindowHeight() - 15);
	ofDrawBitmapString(nombreB[gIndex], 20 + 500, ofGetWindowHeight() - 15);

	///webcam
	//webcam1.draw();
	//webcam2.draw();




	///TEXTOSSSSS
	ofSetColor(210);
	string lineas[20];
	lineas[0] = "<ESC> Salir";
	lineas[1] = "<p> Preview/ventanas";
	lineas[2] = "<f> Fullscreen (desde las ventanas)";
	lineas[3] = "<i> Cambiar indice";
	lineas[15] = "filtro: " + filtros[filtroActual]->getName();
	lineas[16] = "FPS: " + ofToString(ofGetFrameRate());

	///OSC
	lineas[17] = "------------";
	string msj = "INDEX: ";
	msj += ofToString(gIndex);
	lineas[18] = msj;

	///loop impresion de array de texto(lineas)
	int elementos = sizeof(lineas) / sizeof(lineas[0]);
	for (int i = 0; i < elementos; i++)
	{
		if (lineas[i] == "")
		{
			lineas[i] = ".";
		}
		ofDrawBitmapString(lineas[i], 20, 20 * (i + 1));
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

///VENTANA 2222222222222222 -------------------------------------------------------------------------
void ofApp::setupVentana2() {

}

void ofApp::drawVentana2(ofEventArgs & args) {
	if (mostrarVentana2)
	{
		///si no esta visible, agrandar ventana
		if (!estaVisibleVentana2) {
			ofSetWindowShape(videoW, videoH);
			ofSetWindowPosition(videoW + 150, 50);
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
			ofSetWindowPosition((videoW)+150, 10);
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

	///aumentar index
	if (key == 'i')
	{
		gIndex++;
		if (gIndex >= cantidadDeVideos)
		{
			gIndex = 0;
		}
	}

	if (key == ' ') {
		filtroActual++;
		if (filtroActual >= filtros.size()) filtroActual = 0;
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