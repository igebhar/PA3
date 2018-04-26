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
  protected:
    Pixel pixel1;
    Pixel pixel2;

        public:
          BinaryFilter();
          BinaryFilter(string);
	  BinaryFilter(Pixel, Pixel);
          BinaryFilter(const BinaryFilter&);
          ~BinaryFilter();
              // Finally implement!
          virtual Pixel apply_transform(const Pixel&) const;

};
#endif

