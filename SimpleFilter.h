/**
Isabella Gebhart and Clare DuVal
CPSC 002 Spring 2018
igehbar, ckduval
**/

#ifndef SIMPLEFILTER_H
#define SIMPLEFILTER_H

#include <string>
#include "Filter.h"
#include <algorithm>
#include "Image.h"

using namespace std;
//Matrix defined with a vector of double vectors
using Matrix = vector<vector<double>>;

class SimpleFilter : public Filter {
  protected:
    // Data - Shows that abstract classes can still contain data
  //  string name;

    // Derived classes need these visible
    SimpleFilter();
    SimpleFilter(string name);
    SimpleFilter(const SimpleFilter&);


  public:
    // Pure virtual destructor - Still needs definition!
    virtual ~SimpleFilter () = 0;

    // Static helpers - should be a template
    static int clamp (int lo, int hi, int x);
    static double clamp (double lo, double hi, double x);

    // Public Interface - every derived class must implement
    //                  - or be abstract itself
    virtual void apply (Image&) const = 0;
};

#endif
