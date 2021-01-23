#include <glad/glad.h>
#include <glm/ext.hpp>
#include <utility>

#include "Demo/ColoredCube.hpp"
#include "Demo/LightCube.hpp"
#include "GL/VAO.hpp"
#include "GL/Shader/ShaderProgram.hpp"
#include "Utility/Logger.hpp"

using namespace OGLDemo;

ColoredCube::ColoredCube(std::string id, glm::vec3 position, glm::vec3 color, std::shared_ptr<LightCube> light) : OGL::Entity(std::move(id), position), m_light(std::move(light))
{
    auto *pVao = new OGL::VAO();
    pVao->Bind();
    OGL::VBO::SetVertexAttribute(0, 3, 6 * sizeof(float), (void*)0);
    OGL::VBO::SetVertexAttribute(1, 3, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    OGL::VAO::Unbind();

    auto pProgram = std::make_shared<OGL::ShaderProgram>("ColoredCube", OGL::Logger::GL);
    pProgram->Build();
    pProgram->Use();
    pProgram->SetUniform3f("objectColor", color);

    SetVAO(*pVao);
    SetShaderProgram(pProgram);
}

void ColoredCube::Render(std::shared_ptr<OGL::Camera> camera)
{
    m_shaderProgram->Use();
    m_shaderProgram->SetUniform3f("lightPos", m_light->GetTransform().GetPosition());
    m_shaderProgram->SetUniform3f("lightColor", m_light->GetEmissionColor());
    m_shaderProgram->SetUniformMatrix4fv("projection", glm::value_ptr(camera->GetProjectionMatrix()));
    m_shaderProgram->SetUniformMatrix4fv("view", glm::value_ptr(camera->GetViewMatrix()));
    m_shaderProgram->SetUniformMatrix4fv("model", glm::value_ptr(GetTransform().GetModel()));
    m_shaderProgram->SetUniform3f("viewPos", camera->GetPosition());

    m_vao.Bind();

    glDrawArrays(GL_TRIANGLES, 0, 36);
}
