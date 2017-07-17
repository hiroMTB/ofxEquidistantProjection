#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetColor(255);
    
    sphere.setRadius(radius);
    sphere.setResolution(50);
    sphere.setPosition(0, 0, 0);
    sphere.setOrientation(ofVec3f(90,0,0));
    
    proj.setup();
    proj.getCamera().setPosition(0,0,0);
    proj.getCamera().setNearClip(0.001);
    proj.getCamera().setFarClip(10000);
    
    normalCam.setNearClip(0.01);
    normalCam.setDistance(0.5);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    ofPushMatrix();
    bEqui ? proj.begin() : normalCam.begin();
    
    ofDrawAxis(10);
    
    ofSetColor(255);
    sphere.drawWireframe();

    if(bDraw3dGuide){
        ofNoFill();
        ofSetColor(0,0,255);
        proj.drawEquidistantHemisphere(radius);
    }

    bEqui ? proj.end() : normalCam.end();
    ofPopMatrix();
    
    if(bDraw2dGuide){
        ofSetupScreenOrtho();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofSetColor(0, 255, 0);
        ofNoFill();
        proj.draw2dCircles(ofGetWidth()/2);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key){
        case 'e':
            bEqui = !bEqui;
            break;
        case '2':
            bDraw2dGuide = !bDraw2dGuide;
            break;
        case '3':
            bDraw3dGuide = !bDraw3dGuide;
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    //sphere.setPosition(ofMap(x, 0, 1024, -25, 25), ofMap(y, 0, 1024, -25, 25), 5);
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
