/**
Isabella Gebhart and Clare DuVal
CPSC 002 Spring 2018
igehbar, ckduval
**/

#include "GrayscaleFilter.h"
#include "Pixel.h"

GrayscaleFilter::GrayscaleFilter() :
  PixelFilter("") {}

GrayscaleFilter::GrayscaleFilter(string name) : PixelFilter(name){}

GrayscaleFilter::GrayscaleFilter(const GrayscaleFilter& f) :
  PixelFilter(f.name)  {}
GrayscaleFilter::~GrayscaleFilter() {}


 Pixel GrayscaleFilter::apply_transform(const Pixel& pix) const{
  uint8_t lum = pix.luminance();
  Pixel pixelnew(lum,lum,lum);

  return pixelnew;
}
