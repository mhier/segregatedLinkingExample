#include "myinterfaceChanged.h"


void IMPL::fun() {
  std::cout << "IMPL::fun() from libb" << std::endl;
      std::string x = "B";
      x += std::to_string(42);
      std::cout << "x = " << x << std::endl;
}

void IMPL::nonVirtual() {
  std::cout << "IMPL::nonVirtual() from libb" << std::endl;
}

