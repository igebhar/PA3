/**
Isabella Gebhart and Clare DuVal
CPSC 002 Spring 2018
igehbar, ckduval
**/

#include "Filter.h"

Filter::Filter() :
  name("") {}

Filter::Filter(string name) :
  name(name) {}

Filter::Filter(const Filter& f) :
  name(f.name)  {}

Filter::~Filter() {}

int Filter::clamp (int lo, int hi, int x) {
  return std::max(lo, std::min(x, hi));
}

double Filter::clamp (double lo, double hi, double x) {
  return std::max(lo, std::min(x, hi));
}
