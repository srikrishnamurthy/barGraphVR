#ifndef removeme_Shapes_h
#define removeme_Shapes_h

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

// Uniform index.
enum
{
    UNIFORM_MODELVIEWPROJECTION_MATRIX,
    UNIFORM_NORMAL_MATRIX,
    NUM_UNIFORMS
};
GLint uniforms[NUM_UNIFORMS];

// Attribute index.
enum
{
    ATTRIB_VERTEX,
    ATTRIB_NORMAL,
    NUM_ATTRIBUTES
};

GLfloat gCubeVertexData[216] = 
{
    // Data layout for each line below is:
    // positionX, positionY, positionZ,     normalX, normalY, normalZ
    
    // 6 triangles, 3 square faces
    //right face:
    1.0f, 0.0f, 0.0f,        1.0f, 0.0f, 0.0f,      
    1.0f, 1.0f, 0.0f,         1.0f, 0.0f, 0.0f,     
    1.0f, 0.0f, 1.0f,         1.0f, 0.0f, 0.0f,     
    1.0f, 0.0f, 1.0f,         1.0f, 0.0f, 0.0f,     
    1.0f, 1.0f, 0.0f,         1.0f, 0.0f, 0.0f,     
    1.0f, 1.0f, 1.0f,          1.0f, 0.0f, 0.0f,    
    
    // top face
    1.0f, 1.0f, 0.0f,         0.0f, 1.0f, 0.0f,     
    0.0f, 1.0f, 0.0f,        0.0f, 1.0f, 0.0f,      
    1.0f, 1.0f, 1.0f,          0.0f, 1.0f, 0.0f,    
    1.0f, 1.0f, 1.0f,          0.0f, 1.0f, 0.0f,    
    0.0f, 1.0f, 0.0f,        0.0f, 1.0f, 0.0f,      
    0.0f, 1.0f, 1.0f,         0.0f, 1.0f, 0.0f,     
    
    // left face
    0.0f, 1.0f, 0.0f,        -1.0f, 0.0f, 0.0f,     
    0.0f, 0.0f, 0.0f,       -1.0f, 0.0f, 0.0f,      
    0.0f, 1.0f, 1.0f,         -1.0f, 0.0f, 0.0f,    
    0.0f, 1.0f, 1.0f,         -1.0f, 0.0f, 0.0f,    
    0.0f, 0.0f, 0.0f,       -1.0f, 0.0f, 0.0f,      
    0.0f, 0.0f, 1.0f,        -1.0f, 0.0f, 0.0f,     
    
    /// 
    0.0f, 0.0f, 0.0f,       0.0f, -1.0f, 0.0f,      
    1.0f, 0.0f, 0.0f,        0.0f, -1.0f, 0.0f,     
    0.0f, 0.0f, 1.0f,        0.0f, -1.0f, 0.0f,     
    0.0f, 0.0f, 1.0f,        0.0f, -1.0f, 0.0f,     
    1.0f, 0.0f, 0.0f,        0.0f, -1.0f, 0.0f,     
    1.0f, 0.0f, 1.0f,         0.0f, -1.0f, 0.0f,    
    
    // back
    1.0f, 1.0f, 1.0f,          0.0f, 0.0f, 1.0f,    
    0.0f, 1.0f, 1.0f,         0.0f, 0.0f, 1.0f,     
    1.0f, 0.0f, 1.0f,         0.0f, 0.0f, 1.0f,     
    1.0f, 0.0f, 1.0f,         0.0f, 0.0f, 1.0f,     
    0.0f, 1.0f, 1.0f,         0.0f, 0.0f, 1.0f,     
    0.0f, 0.0f, 1.0f,        0.0f, 0.0f, 1.0f,      
    
    1.0f, 0.0f, 0.0f,        0.0f, 0.0f, -1.0f,     
    0.0f, 0.0f, 0.0f,       0.0f, 0.0f, -1.0f,      
    1.0f, 1.0f, 0.0f,         0.0f, 0.0f, -1.0f,    
    1.0f, 1.0f, 0.0f,         0.0f, 0.0f, -1.0f,    
    0.0f, 0.0f, 0.0f,       0.0f, 0.0f, -1.0f,      
    0.0f, 1.0f, 0.0f,        0.0f, 0.0f, -1.0f,     
};

GLfloat gHLineVertexData[2*6] = 
{
    // positionX, positionY, positionZ,     normalX, normalY, normalZ,
    0.0f, -0.0f, -0.0f,       0.0f, +1.0f, 1.0f,    
    1.0f, -0.0f, -0.0f,        0.0f, +1.0f, 1.0f,   
};

GLfloat gVLineVertexData[2*6] = 
{
    // positionX, positionY, positionZ,     normalX, normalY, normalZ,
    0.0f, 0.0f, 0.0f,       0.0f, +1.0f, 0.0f,      
    0.0f, 0.0f, 1.0f,        0.0f, +1.0f, 0.0f,     
};


GLfloat gBasePlaneData[6*6] = 
{
    // positionX, positionY, positionZ,     normalX, normalY, normalZ,
    0.0f, 0.0f, 0.0f,       0.0f, +1.0f, 0.0f,      
    1.0f, 0.0f, 0.0f,        0.0f, +1.0f, 0.0f,     
    0.0f, 0.0f, 1.0f,        0.0f, +1.0f, 0.0f,     
    0.0f, 0.0f, 1.0f,        0.0f, +1.0f, 0.0f,     
    1.0f, 0.0f, 0.0f,        0.0f, +1.0f, 0.0f,     
    1.0f, 0.0f, 1.0f,         0.0f, +1.0f, 0.0f,    
};

GLfloat gLeftLegendPlaneData[6*8] = 
{
    // positionX, positionY, positionZ,     normalX, normalY, normalZ,  texture X, texture Y
    0.0f, 0.0f, 0.0f,       0.0f, +0.0f, 0.0f,      0.0f, 0.0f,
    3.0f, 0.0f, 0.0f,        0.0f, +0.0f, 0.0f,     1.0f, 0.0f,
    0.0f, 0.0f, 1.0f,        0.0f, +0.0f, 0.0f,     0.0f, 1.0f,
    0.0f, 0.0f, 1.0f,        0.0f, +0.0f, 0.0f,     0.0f, 1.0f,
    3.0f, 0.0f, 0.0f,        0.0f, +0.0f, 0.0f,     1.0f, 0.0f,
    3.0f, 0.0f, 1.0f,         0.0f, +0.0f, 0.0f,    1.0f, 1.0f,
};

GLfloat gTopTextData[6*8] =
{
    // positionX, positionY, positionZ,     normalX, normalY, normalZ,  texture X, texture Y
    0.0f, 0.0f, 0.0f,       0.0f, +0.0f, 0.0f,      0.0f, 0.0f,
    1.0f, 0.0f, 0.0f,        0.0f, +0.0f, 0.0f,     1.0f, 0.0f,
    0.0f, 0.0f, 1.0f,        0.0f, +0.0f, 0.0f,     0.0f, 1.0f,
    0.0f, 0.0f, 1.0f,        0.0f, +0.0f, 0.0f,     0.0f, 1.0f,
    1.0f, 0.0f, 0.0f,        0.0f, +0.0f, 0.0f,     1.0f, 0.0f,
    1.0f, 0.0f, 1.0f,         0.0f, +0.0f, 0.0f,    1.0f, 1.0f,
    

};

#endif
