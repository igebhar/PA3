/**
Isabella Gebhart and Clare DuVal
CPSC 002 Spring 2018
igehbar, ckduval
**/

#include "SimpleFilter.h"

Constructors
SimpleFilter::SimpleFilter() :
  Filter() {}

SimpleFilter::SimpleFilter(string name) :
  Filter(name) {}

SimpleFilter::SimpleFilter(const SimpleFilter& f) :
  Filter(f.name)  {}

//Deconstructor
SimpleFilter::~SimpleFilter() {}

//Checks pixel r g b values to be between 0 and 255 with ints
int SimpleFilter::clamp (int lo, int hi, int x) {
  return std::max(lo, std::min(x, hi));
}

//Checks pixel r g b values to be between 0 and 255 with doubles
double SimpleFilter::clamp (double lo, double hi, double x) {
  return std::max(lo, std::min(x, hi));
}
