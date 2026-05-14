#pragma once

class Renderer
{
public:
    void init();
    void clear(float r, float g, float b);

    void resize(int w, int h);

private:
    int m_width = 960;
    int m_height = 540;
};