#include <dlfcn.h>
#include <assert.h>

#include "myinterface.h"


int main() {

    std::cout << "HIER main() START" << std::endl;
    
    auto handle = dlmopen(LM_ID_NEWLM, "libC.so", RTLD_LAZY | RTLD_LOCAL);
    
//    auto handle = dlopen("libC.so", RTLD_LAZY | RTLD_LOCAL);  // this leads to crashes, as it does not separate the plugin

    auto pA = creator();
    pA->fun();
    
    IFACE* (*fn)(void) = reinterpret_cast<IFACE* (*)(void)>(dlsym(handle, "creator"));
    assert(fn != nullptr);
    auto pC = fn();
    pC->fun();

    std::cout << "HIER main() END" << std::endl;

    return 0;
}
