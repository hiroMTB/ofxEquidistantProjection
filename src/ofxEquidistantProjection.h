/*
 *      ofxEquidistantProjection
 *      openFrameworks addon for equidistant projection (hemisphare mapping, domemaster)
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
    
    void begin(const glm::vec3 & eye){
        shader.begin();
        shader.setUniform3f("eye", eye);        
    }
    
    void end(){
        shader.end();
    }

    ofShader shader;
};

#endif /* OFX_EQUIDISANT_PROJECTION_H */
