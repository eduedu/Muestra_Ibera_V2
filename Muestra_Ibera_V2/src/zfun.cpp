#include "zfun.h"

static string ofxTrimStringRight(string str) {
	size_t endpos = str.find_last_not_of(" \t\r\n");
	return (string::npos != endpos) ? str.substr(0, endpos + 1) : str;
}

static string ofxTrimStringLeft(string str) {
	size_t startpos = str.find_first_not_of(" \t\r\n");
	return (string::npos != startpos) ? str.substr(startpos) : str;
}

static string ofxTrimString(string str) {
	return ofxTrimStringLeft(ofxTrimStringRight(str));;
}

void cons(string strOrInt) {
	cout << strOrInt  << endl;
	return;
}
void cons(int strOrInt) {
	cout << ofToString(strOrInt) << endl;
	return;
}