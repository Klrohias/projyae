//
// Created by Twiiz on 2023/4/16.
//

#ifndef PROJYAE_METALBACKEND_H
#define PROJYAE_METALBACKEND_H

#include "../IRenderBackend.h"

#include "../../utilities.h"

#ifdef __OBJC__

#import <MetalKit/MetalKit.h>
#import <Metal/Metal.h>
#import <Foundation/Foundation.h>
#import <QuartzCore/CAMetalLayer.h>

#endif

namespace ProjYae {
    class MetalBackend;
}

#ifdef __OBJC__

@interface RenderDelegate : NSObject <MTKViewDelegate> {
    id <MTLCommandQueue> _queue;
    ProjYae::MetalBackend *_backend;
}
- (void)setBackend:(ProjYae::MetalBackend *)backend;
@end


#endif

namespace ProjYae {
    class MetalBackend : public IRenderBackend {
        __OBJC_TYPE_PTR(NSWindow)_window = __OBJC_NIL;
        __OBJC_ID(MTLDevice) _device = __OBJC_NIL;
        __OBJC_ID(MTLCommandQueue) _queue = __OBJC_NIL;
        __OBJC_TYPE_PTR(CAMetalLayer)_layer = __OBJC_NIL;
        __OBJC_TYPE_PTR(RenderDelegate)_delegate = __OBJC_NIL;
    public:
        void init() override;

        void attachMTKView(__OBJC_TYPE_PTR(MTKView)view);

        void attachGlfwWindow(__OBJC_TYPE_PTR(NSWindow)window);

        void draw();
    };
};

#endif //PROJYAE_METALBACKEND_H
