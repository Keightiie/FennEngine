#pragma once

class Texture {
public:
    Texture() = default;
    ~Texture();

    bool create(const void* pixels, int width, int height);
    void destroy();

    void bind(unsigned int slot = 0) const;
    void unbind() const;

    unsigned int id() const { return m_id; };
    int width() const { return m_width; };
    int height() const { return m_height; };

private:
    unsigned int m_id = 0;
    int m_width = 0;
    int m_height = 0;

};