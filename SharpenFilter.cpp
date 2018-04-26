/**
Isabella Gebhart and Clare DuVal
CPSC 002 Spring 2018
igehbar, ckduval
**/

#include "SharpenFilter.h"

//Constructors
SharpenFilter::SharpenFilter() :
  KernelFilter("") {}

SharpenFilter::SharpenFilter(string name) : KernelFilter(name){}

SharpenFilter::SharpenFilter(const SharpenFilter& f) :
  KernelFilter(f.name)  {}

//Matrix with vector of vectors
const Matrix SharpenFilter::K3 =
{{0,-1,0},
 {-1,5,-1},
 {0,-1,0}};

//Apply function that applies the matrix to
//each pixel in the image
void SharpenFilter::apply(Image& img) const{
  KernelFilter::apply(img, K3);
}
