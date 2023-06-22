//
// Created by Twiiz on 2023/5/2.
//

#include <iostream>
#include <GLFW/glfw3.h>
#include <core/engine/Engine.h>
#include <core/render/opengl/GlBackend.hpp>

#include <core/audio/Mp3AudioStream.h>
#include "core/audio/AudioPlayer.h"
#include "core/audio/FlacAudioStream.h"

int main() {
    std::cout << "ProjYae Desktop (glfw) built at " << __TIMESTAMP__ << " \n";

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(640, 480, "ProjYaePlayer", NULL, NULL);
    glfwMakeContextCurrent(window);
    ProjYae::GlBackend::setupGl(reinterpret_cast<void*>(glfwGetProcAddress));

    auto backend = ProjYae::GlBackend();
    backend.init();

    ProjYae::FlacAudioStream stream(std::string("test.flac"));
    ProjYae::AudioPlayer player;
    player.play(&stream);

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