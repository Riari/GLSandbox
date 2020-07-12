#include <utility>
#include <string>
#include <fstream>
#include <iostream>
#include <spdlog/spdlog.h>
#include "Shader.h"
#include "../../Exception/Exception.h"

Shader::Shader(GLenum type, const std::string& name, const std::string& suffix) : m_id(glCreateShader(type)), m_name(name + suffix) {}

unsigned int Shader::GetID() const {
    return m_id;
}

void Shader::Compile() const {
    std::string source = LoadSource();
    GLchar const *shader_source = source.c_str();
    GLint const shader_length = source.size();
    glShaderSource(m_id, 1, &shader_source, &shader_length);
    glCompileShader(m_id);

    GLint success;
    glGetShaderiv(m_id, GL_COMPILE_STATUS, &success);

    if (success == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetShaderiv(m_id, GL_INFO_LOG_LENGTH, &maxLength);

        std::string info;
        info.resize(static_cast<std::string::size_type>(maxLength - 1));
        glGetShaderInfoLog(m_id, maxLength, &maxLength, info.data());
        throw Exception("Shader compilation failed: " + info);
    }

    spdlog::info("Shader " + m_name + m_extension + " compiled");
}

std::string Shader::LoadSource() const {
    std::string source;
    std::string filepath = m_path + m_name + m_extension;
    std::ifstream fileStream(filepath.c_str(), std::ios::in);

    if (!fileStream.is_open()) throw Exception("Failed to open " + filepath);

    std::string line;
    while (!fileStream.eof()) {
        std::getline(fileStream, line);
        source.append(line + "\n");
    }

    fileStream.close();

    return source;
}
