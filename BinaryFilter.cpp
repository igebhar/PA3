/**
Isabella Gebhart and Clare DuVal
CPSC 002 Spring 2018
igehbar, ckduval
**/

#include "BinaryFilter.h"
#include "Pixel.h"

BinaryFilter::BinaryFilter() :
    PixelFilter(" "), pixel1 (255, 255, 255), pixel2 (0,0,0);

BinaryFilter::BinaryFilter(const BinaryFilter& bf) :
  PixelFilter(bf.name), pixel1(bf.primary), pixel2(bf.secondary)  {}
  
BinaryFilter::~BinaryFilter() {}


 Pixel BinaryFilter::apply_transform(const Pixel& pix) const{
  uint8_t lum = pix.luminance();
    if(lum >(pixel1.r() / 2)){
      return pixel1;
    }
    else {
      return pixel2; 
    }
}
