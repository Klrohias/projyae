//
// Created by mac on 2023/4/16.
//

#include "MetalBackend.h"

MTLClearColor debugClearColor = MTLClearColorMake(0, .5, 1, 1); // TODO

namespace ProjYae {
    void MetalBackend::init() {
        _device = MTLCreateSystemDefaultDevice();
        _queue = [_device newCommandQueue];
        _layer = [CAMetalLayer layer];
        _layer.device = _device;
        _layer.opaque = YES;

        _delegate = [[RenderDelegate alloc] init];
        [_delegate setBackend:this];
    }

    void MetalBackend::attachMTKView(MTKView *view) {
        view.device = _device;
        view.paused = NO;
        view.enableSetNeedsDisplay = NO;
        view.delegate = _delegate;
    }

    void MetalBackend::attachGlfwWindow(NSWindow *window) {
        window.contentView.layer = _layer;
        window.contentView.wantsLayer = YES;
    }

    void MetalBackend::draw() {
        // TODO
        id<CAMetalDrawable> surface = [_layer nextDrawable];

        MTLRenderPassDescriptor *pass = [MTLRenderPassDescriptor renderPassDescriptor];
        pass.colorAttachments[0].clearColor = debugClearColor;
        pass.colorAttachments[0].loadAction  = MTLLoadActionClear;
        pass.colorAttachments[0].storeAction = MTLStoreActionStore;
        pass.colorAttachments[0].texture = surface.texture;

        id<MTLCommandBuffer> buffer = [_queue commandBuffer];
        id<MTLRenderCommandEncoder> encoder = [buffer renderCommandEncoderWithDescriptor:pass];
        [encoder endEncoding];
        [buffer presentDrawable:surface];
        [buffer commit];
    }
};


@implementation RenderDelegate
- (void)drawInMTKView:(MTKView *)view {
    _backend->draw();
}

- (void)setBackend:(ProjYae::MetalBackend *)backend {
    _backend = backend;
}

- (void)mtkView:(nonnull MTKView *)view drawableSizeWillChange:(CGSize)size {
    // ignored
}

@end