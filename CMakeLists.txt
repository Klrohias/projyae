cmake_minimum_required(VERSION 3.24)
project(ProjYae)

set(CMAKE_CXX_STANDARD 23)
include_directories(./)

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(PROJYAE_DARWIN TRUE)
endif()
if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(PROJYAE_WIN32 TRUE)
endif()

# projects
add_subdirectory(core)

if (${PROJYAE_DARWIN})
    add_subdirectory(player-darwin)
endif()
if (${PROJYAE_WIN32})
    add_subdirectory(player-win32)
endif()