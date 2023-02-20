cmake_minimum_required(VERSION 3.10)

# Enable group projects in folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

project(rewanz-kerfusia)

set(CMAKE_CXX_STANDARD 11)

add_executable(rewanz-kerfusia WIN32
    # Source files
    src/main.cpp
    src/rewanz_kerfusia_app.cpp

    # Include files
    include/delta.h
    include/rewanz_kerfusia_app.h
 "src/gameobject.cpp" "include/gameobject.h")

target_link_libraries(rewanz-kerfusia
    delta-basic)

target_include_directories(rewanz-kerfusia
    PUBLIC dependencies/submodules)

add_subdirectory(dependencies)
