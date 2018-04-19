#ifndef BLURFILTER_H
#define BLURFILTER_H

#include <string>
#include <algorithm>
#include "Image.h"
#include "KernelFilter.h"

using namespace std;


class BlurFilter : public KernelFilter {
    protected:
          static const  Matrix Blur;

        public:
          BlurFilter();
          BlurFilter(string);
          BlurFilter(const BlurFilter&);
              // Finally implement!
              virtual void apply(Image&) const;

            };
#endif
