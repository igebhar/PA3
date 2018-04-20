#ifndef GRAYSCALEFILTER_H
#define GRAYSCALEFILTER_H

#include <string>
#include <algorithm>
#include "Image.h"
#include "PixelFilter.h"

using namespace std;


class GrayscaleFilter : public PixelFilter {

        public:
          GrayscaleFilter();
          GrayscaleFilter(string);
          GrayscaleFilter(const GrayscaleFilter&);
           ~GrayscaleFilter();
              // Finally implement!
              virtual Pixel apply_transform(const Pixel&) const;

            };
#endif
