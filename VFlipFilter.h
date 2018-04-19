#ifndef VFLIPFILTER_H
#define VFLIPFILTER_H

#include <string>
#include <algorithm>
#include "Image.h"
#include "SimpleFilter.h"

using namespace std;


class VFlipFilter : public SimpleFilter {

        public:
          VFlipFilter();
          VFlipFilter(string);
          VFlipFilter(const VFlipFilter&);
              // Finally implement!
              void apply(Image&) const;

            };
#endif
