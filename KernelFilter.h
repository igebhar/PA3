#ifndef KERNELFILTER_H
#define KERNELFILTER_H

#include <string>
#include "Filter.h"
#include <algorithm>
#include "Image.h"

using namespace std;
using Matrix = vector<vector<double>>;

class KernelFilter : public Filter {
  protected:
    // Data - Shows that abstract classes can still contain data
  //  string name;

    // Derived classes need these visible
    KernelFilter();
    KernelFilter(string name);
    KernelFilter(const KernelFilter&);

    virtual void apply (Image&, const Matrix&) const;
    virtual Pixel apply_kernel(Image&, int x, int y, const Matrix&) const;

  public:
    // Pure virtual destructor - Still needs definition!
    virtual ~KernelFilter () = 0;

    // Static helpers - should be a template
    static int clamp (int lo, int hi, int x);
    static double clamp (double lo, double hi, double x);

    // Public Interface - every derived class must implement
    //                  - or be abstract itself
    virtual void apply (Image&) const = 0;
};

#endif
