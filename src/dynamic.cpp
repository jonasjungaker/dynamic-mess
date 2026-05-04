#include <iostream>
#include "global_object.h"


extern "C" void dynamic_function()
{
  std::cout << "dynamic_function()" << std::endl;
  g_myobject.hello("from dynamic");
}

