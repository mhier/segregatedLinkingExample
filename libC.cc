#include "myinterfaceChanged.h"
#include <stdio.h>

extern "C" {
  IFACE* creator() {
    std::cout << "HIER creatorC BEGIN" << std::endl;
    auto ret = new IMPL();
    std::cout << ret << std::endl;
    ret->nonVirtual();
    ret->fun();
    std::cout << "HIER creatorC END" << std::endl;
    return ret;
  }
}
