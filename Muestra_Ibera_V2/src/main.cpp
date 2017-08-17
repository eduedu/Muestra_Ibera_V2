#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"

//========================================================================
int main( ){
	//ofSetupOpenGL(1024,650,OF_WINDOW);			// <-------- setup the GL context

	//// this kicks off the running of my app
	//// can be OF_WINDOW or OF_FULLSCREEN
	//// pass in width and height too:
	//ofRunApp(new ofApp());

	///mainWindow
	ofGLFWWindowSettings settings;
	settings.width = 1024;
	settings.height = 650;
	settings.setPosition(ofVec2f(50, 80));
	settings.resizable = true;
	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
	///-------------------

	///ventana1
	settings.width = 420;
	settings.height = 240;
	settings.setPosition(ofVec2f(150, 50));
	settings.resizable = true;
	// uncomment next line to share main's OpenGL resources with gui
	settings.shareContextWith = mainWindow;	
	shared_ptr<ofAppBaseWindow> ventana1 = ofCreateWindow(settings);
	//ventana1->setVerticalSync(false);
	///-------------------

	///ventana2
	//settings.width = 420;
	//settings.height = 240;
	settings.setPosition(ofVec2f(settings.width+150, 50));
	settings.resizable = true;
	// uncomment next line to share main's OpenGL resources with gui
	settings.shareContextWith = mainWindow;
	shared_ptr<ofAppBaseWindow> ventana2 = ofCreateWindow(settings);
	//ventana1->setVerticalSync(false);
	///-------------------

	shared_ptr<ofApp> mainApp(new ofApp);
	
	///pointers y listeners
	mainApp->setupVentana1();
	mainApp->setupVentana2();
	ofAddListener(ventana1->events().draw, mainApp.get(), &ofApp::drawVentana1);
	ofAddListener(ventana2->events().draw, mainApp.get(), &ofApp::drawVentana2);
	ofAddListener(ventana1->events().keyPressed, mainApp.get(), &ofApp::keyPressedVentana1);
	ofAddListener(ventana2->events().keyPressed, mainApp.get(), &ofApp::keyPressedVentana1);
	//ofAddListener(ventana1->events().mouseDragged, mainApp.get(), &ofApp::mouseDraggedVentana1);
	///-------------------

	ofRunApp(mainWindow, mainApp);
	ofRunMainLoop();

}
