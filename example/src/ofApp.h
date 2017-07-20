#pragma once

#include "ofMain.h"
#include "ofxEquidistantProjection.h"
#include "ofxGui.h"

using namespace ofxequidistantprojection;
using namespace glm;

class ofApp: public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
        void begin(ShaderType type);
        void end(ShaderType type);
        
        ofxEquidistantProjection proj;
    
        ofSpherePrimitive sphere;
        ofEasyCam normalCam;
    
        ofxPanel gui;
        ofxLabel fps;
        ofParameterGroup prm;
        ofParameter<bool> bEqui;
        ofParameter<bool> bDraw2dGuide;
        ofParameter<bool> bDraw3dGuide;
        ofParameter<bool> bDrawPoints;
        ofParameter<bool> bDrawLines;
        ofParameter<bool> bDrawTriangles;
    
        ofParameter<glm::vec3> objPos;
        ofParameter<float> objScale;
        
        ofVboMesh vboPoints;
        ofVboMesh vboLines;

};
