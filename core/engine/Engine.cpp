//
// Created by twiiz on 2023/4/15.
//

#include "Engine.h"
#include <exception>

#if defined(PROJYAE_METAL_ENABLE)
#include "../backends/metal/MetalBackend.h"
#endif

namespace ProjYae {
    void Engine::notifyNextFrame() {
    }

    void Engine::init() {
    }

    RenderBackend *Engine::getRenderBackend() const {
        return _renderBackend;
    }

    void Engine::setRenderBackend(RenderBackend *backend) {
        _renderBackend = backend;
    }
} // ProjYae