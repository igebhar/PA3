/**
Isabella Gebhart and Clare DuVal
CPSC 002 Spring 2018
igehbar, ckduval
**/

#include "SharpenFilter.h"

SharpenFilter::SharpenFilter() :
  KernelFilter("") {}

SharpenFilter::SharpenFilter(string name) : KernelFilter(name){}

SharpenFilter::SharpenFilter(const SharpenFilter& f) :
  KernelFilter(f.name)  {}


const Matrix SharpenFilter::K3 =
{{0,-1,0},
 {-1,5,-1},
 {0,-1,0}};

void SharpenFilter::apply(Image& img) const{
  KernelFilter::apply(img, K3);
}
