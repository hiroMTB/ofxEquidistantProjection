/*
 *      ofxEquidistantProjection
 *      openFrameworks addon for equidistant projection (hemisphare mapping, domemaster format for planetarium material)
 *      based on this paper (Japanese)
 *      https://www.jstage.jst.go.jp/article/iteac/2008/0/2008__17-6-1_/_article/-char/ja/
 */

#ifndef OFX_EQUIDISANT_PROJECTION_H
#define OFX_EQUIDISANT_PROJECTION_H

#include "ofMain.h"

class ofxEquidistantProjection{
    
public:
    
    ofxEquidistantProjection(){};
    
    void setup(){
#ifdef TARGET_OPENGLES
        static_assert(1, "ofxEquidistantCam does not support openGL ES");
#else
        if(ofIsGLProgrammableRenderer()){
            shader.load("shadersGL3/shader");
        }else{
            shader.load("shadersGL2/shader");
        }
#endif
    }
    
    void begin(){
        cam.begin();
        shader.begin();
        shader.setUniform3f("eye", cam.getPosition());
    }
    
    void end(){
        cam.end();
        shader.end();
    }

    ofCamera & getCamera(){
        return cam;
    }
    
    // 3D & 2D guide drawer
    void drawEquidistantHemisphere(float radius){
        
        int nCircles = 8;
        for(int i=0; i<nCircles; i++){
            float angle = i * 90.0/nCircles;
            float r = radius * cos(ofDegToRad(angle));
            float h = radius * sin(ofDegToRad(angle));
            ofDrawCircle(glm::vec3(0,0,-h), r);
        }
    }
    
    void draw2dCircles(float radius){
        int nCircles = 8;
        for(int i=0; i<nCircles; i++){
            float r = radius/nCircles * (i+1);
            ofDrawCircle(0, 0, r);
        }
    }
    
    private:
        ofShader shader;
        ofCamera cam;
};

#endif /* OFX_EQUIDISANT_PROJECTION_H */
