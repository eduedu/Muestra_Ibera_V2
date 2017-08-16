#pragma once
#pragma once
#ifndef _CAM // if this class hasn't been defined, the program can define it
#define _CAM// by using this if statement you prevent the class to be called more than once which would confuse the compiler
#include "ofApp.h" // we need to include this to have a reference to the openFrameworks framework
class miWebcam {
	//class myclass { public: myclass(); void Test_Func() {} }; myclass::myclass() { }
public: // place public functions or variables declarations here
	// constructor - used to initialize an object, if no properties are passed the program sets them to the default value
	miWebcam();
	void setup(float _x, float _y, int _deviceIndex);

	// methods, equivalent to specific functions of your class objects
	void update();
	void draw();
	void siguiente();

	// variables
	ofVideoGrabber webcam;
	int deviceIndex;
	float x; 
	float y;
	float  h;
	float  w;


private: // place private functions or variables declarations here
	//nada por aqui
};

#endif