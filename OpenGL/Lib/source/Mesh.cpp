//
// Created by Keirb on 13/11/2017.
//

#include "Mesh.h"


Dotel::Mesh::Mesh(Dotel::Vertex *vertices, unsigned int numVertices)
{
    m_DrawCount = numVertices;

    glGenVertexArrays(1, &m_VertexArrayObject);
    glBindVertexArray(m_VertexArrayObject);

    std::vector<glm::vec3> positions;
    std::vector<glm::vec2> texCoords;

    positions.reserve(numVertices);
    texCoords.reserve(numVertices);

    for (unsigned int i = 0; i < numVertices; i++)
    {
        positions.push_back(*vertices[i].GetPos());
        texCoords.push_back(*vertices[i].GetTexCoord());
    }

    glGenBuffers(NUM_BUFFERS, m_VertexArrayBuffers);
    glBindBuffer(GL_ARRAY_BUFFER, m_VertexArrayBuffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(positions[0]), &positions[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, m_VertexArrayBuffers[TEXCOORD_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(texCoords[0]), &texCoords[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glBindVertexArray(0);
}

Dotel::Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &m_VertexArrayObject);
}

void Dotel::Mesh::Draw()
{
    glBindVertexArray(m_VertexArrayObject);
    glDrawArrays(GL_TRIANGLES,0,m_DrawCount);
    glBindVertexArray(0);
}
