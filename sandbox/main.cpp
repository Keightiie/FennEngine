#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Renderer.h"
#include "imgui/ImGuiScene.h"
#include "imgui_setup.h"

#include <iostream>

ImGuiScene DEBUG_WINDOWS;

int main()
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window =
        glfwCreateWindow(1280, 720, "Sandbox", nullptr, nullptr);

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to init GLAD\n";
        return -1;
    }


    ImguiSetup::init(window);
    DEBUG_WINDOWS.createWindow<ImGuiWindow>();
    Renderer renderer;
    renderer.init();

    int width, height;
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        renderer.clear(0.1f, 0.1f, 0.15f);

        glfwGetFramebufferSize(window, &width, &height);

        DEBUG_WINDOWS.render({0, 0}, {static_cast<float>(width), static_cast<float>(height)});

        glfwSwapBuffers(window);
    }

    glfwTerminate();
}