//
// Created by Twiiz on 2023/5/2.
//

#ifndef PROJYAE_GLBACKEND_HPP
#define PROJYAE_GLBACKEND_HPP

#include "../IRenderBackend.h"

namespace ProjYae
{
    class GLBackend : public IRenderBackend
    {
    public:
        static void initGlobal(void* getProcAddr);

        void draw();
    };
}

#endif //PROJYAE_GLBACKEND_HPP
