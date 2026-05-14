add_library(FennEngine STATIC
        src/Renderer.cpp
        ../external/glad/src/glad.c
)

target_include_directories(FennEngine PUBLIC
        include
        ../external/glad/include
        ../external/glm
)

target_link_libraries(FennEngine PUBLIC
        glfw
)