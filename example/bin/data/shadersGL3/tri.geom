#version 150

layout (triangles) in;
layout (triangle_strip) out;
layout (max_vertices = 12) out;

uniform mat4 modelViewMatrix;
uniform vec3 eye;

in vec4 vColor[];

out vec4 Color;

vec4 equidistant( vec4 inVec ){
    
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

void GenerateTriangle(vec4 v1, vec4 v2, vec4 v3, vec4 c)
{
    gl_Position = v1;
    Color = c;
    EmitVertex();

    gl_Position = v2;
    Color = c;
    EmitVertex();
    
    gl_Position = v3;
    Color = c;
    EmitVertex();
    
    EndPrimitive();
}

void main(void)
{
    // Original Vertex
    vec4 iP0 = gl_in[0].gl_Position;
    vec4 iP1 = gl_in[1].gl_Position;
    vec4 iP2 = gl_in[2].gl_Position;
    
    // original Color
    vec4 c0 = vColor[0];
    vec4 c1 = vColor[1];
    vec4 c2 = vColor[2];    

    vec4 P0 = (iP0 + iP1) * 0.5;
    vec4 P1 = (iP1 + iP2) * 0.5;
    vec4 P2 = (iP2 + iP0) * 0.5;
    
    iP0 = equidistant(iP0);
    iP1 = equidistant(iP1);
    iP2 = equidistant(iP2);
    P0 = equidistant(P0);
    P1 = equidistant(P1);
    P2 = equidistant(P2);
    
    GenerateTriangle(P0, P1, P2, c0);
    GenerateTriangle(iP0, P0, P2, c0);
    GenerateTriangle(iP1, P1, P0, c0);
    GenerateTriangle(iP2, P2, P1, c0);
}