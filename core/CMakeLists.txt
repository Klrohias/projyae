# macros
if (PROJYAE_DARWIN)
    add_compile_definitions(PROJYAE_METAL_ENABLE)
else()
    add_compile_definitions(PROJYAE_VULKAN_ENABLE)
    add_compile_definitions(PROJYAE_OPENGL_ENABLE)
endif()

# compile
add_library(ProjYae engine/Engine.cpp backends/RenderBackend.cpp backends/metal/MetalBackend.mm)

if (PROJYAE_DARWIN)
    target_link_libraries(ProjYae stdc++ "-framework Foundation" "-framework Cocoa" "-framework MetalKit" objc)
    set_target_properties(ProjYae PROPERTIES LINK_FLAGS "-Wl,-F/Library/Frameworks")
endif()
