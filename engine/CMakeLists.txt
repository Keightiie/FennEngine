file(GLOB_RECURSE FENN_ENGINE_SRC CONFIGURE_DEPENDS
        src/*.cpp
        src/*.c
)

add_library(FennEngine STATIC
        ${FENN_ENGINE_SRC}
        ../external/glad/src/glad.c
)

target_include_directories(FennEngine PUBLIC
        include
        ../external/glad/include
        ../external/glm
        ../external/imgui
)

add_library(imgui STATIC
        ../external/imgui/imgui.cpp
        ../external/imgui/imgui_draw.cpp
        ../external/imgui/imgui_tables.cpp
        ../external/imgui/imgui_widgets.cpp

        ../external/imgui/backends/imgui_impl_glfw.cpp
        ../external/imgui/backends/imgui_impl_opengl3.cpp
)

target_include_directories(imgui PUBLIC
        ../external/imgui
        ../external/imgui/backends
)

target_link_libraries(imgui PUBLIC
        glfw
)

target_link_libraries(FennEngine PUBLIC
        glfw
        imgui
)