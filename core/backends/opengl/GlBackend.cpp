//
// Created by Twiiz on 2023/5/2.
//

#include "GlBackend.hpp"
#include <glad/glad.h>

void ProjYae::GLBackend::initGlobal(void* getProcAddr)
{
    gladLoadGLLoader(reinterpret_cast<GLADloadproc>(getProcAddr));
}

void ProjYae::GLBackend::draw()
{
    glClearColor(0, .5, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
}
