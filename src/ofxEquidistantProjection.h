/*
 *      ofxEquidistantProjection
 *      openFrameworks addon for equidistant projection (hemisphare mapping, domemaster format for planetarium material)
 *      based on this paper (Japanese)
 *      https://www.jstage.jst.go.jp/article/iteac/2008/0/2008__17-6-1_/_article/-char/ja/
 */

#ifndef OFX_EQUIDISANT_PROJECTION_H
#define OFX_EQUIDISANT_PROJECTION_H

#include "ofMain.h"

namespace ofxequidistantprojection{

    enum class ShaderType{
        POINT_SHADER,
        LINE_SHADER,
        TRIANGLE_SHADER
    };

class ofxEquidistantProjection{
    
public:
    
    ofxEquidistantProjection(){};
    
    bool setup(){
#ifdef TARGET_OPENGLES
        static_assert(1, "ofxEquidistantCam does not support openGL ES");
#else

        int maxOut = triShader.getGeometryMaxOutputCount();
        
        pointShader.setGeometryInputType(GL_POINTS);
        pointShader.setGeometryOutputType(GL_POINTS);
        pointShader.setGeometryOutputCount(1);

        lineShader.setGeometryInputType(GL_LINES);
        lineShader.setGeometryOutputType(GL_LINE_STRIP);
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
        
        return pointShader.isLoaded() && lineShader.isLoaded() && triShader.isLoaded();
#endif
    }
    
    void begin(ShaderType type){
        cam.begin();
        switch(type){
            case ShaderType::POINT_SHADER:
                pointShader.begin();
                pointShader.setUniform3f("eye", cam.getPosition());
                break;
            
            case ShaderType::LINE_SHADER:
                lineShader.begin();
                lineShader.setUniform3f("eye", cam.getPosition());
                break;
            
            case ShaderType::TRIANGLE_SHADER:
                triShader.begin();
                triShader.setUniform3f("eye", cam.getPosition());
                break;

            default:
                static_assert(1, "ofxEquidistantProjection : Unsupported GL primitive");
                break;
        }
    }
    
    void end(ShaderType type){
        switch(type){
            case ShaderType::POINT_SHADER:
                pointShader.end();
                break;

            case ShaderType::LINE_SHADER:
                lineShader.end();
                break;

            case ShaderType::TRIANGLE_SHADER:
                triShader.end();
            break;

            default:
                static_assert(1, "ofxEquidistantProjection : Unsupported GL primitive");
                break;
        }
        cam.end();
    }

    ofCamera & getCamera(){
        return cam;
    }
    
    // 3D & 2D guide drawer
    static void drawEquidistantHemisphere(float radius){
        
        int nCircles = 8;
        for(int i=0; i<nCircles; i++){
            float angle = i * 90.0/nCircles;
            float r = radius * cos(ofDegToRad(angle));
            float h = radius * sin(ofDegToRad(angle));
            ofDrawCircle(glm::vec3(0,0,-h), r);
        }
    }
    
    static void draw2dCircles(float radius){
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
} // namespace ofxequidistantprojection
#endif /* OFX_EQUIDISANT_PROJECTION_H */
