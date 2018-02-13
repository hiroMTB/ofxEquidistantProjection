#version 120
#extension GL_EXT_geometry_shader4 : enable

vec4 equidistant( vec4 inVec )
{
    vec4 s = gl_ModelViewMatrix * inVec;
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

    vec4 p0 = gl_PositionIn[0];
    vec4 p1 = gl_PositionIn[1];
    vec4 dir = (p1 - p0) / sub;

    int i;
    for(i=0; i<sub; i++){
        vec4 ep = equidistant(p0 + dir * i);
        gl_Position = ep;
        gl_FrontColor = gl_FrontColorIn[0];
        EmitVertex();
    }

    EndPrimitive();
}
