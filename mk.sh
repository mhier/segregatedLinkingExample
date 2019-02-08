#!/bin/bash -e

# libC uses libB
# libB conflicts libA
# main uses libA and loads libC which depends on libB, thus pulls in a conflict

g++ -g -O0 -std=c++17 -fPIC -shared libA.cc -o libA.so

g++ -g -O0 -std=c++17 -fPIC -shared libB.cc -o libB.so
g++ -g -O0 -std=c++17 -fPIC -shared libC.cc -o libC.so -L. -lB

g++ -g -O0 -std=c++17 main.cc -o main -L. -lA -ldl -Wl,-rpath=.


