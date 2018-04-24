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
          static const Pixel WHITE(255, 255, 255);
          static const Pixel BLACK(0, 0, 0);

        public:
          BinaryFilter();
          BinaryFilter(string);
          BinaryFilter(const BinaryFilter&);
          ~BinaryFilter();
              // Finally implement!
          virtual Pixel apply(Pixel&) const;

};
#endif
