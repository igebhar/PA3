/**
Isabella Gebhart and Clare DuVal
CPSC 002 Spring 2018
igehbar, ckduval
**/

#ifndef BLURFILTER_H
#define BLURFILTER_H

#include <string>
#include <algorithm>
#include "Image.h"
#include "KernelFilter.h"

using namespace std;


class BlurFilter : public KernelFilter {
    protected:
        //new blur matrix that will change the clarity
        // of the image
          static const  Matrix Blur;

        public:
          BlurFilter();
          BlurFilter(string);
          BlurFilter(const BlurFilter&);
              // Used to apply filters to the image
              virtual void apply(Image&) const;

            };
#endif
