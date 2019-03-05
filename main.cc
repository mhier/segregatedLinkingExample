#include <dlfcn.h>
#include <assert.h>

#include "myinterface.h"


#ifdef WITH_CRASH
#include <libxml++/libxml++.h>

struct bar : xmlpp::Node {
  bar();
  ~bar() override;

};

bar::bar() : xmlpp::Node(nullptr) {
  std::cout << "HIER bar()" << std::endl;
}

bar::~bar() {
  std::cout << "HIER bar()" << std::endl;
}
#endif


int main() {

    std::cout << "HIER main() START" << std::endl;
    
    auto handle = dlmopen(LM_ID_NEWLM, "libC.so", RTLD_LAZY | RTLD_LOCAL);
//    auto handle = dlopen("libC.so", RTLD_LAZY | RTLD_LOCAL);  // this leads to crashes, as it does not separate the plugin

// commented, not neede to show the segfault issue
/*
    auto pA = creator();
    pA->fun();
    
    IFACE* (*fn)(void) = reinterpret_cast<IFACE* (*)(void)>(dlsym(handle, "creator"));
    assert(fn != nullptr);
    auto pC = fn();
    pC->fun();
*/

    std::cout << "HIER main() END" << std::endl;
    return 0;
}
