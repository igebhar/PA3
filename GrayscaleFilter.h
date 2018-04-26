/**
Isabella Gebhart and Clare DuVal
CPSC 002 Spring 2018
igehbar, ckduval
**/

#ifndef GRAYSCALEFILTER_H
#define GRAYSCALEFILTER_H

#include <string>
#include <algorithm>
#include "Image.h"
#include "PixelFilter.h"

using namespace std;


class GrayscaleFilter : public PixelFilter {

        public:
        //Default 
          GrayscaleFilter();
          GrayscaleFilter(string);
          GrayscaleFilter(const GrayscaleFilter&);
           ~GrayscaleFilter();
              // apply transform to be used in the gratscale filter
              virtual Pixel apply_transform(const Pixel&) const;

            };
#endif
