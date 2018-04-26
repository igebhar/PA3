/**
Isabella Gebhart and Clare DuVal
CPSC 002 Spring 2018
igehbar, ckduval
**/

#ifndef HFLIPFILTER_H
#define HFLIPFILTER_H

#include <string>
#include <algorithm>
#include "Image.h"
#include "SimpleFilter.h"

using namespace std;


class HFlipFilter : public SimpleFilter {

        public:
          HFlipFilter();
          HFlipFilter(string);
          HFlipFilter(const HFlipFilter&);
              //will help pass the Hflip filter to the image
              void apply(Image&) const;

            };
#endif
