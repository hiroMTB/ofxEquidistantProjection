#version 150

layout (lines) in;
layout (line_strip) out;
layout (max_vertices = 128) out;

uniform mat4 modelViewMatrix;

in vec4 vColor[];

out vec4 Color;

vec4 equidistant( vec4 inVec )
{    
    vec4 s = modelViewMatrix * inVec;
    s.xyz = s.xyz/s.w;
    
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
    float sub = 100;
    vec4 p0 = gl_in[0].gl_Position;
    vec4 p1 = gl_in[1].gl_Position;
    vec4 dir = (p1 - p0) / sub;

    int i;
    for(i=0; i<sub; i++){
        gl_Position = equidistant(p0 + dir * i);
        Color = vColor[0];
        EmitVertex();
    }
    
    EndPrimitive();
}
