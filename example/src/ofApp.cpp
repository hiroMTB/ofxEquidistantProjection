#include "ofApp.h"

using namespace glm;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetColor(255);
    ofSetCircleResolution(50);
    
    sphere.setRadius(10);
    sphere.setResolution(10);
    sphere.setPosition(0, 0, 0);
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
    prm.add(bDraw2dGuide.set("Draw 2D Guide", false));
    prm.add(bDraw3dGuide.set("Draw 3D Guide", false));
    prm.add(bDrawPoints.set("Draw Points", true));
    prm.add(bDrawLines.set("Draw Lines", true));
    prm.add(bDrawTriangles.set("Draw Triangles", true));

    prm.add(objPos.set("Object Position", vec3(0,0,0), vec3(-200,-200,-200), vec3(200,200,200)));
    prm.add(objScale.set("Object Scale", 1, 0, 10.0));

    gui.add(prm);
    
    vboPoints.setMode(OF_PRIMITIVE_POINTS);
    for(int i=0; i<100; i++){
        vboPoints.addVertex(vec3(ofRandom(-2,2), ofRandom(-2,2), ofRandom(-2,2)));
    }
    
    vboLines.setMode(OF_PRIMITIVE_LINES);
    for(int i=0; i<100; i++){
        vboLines.addVertex(vec3(ofRandom(-2,2), ofRandom(-2,2), ofRandom(-2,2)));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
}

void ofApp::begin(ShaderType type){
    ofPushMatrix();
    bEqui ? proj.begin(type) : normalCam.begin();
    ofDrawAxis(10);
    ofTranslate(objPos);
    ofScale(objScale, objScale, objScale);
}

void ofApp::end(ShaderType type){
    bEqui ? proj.end(type) : normalCam.end();
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
        
    if(bDrawPoints){
        begin(ShaderType::POINT_SHADER);
        ofSetColor(255);
        vboPoints.draw();
        sphere.draw(OF_MESH_POINTS); // this does not work since geom input is GL_TRIANGLES    
        end(ShaderType::POINT_SHADER);
    }

    if(bDrawLines){
        begin(ShaderType::LINE_SHADER);
        ofSetColor(255);
        vboLines.draw();
        
        if(bDraw3dGuide){
            ofNoFill();
            ofSetColor(0,0,255);
            proj.drawEquidistantHemisphere(10);
        }
        end(ShaderType::LINE_SHADER);
    }
    
    if(bDrawTriangles){
        begin(ShaderType::TRIANGLE_SHADER);
        ofSetColor(255);
        sphere.drawWireframe();
        end(ShaderType::TRIANGLE_SHADER);
    }    
    
    if(bDraw2dGuide){
        ofPushMatrix();
        ofSetupScreenOrtho();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofSetColor(0,255,0);
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
