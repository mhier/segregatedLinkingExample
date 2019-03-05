#include "myinterfaceChanged.h"
#include <stdio.h>

#include <libxml++/libxml++.h>

struct foo : xmlpp::Node {
  foo();
  ~foo() override;

};

foo::foo() : xmlpp::Node(nullptr) {
  std::cout << "HIER foo()" << std::endl;
}

foo::~foo() {
  std::cout << "HIER foo()" << std::endl;
}

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
