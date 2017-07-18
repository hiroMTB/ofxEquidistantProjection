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

        int maxOut = triShader.getGeometryMaxOutputCount();
        
        pointShader.setGeometryInputType(GL_POINTS);
        pointShader.setGeometryOutputType(GL_POINTS);
        pointShader.setGeometryOutputCount(1);

        lineShader.setGeometryInputType(GL_LINES);
        lineShader.setGeometryOutputType(GL_LINES);
        lineShader.setGeometryOutputCount(128);

        triShader.setGeometryInputType(GL_TRIANGLES);
        triShader.setGeometryOutputType(GL_TRIANGLES);
        triShader.setGeometryOutputCount(3*4);
        
        if(ofIsGLProgrammableRenderer()){
            pointShader.load("shadersGL3/pass.vert", "shadersGL3/pass.frag", "shadersGL3/point.geom");
            lineShader.load("shadersGL3/pass.vert", "shadersGL3/pass.frag", "shadersGL3/line.geom");
            triShader.load("shadersGL3/pass.vert", "shadersGL3/pass.frag", "shadersGL3/tri.geom");
        }else{
            pointShader.load("shadersGL2/pass.vert", "shadersGL2/pass.frag", "shadersGL2/point.geom");
            lineShader.load("shadersGL2/pass.vert", "shadersGL2/pass.frag", "shadersGL2/line.geom");
            triShader.load("shadersGL2/pass.vert", "shadersGL2/pass.frag", "shadersGL2/tri.geom");
        }
#endif
    }
    
    void begin(GLenum type){
        cam.begin();
        switch(type){
            case GL_POINTS:
                pointShader.begin();
                pointShader.setUniform3f("eye", cam.getPosition());
                break;
            
            case GL_LINES:
                lineShader.begin();
                lineShader.setUniform3f("eye", cam.getPosition());
                break;
            
            case GL_TRIANGLES:
                triShader.begin();
                triShader.setUniform3f("eye", cam.getPosition());
                break;
        }
    }
    
    void end(GLenum type){
        switch(type){
            case GL_POINTS:
                pointShader.end();
                break;

            case GL_LINES:
                lineShader.end();
                break;

            case GL_TRIANGLES:
                triShader.end();
            break;
        }
        cam.end();
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
        ofShader pointShader;
        ofShader lineShader;
        ofShader triShader;
    
        ofCamera cam;
};

#endif /* OFX_EQUIDISANT_PROJECTION_H */
