//
// Created by Twiiz on 2023/5/2.
//

#include <iostream>
#include <GLFW/glfw3.h>
#include <core/engine/Engine.h>
#include <core/backends/opengl/GlBackend.hpp>

int main() {
    std::cout << "ProjYae Player (Win32 + glfw) built at " << __TIMESTAMP__ << " \n";

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(640, 480, "ProjYaePlayer", NULL, NULL);
    glfwMakeContextCurrent(window);
    ProjYae::GLBackend::initGlobal(reinterpret_cast<void*>(glfwGetProcAddress));

    auto backend = ProjYae::GLBackend();
    backend.init();

    auto engine = ProjYae::Engine();
    engine.init();
    engine.setRenderBackend(&backend);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        engine.notifyNextFrame();
        backend.draw();
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}