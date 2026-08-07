#pragma once

class Renderer
{
public:
    void init();
    void clear(float r, float g, float b, float a = 1.0f);

    void resize(int w, int h);

private:
    int m_width = 960;
    int m_height = 540;
};
