//
// Created by Keirb on 13/11/2017.
//

#ifndef DOTEL_TEXTURE_H
#define DOTEL_TEXTURE_H

#include <string>
#include <cassert>
#include <iostream>
#include <glad/glad.h>
#include <soil/stb_image_aug.h>

namespace Dotel
{
    class Texture
    {
    public:
        Texture(const std::string &fileName);

        void Bind(unsigned int unit);

        virtual ~Texture();

    protected:
    private:
        GLuint m_Texture;
    };
}


#endif //DOTEL_TEXTURE_H
