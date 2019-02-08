# segregatedLinkingExample
Short example how to load plugins via dlmopen 

Three libraries and one executable are created:

main is directly linking against libA

libC is a plugin loaded by main; libC is linked against libB

libB and libA are binary incompatible, as they both implement the same symbols (struct IFACE and struct IMPL derived from IFACE) but in an incompatible way.

With dlopen, the code fails, since libC is run against libA instead of libB, since the symbols are already loaded. Only with dlmopen it will properly load libB for use with libC, without interference with libA.
