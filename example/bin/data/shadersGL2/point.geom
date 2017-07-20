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

void GeneratePoint(vec4 v1)
{
    gl_Position = v1;
    gl_FrontColor = gl_FrontColorIn[0];
    EmitVertex();
}

void main(void)
{
    // Original Vertex
    int i;
    for(i=0; i<gl_VerticesIn; i++){
        vec4 p = equidistant(gl_PositionIn[i]);
        GeneratePoint(p);
    }
    
    EndPrimitive();
}
