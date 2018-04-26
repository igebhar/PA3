/**
Isabella Gebhart and Clare DuVal
CPSC 002 Spring 2018
igehbar, ckduval
**/

#include "BlurFilter.h"

//Default constructors
BlurFilter::BlurFilter() :
  KernelFilter("") {}

BlurFilter::BlurFilter(string name) : KernelFilter(name){}

BlurFilter::BlurFilter(const BlurFilter& f) :
  KernelFilter(f.name)  {}

//this matrix will help blur the image
const Matrix BlurFilter::Blur =
{{0.0625,0.125,0.0625},
 {0.125,0.25,0.125},
 {0.0625,0.125,0.0625}};

//Applies the apply function to the image using the new
// Blur matrix
void BlurFilter::apply(Image& img) const{
  KernelFilter::apply(img, Blur);
}
