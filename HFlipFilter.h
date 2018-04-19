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
              // Finally implement!
              void apply(Image&) const;

            };
#endif
