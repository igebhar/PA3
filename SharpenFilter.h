#ifndef SHARPENFILTER_H
#define SHARPENFILTER_H

#include <string>
#include <algorithm>
#include "../image/Image.h"
#include "KernelFilter.h"

using namespace std;


class SharpenFilter : public KernelFilter {
    protected:
          static const  Matrix K3;

        public:
          SharpenFilter();
          SharpenFilter(string);
          SharpenFilter(const SharpenFilter&);
              // Finally implement!
              virtual void apply(Image&) const;

            };
#endif
