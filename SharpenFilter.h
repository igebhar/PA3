/**
Isabella Gebhart and Clare DuVal
CPSC 002 Spring 2018
igehbar, ckduval
**/

#ifndef SHARPENFILTER_H
#define SHARPENFILTER_H

#include <string>
#include <algorithm>
#include "Image.h"
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
