vec4 equidistant( mat4 mv, vec4 inVec ){
    
    vec4 s = mv * inVec;
    s.xyz = s.xyz/s.w;
    
    float d = length(s.xyz);
    float t = acos( abs(s.z/d) ) / 3.14159265 * 2;
    float h = length(s.xy);
    
    if(s.z>0.0) t = 2.0 - t;
    
    vec4 outVec = t * s/h;
    outVec.w = 1;
    return outVec;
}
