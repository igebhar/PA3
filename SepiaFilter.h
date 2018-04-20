#ifndef SEPIAFILTER_H
#define SEPIAFILTER_H

#include <string>
#include <algorithm>
#include "Image.h"
#include "PixelFilter.h"

using namespace std;


class SepiaFilter : public PixelFilter {

        public:
          SepiaFilter();
          SepiaFilter(string);
          SepiaFilter(const SepiaFilter&);
           ~SepiaFilter();
              // Finally implement!
              virtual Pixel apply_transform(const Pixel&) const;

            };
#endif
