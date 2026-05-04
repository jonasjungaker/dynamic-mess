#pragma once
#include <iostream>

class MyObject
{
  public:
    MyObject(int a)
    {
      std::cout << "MyObject::MyObject(" << a << ")" << std::endl;
    }

    void hello(const char* str)
    {
      std::cout << "Hello: " << str << ", value is: " << m_value << std::endl;
    }

    ~MyObject()
    {
      std::cout << "MyObject::~MyObject()" << std::endl;
    }

    void set_value(int value)
    {
      std::cout << "Value is set to: " << value << std::endl;
      m_value = value;
    }
  private:
    int m_value;
};

extern MyObject g_myobject;

