#include "imgui/ImGuiScene.h"
#include "imgui/SampleWindow.h"
#include "imgui.h"
#include "backends/imgui_impl_opengl3.h"

void ImGuiScene::render(const ImVec2 &mouse, const ImVec2 &size) {
    ImGuiIO& io = ImGui::GetIO();

    io.MousePos = mouse;
    io.DisplaySize = size;

    ImGui_ImplOpenGL3_NewFrame();

    ImGui::NewFrame();

    for (const auto& window : m_windows) {
        window->draw();
    }

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
