#include <emscripten/bind.h>

struct Child
{
  Child(){};
};

struct Parent
{
  Parent(){};
  Child child;
};

using namespace emscripten;

EMSCRIPTEN_BINDINGS(mod)
{
  class_<Parent>("Parent")
    .constructor<>()
    .property("child", &Parent::child)
  ;
  
  class_<Child>("Child")
    .constructor<>()
  ;
}
