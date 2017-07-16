#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetColor(255);
    
    sphere.setScale(.5);
    sphere.setResolution(50);
    sphere.setPosition(0, 0, 0);
    sphere.setOrientation(ofVec3f(90,0,0));
    
    proj.setup();
    cam.setPosition(0, 0, 10);
    cam.setNearClip(0.1);
    cam.setFarClip(10000);
    cam.disableMouseInput();
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){

    glm::vec3 eye = cam.getPosition();

    ofBackground(0);
    
    if(bEqui) proj.begin(eye);
    
    cam.begin();
    ofSetColor(255);
    sphere.drawWireframe();
    cam.end();
    
    if(bEqui) proj.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    bEqui = !bEqui;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
