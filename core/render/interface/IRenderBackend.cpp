//
// Created by twiiz on 2023/4/16.
//

#include "IRenderBackend.h"

namespace ProjYae {
    IRenderBackend::~IRenderBackend() = default;

    void IRenderBackend::init() {
    }

    std::unique_ptr<ICommandBuffer> IRenderBackend::getCommandBuffer()
    {
        return nullptr;
    }
} // ProjYae