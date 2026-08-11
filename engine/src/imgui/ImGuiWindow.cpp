#include "imgui/ImGuiWindow.h"
#include "../imgui/imgui.h"

void ImGuiWindow::draw() {
  ImGui::Begin("Sample Window");
  ImGui::Text("If you are reading this, the window you're trying to render has not been properly configured.");
  ImGui::End();
}
