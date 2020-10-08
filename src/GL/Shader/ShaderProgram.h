#pragma once

#include <memory>

#include "Shader.h"

class ShaderProgram
{
public:
    explicit ShaderProgram(std::string name);

    ~ShaderProgram();

    void Compile() const;
    void Link();
    void DeleteShaders();
    void Use() const;

    [[nodiscard]] int GetUniformLocation(const std::string &name) const;

    void SetUniformBool(const std::string &name, bool value) const;
    void SetUniformInt(const std::string &name, int value) const;
    void SetUniformFloat(const std::string &name, float value) const;
    void SetUniform3f(const std::string &name, std::vector<float> values) const;
    void SetUniform4f(const std::string &name, std::vector<float> values) const;
    void SetUniformMatrix4fv(const std::string &name, float *value_ptr) const;

private:
    const std::string m_name;
    unsigned int m_program;
    Shader *m_vertexShader;
    Shader *m_fragmentShader;

    bool m_isLinked = false;
};