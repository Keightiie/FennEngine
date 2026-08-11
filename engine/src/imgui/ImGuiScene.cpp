#include "imgui/ImGuiScene.h"
#include "imgui/SampleWindow.h"
#include "imgui.h"
#include "backends/imgui_impl_opengl3.h"

#ifndef  FENN_QT
#include "backends/imgui_impl_glfw.h"
#include "GLFW/glfw3.h"
#endif

void ImGuiScene::render(const ImVec2 &mouse, const ImVec2 &size) {


#ifndef FENN_QT
    ImGui_ImplGlfw_NewFrame();
#else
    ImGuiIO& io = ImGui::GetIO();

    io.MousePos = mouse;
    io.DisplaySize = size;
#endif

    ImGui_ImplOpenGL3_NewFrame();
    ImGui::NewFrame();


    for (const auto& window : m_windows) {
        window->draw();
    }

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
