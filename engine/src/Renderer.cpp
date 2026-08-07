#include "Renderer.h"

#include <glad/glad.h>

void Renderer::init()
{
    resize(960, 540);
}

void Renderer::clear(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::resize(int w, int h) {
    glViewport(0, 0, w, h);
    m_width = w;
    m_height = h;
}
