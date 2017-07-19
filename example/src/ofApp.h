#pragma once

#include "ofMain.h"
#include "ofxEquidistantProjection.h"
#include "ofxGui.h"

class ofApp: public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        ofxEquidistantProjection proj;
    
        ofSpherePrimitive sphere;
        ofEasyCam normalCam;
    
        ofxPanel gui;
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
