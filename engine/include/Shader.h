#pragma once
#include <string>

class Shader
{
public:
    Shader() = default;
    ~Shader();

    bool create(const char* vertexSource, const char* fragmentSource);
    void destroy();

    void bind() const;
    void unbind() const;

    unsigned int id() const { return m_id; };

    void setInt(const char* name, int value) const;
    void setFloat(const char* name, float value) const;

private:
    unsigned int compile(unsigned int type, const char* source);

private:
    unsigned int m_id = 0;

};