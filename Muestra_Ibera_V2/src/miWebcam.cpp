#include "miWebcam.h"


miWebcam::miWebcam() {
};

void miWebcam::setup(float _x, float _y, int _deviceIndex) {
	x = _x;
	y = _y;
	deviceIndex = _deviceIndex;

	//deviceIndex = 0;

	///SETUP
	w = 320;  // try to grab at this size.
	h = 240;

	////we can now get back a list of devices.
	//vector<ofVideoDevice> devices = webcam.listDevices();
	//for (int i = 0; i < devices.size(); i++) {
	//	if (devices[i].bAvailable) {
	//		ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
	//	}
	//	else {
	//		ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
	//	}
	//}

	///selecionar webcam
	webcam.setDeviceID(deviceIndex);
	webcam.setDesiredFrameRate(60);
	webcam.initGrabber(w, h);

};

void miWebcam::update() {
	webcam.update();
};

void miWebcam::draw() {
	ofSetHexColor(0xffffff);
	webcam.draw(x, y, w, h);
};
void miWebcam::siguiente() {
	//cons("CERRANDO CAMARA: "+ ofToString(deviceIndex));

	///cierro la camara activa
	webcam.close();

	///cargo en una variable la lista de camaras existentes
	vector<ofVideoDevice> devices = webcam.listDevices();
	
	//we can now get back a list of devices.
	//for (int i = 0; i < devices.size(); i++) {
	//	if (devices[i].bAvailable) {
	//		ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
	//	}
	//	else {
	//		ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
	//	}
	//}

	///voy recorriendo todas las webcams q hay y pruebo inicializarlas
	///si probe 10 veces, salgo (para evitar un cuelgue);
	int contadorVueltas = 0;
	bool buscarCamara = true;
	int indexTemp = deviceIndex;
	do
	{
		//cons("PROCESANDO: " + ofToString(indexTemp));
		///voy sumando 1 al index-de-device (numero de webcam)
		indexTemp++;
		///si es mayor a la cantidad de 'devices', vuelvo a cero (o sea, la primer webcam q encuentre)
		if (indexTemp > (devices.size() - 1))
		{
			indexTemp = 0;
		}
		///pruebo inicializar la webcam
		deviceIndex = indexTemp;
		//cons("CAMARA SELECCIONADA: " + ofToString(deviceIndex));
		webcam.setDesiredFrameRate(60);
		webcam.setDeviceID(deviceIndex);
		bool todoOk= webcam.initGrabber(h, w);

		///si no hubo error, salir del loop
		if (todoOk) {
			buscarCamara = false;
		}

		///si intente mas de 10 veces, salgo del loop para evitar un cuelgue
		contadorVueltas++;
		if (contadorVueltas>10)
		{
			buscarCamara = false;
		}
		//if (devices[indexTemp].bAvailable) {
		//	buscarCamara = false;
		//	//cons("CAMARA INHABILITADA: " + ofToString(indexTemp));
		//}
	} while (buscarCamara);

	/////cerrar webcam y asignar nuevo index
	//deviceIndex = indexTemp;
	////cons("CAMARA SELECCIONADA: " + ofToString(deviceIndex));
	//webcam.setDesiredFrameRate(60);
	//webcam.setDeviceID(deviceIndex);
	//webcam.initGrabber(h, w);
}

