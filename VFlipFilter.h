/**
Isabella Gebhart and Clare DuVal
CPSC 002 Spring 2018
igehbar, ckduval
**/

#ifndef VFLIPFILTER_H
#define VFLIPFILTER_H

#include <string>
#include <algorithm>
#include "Image.h"
#include "SimpleFilter.h"

using namespace std;


class VFlipFilter : public SimpleFilter {

        public:
        //Normal constructors
          VFlipFilter();
          VFlipFilter(string);
          VFlipFilter(const VFlipFilter&);
              // Will be used later in the Binary cpp to make 
              // the filter
              void apply(Image&) const;

            };
#endif
