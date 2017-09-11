//
// Created by Keir on 11/09/2017.
//

#ifndef DOTEL_D_SHADERLOADER_H
#define DOTEL_D_SHADERLOADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <glad/glad.h>

using namespace std;

class D_ShaderLoader
{
public:
//    TODO: Add geometry shader
    D_ShaderLoader(const char *vertexPath, const char *fragmentPath);

    ~D_ShaderLoader();

//    Enable and disable the shader
    void Use();

    void Disable();

//    Set shader properties


private:
    GLuint shaderProgram;
    string vertexCode, fragmentCode;
    ifstream vShaderFile, fShaderFile;
    stringstream vShaderStream, fShaderStream;
    const char *vShaderCode;
    const char *fShaderCode;

    GLuint vertex, fragment;

    void checkShaderCompile(GLuint shader, string type);

};


#endif //DOTEL_D_SHADERLOADER_H
