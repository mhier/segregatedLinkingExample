#include <iostream>

struct IFACE {

    virtual void unusedVirt() { std::cout << "*** unusedVirt" << std::endl;  }
    void unused() { std::cout << "*** unused" << std::endl;  }
  
    void nonVirtual();
    virtual void fun() = 0;

};

struct IMPL : IFACE {

    void fun() override;
    void nonVirtual();

};


// this is like the creator function for the DOOCS backend
extern "C" {
  IFACE* creator();
}
