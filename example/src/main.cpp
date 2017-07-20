#include "ofApp.h"

int main(){
	
	ofGLWindowSettings settings;
	settings.setGLVersion(3,2);
	settings.width = 1024;
	settings.height = 1024;
	ofCreateWindow(settings);
    
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());
}
