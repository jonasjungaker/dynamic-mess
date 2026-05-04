# Dynamic linking

This short snippet of code showcases how global variables are linked in dynamic and static libraries. This has confused me a couple times, it felt nice to walk through it with concrete examples.

In short, if you have a shared object that you load dynamically, any statically linked global variables will exist twice if both the main executable and the shared object depends on them. This is shown with the `MyObject g_myobject` global in the static library in this project.

## Build

This currently only builds on linux, use CMake for easy building and compiling. If you want your IDE to help you understand the code, you should probably include the `-DCMAKE_EXPORT_COMPILE_COMMANDS=ON` flag in the configuration command.

Clone the repository and in the root of the repository, call the following command to build the project:

`cmake -S . -B build && cmake --build build`

Once you have built the project, you can run the main executable by running:

`./build/my_program`

## Contributor

Jonas Jungåker

Copyright 2026

