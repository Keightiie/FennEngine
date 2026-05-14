#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Renderer.h"

#include <iostream>

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

    Renderer renderer;
    renderer.init();

    while (!glfwWindowShouldClose(window))
    {
        renderer.clear(0.1f, 0.1f, 0.15f);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}