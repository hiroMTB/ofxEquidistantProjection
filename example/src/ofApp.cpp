#include "ofApp.h"

using namespace glm;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetColor(255);
    ofSetCircleResolution(50);
    
    sphere.setRadius(radius);
    sphere.setResolution(10);
    sphere.setPosition(0, 0, 110);
    sphere.setOrientation(ofVec3f(90,0,0));
    
    proj.setup();
    proj.getCamera().setPosition(0,0,0);
    proj.getCamera().setNearClip(0.01);
    proj.getCamera().setFarClip(1000);
    
    normalCam.setNearClip(0.01);
    normalCam.setFarClip(1000);
    normalCam.setDistance(10);
    normalCam.disableMouseInput();
    
    gui.setup();
    prm.add(bEqui.set("Equidistant Projection", true));
    prm.add(bDraw2dGuide.set("Draw 2D Guide", true));
    prm.add(bDraw3dGuide.set("Draw 3D Guide", true));
    prm.add(spherePos.set("Sphere Position", vec3(0,0,0), vec3(-200,-200,-200), vec3(200,200,200)));
    prm.add(radius.set("Sphere Radius", 10, 0, 100));

    gui.add(prm);
}

//--------------------------------------------------------------
void ofApp::update(){
    sphere.setPosition(spherePos);
    sphere.setRadius(radius);
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
        ofPushMatrix();
        ofSetupScreenOrtho();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofSetColor(0, 255, 0);
        ofNoFill();
        proj.draw2dCircles(ofGetWidth()/2);
        ofPopMatrix();
    }

    ofSetupScreenOrtho();
    ofDisableDepthTest();
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
