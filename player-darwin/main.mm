//
// Created by Twiiz on 2023/5/2.
//


#define GLFW_INCLUDE_NONE
#define GLFW_EXPOSE_NATIVE_COCOA

#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#include <iostream>
#include <core/render/metal/MetalBackend.h>
#include <core/engine/Engine.h>


int main() {
    std::cout << "ProjYae Player (macOS + glfw) built at " << __TIMESTAMP__ << " \n";

    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow *window = glfwCreateWindow(640, 480, "ProjYaePlayer", NULL, NULL);

    NSWindow *cocoaWindow = glfwGetCocoaWindow(window);

    auto metalBackend = ProjYae::MetalBackend();
    metalBackend.init();
    metalBackend.attachGlfwWindow(cocoaWindow);


    auto engine = ProjYae::Engine();
    engine.init();
    engine.setRenderBackend(&metalBackend);

    while (!glfwWindowShouldClose(window)) {

        glfwPollEvents();

        @autoreleasepool {
            engine.notifyNextFrame();
            metalBackend.draw();
        }
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}