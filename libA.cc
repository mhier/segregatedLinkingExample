#include "myinterface.h"

struct IMPL : IFACE {

    void fun() override {
      std::cout << "IMPL::fun() from liba" << std::endl;
      std::string x = "A";
      x += std::to_string(42);
      std::cout << "x = " << x << std::endl;
    }
    
    void nonVirtual() {
      std::cout << "IMPL::nonVirtual() from liba" << std::endl;
    }

};


extern "C" {
  IFACE* creator() {
    std::cout << "HIER creatorA BEGIN" << std::endl;
    auto ret = new IMPL();
    ret->fun();
    ret->nonVirtual();
    std::cout << "HIER creatorA END" << std::endl;
    return ret;
  }
}
