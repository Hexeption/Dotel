//
// Created by Keirb on 13/11/2017.
//

#ifndef DOTEL_SHADERLOADER_H
#define DOTEL_SHADERLOADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <glad/glad.h>

using namespace std;

namespace Dotel
{
    class ShaderLoader
    {
    public:
        ShaderLoader(const char *vertexPath, const char *fragmentPath);

        ~ShaderLoader();

        void Use();

        void Disable();

    protected:
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
}


#endif //DOTEL_SHADERLOADER_H
