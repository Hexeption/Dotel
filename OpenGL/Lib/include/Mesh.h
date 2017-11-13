//
// Created by Keirb on 13/11/2017.
//

#ifndef DOTEL_MESH_H
#define DOTEL_MESH_H

#include <glm/glm.hpp>
#include <glad/glad.h>
#include <vector>

namespace Dotel
{

    class Vertex
    {
    public:
        Vertex(const glm::vec3 &pos, const glm::vec2 &texCoord)
        {
            this->m_Pos = pos;
            this->m_TexCoord = glm::vec2(texCoord.x, 1.0 - texCoord.y);
        }

        inline glm::vec3 *GetPos()
        { return &m_Pos; }

        inline glm::vec2 *GetTexCoord()
        { return &m_TexCoord; }

    protected:
    private:
        glm::vec3 m_Pos;
        glm::vec2 m_TexCoord;
    };

    class Mesh
    {
    public:
        Mesh(Vertex *vertices, unsigned int numVertices);

        virtual  ~Mesh();

        void Draw();

    protected:
    private:
        enum
        {
            POSITION_VB,
            TEXCOORD_VB,
            NUM_BUFFERS
        };

        GLuint m_VertexArrayObject;
        GLuint m_VertexArrayBuffers[NUM_BUFFERS];
        unsigned int m_DrawCount;
    };
}


#endif //DOTEL_MESH_H
