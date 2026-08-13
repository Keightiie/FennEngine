#include "Shader.h"

#include <iostream>
#include <iostream>
#include <glad/glad.h>

Shader::~Shader() {
    destroy();
}

bool Shader::create(const char *vertexSource, const char *fragmentSource) {
    destroy();
    unsigned int vertex = compile(GL_VERTEX_SHADER, vertexSource);

    if (!vertex)
        return false;

    unsigned int fragment = compile(GL_FRAGMENT_SHADER, fragmentSource);
    if (!fragment){
        glDeleteShader(vertex);
        return false;
    }

    m_id = glCreateProgram();

    glAttachShader(m_id, vertex);
    glAttachShader(m_id, fragment);

    glLinkProgram(m_id);

    int success = 0;
    glGetProgramiv(m_id, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[1024];
        glGetProgramInfoLog(m_id, sizeof(infoLog), nullptr, infoLog);
        std::cout << "Shader creation failed:\n" << infoLog << std::endl;

        glDeleteProgram(m_id);
        m_id = 0;
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);

    return m_id != 0;
}

void Shader::destroy() {
    if (m_id)
    {
        glDeleteProgram(m_id);
        m_id = 0;
    }
}

void Shader::bind() const {
    glUseProgram(m_id);
}

void Shader::unbind() const {
    glUseProgram(0);
}

void Shader::setInt(const char *name, int value) const {
    glUniform1i(glGetUniformLocation(m_id, name), value);
}

void Shader::setFloat(const char *name, float value) const {
    glUniform1f(glGetUniformLocation(m_id, name), value);
}

unsigned int Shader::compile(unsigned int type, const char *source) {
    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    int success = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success) {
        char infoLog[1024];
        glGetShaderInfoLog(shader, sizeof(infoLog), nullptr, infoLog);

        std::cerr << "Shader compilation failed:\n" << infoLog << std::endl;
        glDeleteShader(shader);

        return 0;
    }

    return shader;
}
