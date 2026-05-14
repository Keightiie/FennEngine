#ifndef IMGUISCENE_H
#define IMGUISCENE_H
#include "imgui.h"
#include "ImGuiWindow.h"

#include <vector>
#include <memory>

class ImGuiScene {
public:
    void render(const ImVec2& mouse, const ImVec2& size);

    template<typename T = ImGuiWindow>
    ImGuiWindow* createWindow()
    {
        auto window = std::make_unique<T>();
        m_windows.push_back(std::move(window));
        ImGuiWindow* ptr = window.get();
        return ptr;
    }

private:
    std::vector<std::unique_ptr<ImGuiWindow>> m_windows;
};
#endif
