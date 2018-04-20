#ifndef PIXELFILTER_H
#define PIXELFILTER_H

#include <string>
#include "Filter.h"
#include <algorithm>
#include "Image.h"

using namespace std;

class PixelFilter : public Filter {
  protected:
    // Data - Shows that abstract classes can still contain data
  //  string name;

    // Derived classes need these visible
    PixelFilter();
    PixelFilter(string name);
    PixelFilter(const PixelFilter&);


  public:

    virtual void apply (Image&s) const;
    virtual Pixel apply_transform(const Pixel&)const = 0;
    // Pure virtual destructor - Still needs definition!
    virtual ~PixelFilter () = 0;

    // Static helpers - should be a template
    static int clamp (int lo, int hi, int x);
    static double clamp (double lo, double hi, double x);

};

#endif
