#version 120
#extension GL_EXT_geometry_shader4 : enable

uniform vec3 eye;

vec4 equidistant( vec4 inVec )
{    
    vec4 p = gl_ModelViewMatrix * inVec;
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


void GenerateTriangle(vec4 v1, vec4 v2, vec4 v3)
{
    gl_Position = v1;
    gl_FrontColor = gl_FrontColorIn[0];
    EmitVertex();

    gl_Position = v2;
    gl_FrontColor = gl_FrontColorIn[0];
    EmitVertex();
    
    gl_Position = v3;
    gl_FrontColor = gl_FrontColorIn[0];
    EmitVertex();
    
    EndPrimitive();
}

void main(void)
{
    // Original Vertex
    vec4 iP0 = gl_PositionIn[0];
    vec4 iP1 = gl_PositionIn[1];
    vec4 iP2 = gl_PositionIn[2];
    
    vec4 P0 = (iP0 + iP1) * 0.5;
    vec4 P1 = (iP1 + iP2) * 0.5;
    vec4 P2 = (iP2 + iP0) * 0.5;
    
    iP0 = equidistant(iP0);
    iP1 = equidistant(iP1);
    iP2 = equidistant(iP2);
    P0 = equidistant(P0);
    P1 = equidistant(P1);
    P2 = equidistant(P2);
    
    GenerateTriangle(P0, P1, P2);
    GenerateTriangle(iP0, P0, P2);
    GenerateTriangle(iP1, P1, P0);
    GenerateTriangle(iP2, P2, P1);
}
