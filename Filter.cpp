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
//Destructor
Filter::~Filter() {}

//Checks rgb values are inbetween 0 and 255 (ints)
int Filter::clamp (int lo, int hi, int x) {
  return std::max(lo, std::min(x, hi));
}

//Checks rgb values are inbetween 0 and 255 (double)
double Filter::clamp (double lo, double hi, double x) {
  return std::max(lo, std::min(x, hi));
}
