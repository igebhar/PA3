/**
Isabella Gebhart and Clare DuVal
CPSC 002 Spring 2018
igehbar, ckduval
**/

#include "Filter.h"
//Default constructors
Filter::Filter() :
  name("") {}

Filter::Filter(string name) :
  name(name) {}

Filter::Filter(const Filter& f) :
  name(f.name)  {}
//Destructos
Filter::~Filter() {}

// usies clamp function to help apply filter in the future
int Filter::clamp (int lo, int hi, int x) {
  return std::max(lo, std::min(x, hi));
}

double Filter::clamp (double lo, double hi, double x) {
  return std::max(lo, std::min(x, hi));
}
