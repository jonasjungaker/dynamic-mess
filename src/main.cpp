#include <iostream>
#include "global_object.h"
#include <dlfcn.h>

#include <filesystem>

int main(int argc, char* argv[])
{
  std::cout << "Starting main program" << std::endl;
  g_myobject.set_value(43770);
  g_myobject.hello("from main");


  // Below we are loading and calling a dynamic library function
  std::filesystem::path p = argv[0];
  p = p.parent_path() / "libmy_dynamic_library.so";
  void* handle = dlopen(p.c_str(), RTLD_LAZY);
  std::cout << "Shared object loaded: " << handle << std::endl;
  void (*dynamic_function)();
  dynamic_function = (void (*)())dlsym(handle, "dynamic_function");
  std::cout << "Dynamic function loaded: " << dynamic_function << std::endl;
  dynamic_function();
  dlclose(handle);
  std::cout << "Shared object deloaded" << std::endl;


  // Exiting
  std::cout << "Exiting main program" << std::endl;
  return 0; // This line is not needed but included for readability
}

