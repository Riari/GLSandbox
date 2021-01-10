#include <glad/glad.h>

#include <GL/VAO.hpp>

namespace OGL::GL
{
    VAO::VAO()
    {
        glGenVertexArrays(1, &m_vao);
    }

    VAO::~VAO()
    {
        glDeleteVertexArrays(1, &m_vao);
    }

    void VAO::Bind() const
    {
        glBindVertexArray(m_vao);
    }

    void VAO::Unbind()
    {
        glBindVertexArray(0);
    }
}
