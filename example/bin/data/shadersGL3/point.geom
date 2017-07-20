#version 150

layout (points) in;
layout (points) out;
layout (max_vertices = 1) out;

uniform mat4 modelViewMatrix;
uniform vec3 eye;

in vec4 vColor[];

out vec4 Color;

vec4 equidistant( vec4 inVec )
{
    
    vec4 p = modelViewMatrix * inVec;
    vec4 v = vec4(eye, 0);
    p.xyz = p.xyz/p.w;
    
    vec4 s = p - v;
    float d = length(s.xyz);
    float t = acos( abs(s.z/d) ) / 3.14159265 * 2;
    float h = length(s.xy);
    
    if(s.z>0.0) t = 2.0 - t;
    
    vec4 outVec = t * s/h;
    outVec.w = 1;
    return outVec;
}

void main(void)
{
    int i;
    for(i=0; i<gl_in.length(); i++){
        gl_Position = equidistant(gl_in[i].gl_Position);
        Color = vColor[i];
        EmitVertex();
    }
    
    EndPrimitive();
}
