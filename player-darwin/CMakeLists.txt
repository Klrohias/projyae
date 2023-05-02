# Packages
find_package(glfw3 CONFIG REQUIRED)

# Build
add_executable(ProjYaePlayer main.mm)

# Link
target_link_libraries(ProjYaePlayer PRIVATE glfw)
target_link_libraries(ProjYaePlayer PRIVATE ProjYae)