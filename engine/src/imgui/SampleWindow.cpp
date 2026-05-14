#include "imgui/SampleWindow.h"
#include "imgui.h"

void SampleWindow::draw() {
    ImGui::Begin("Sample Window");

    static float value = 0.5f;
    ImGui::SliderFloat("Slider", &value, 0.0f, 1.0f);

    if (ImGui::Button("Reset"))
        value = 0.0f;

    ImGui::Text("Hello World!");

    ImGui::End();
}
