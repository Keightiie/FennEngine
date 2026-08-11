#ifndef IMGUI_SETUP_H
#define IMGUI_SETUP_H
#include "GLFW/glfw3.h"
class ImguiSetup {
public:
    static void init(GLFWwindow *window);
    static void initQt();
};


#endif //IMGUI_SETUP_H
