#include "imgui_setup.h"
#include "imgui.h"
#include "backends/imgui_impl_opengl3.h"

void ImguiSetup::initQt() {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();

    io.BackendPlatformName = "qt";
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    ImGui::StyleColorsDark();
    ImGui_ImplOpenGL3_Init("#version 330");
}
