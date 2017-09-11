//
// Created by Keir on 11/09/2017.
//

#ifndef DOTEL_D_MESH_H
#define DOTEL_D_MESH_H

#include <glm\glm.hpp>
#include <glad\glad.h>
#include <vector>

class D_Vertex
{
public:
    D_Vertex(const glm::vec3 &pos, const glm::vec2 &texCoord)
    {
        this->pos = pos;
        this->texCoord = glm::vec2(texCoord.x, 1.0 - texCoord.y);
    }

    inline glm::vec3 *GetPos()
    { return &pos; }

    inline glm::vec2 *GetTexCoord()
    { return &texCoord; }

protected:
private:
    glm::vec3 pos;
    glm::vec2 texCoord;
};

class D_Mesh
{
public:
    void Draw();

    D_Mesh(D_Vertex *vertices, unsigned int numVertices);

    virtual ~D_Mesh();

protected:
private:
    enum
    {
        POSITION_VB,
        TEXCOORD_VB,

        NUM_BUFFERS
    };

    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffers[NUM_BUFFERS];
    unsigned int m_drawCount;
};

#endif //DOTEL_D_MESH_H
