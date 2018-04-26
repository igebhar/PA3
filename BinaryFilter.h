/**
Isabella Gebhart and Clare DuVal
CPSC 002 Spring 2018
igehbar, ckduval
**/

#ifndef BINARYFILTER_H
#define BinaryFilter_H

#include <string>
#include <algorithm>
#include "Image.h"
#include "PixelFilter.h"

using namespace std;

class BinaryFilter : public PixelFilter {
  // Two pixel variables that will be used to help set colors
  protected:
    Pixel pixel1;
    Pixel pixel2;

        public:
          //Normal constructors
          BinaryFilter();
          BinaryFilter(string);
          BinaryFilter(const BinaryFilter&);
          ~BinaryFilter();
  
          // Will be used later in the Binary cpp to make 
          // the filter
          virtual Pixel apply_transform(Pixel&) const;

};
#endif
