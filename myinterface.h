#include <iostream>

struct IFACE {

    virtual void fun() = 0;
    void nonVirtual();

};

extern "C" {
  IFACE* creator();
}
