//
// Created by Keir on 11/09/2017.
//

#ifndef DOTEL_D_TEXTURE_H
#define DOTEL_D_TEXTURE_H

#include <string>
#include <glad\glad.h>
#include <SOIL/stb_image_aug.h>
#include <cassert>
#include <iostream>

class D_Texture
{
public:
    D_Texture(const std::string &fileName);

    void Bind(unsigned int unit);

    virtual ~D_Texture();

protected:
private:
    GLuint m_texture;
};

#endif //DOTEL_D_TEXTURE_H
