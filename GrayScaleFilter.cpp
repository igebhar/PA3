/**
Isabella Gebhart and Clare DuVal
CPSC 002 Spring 2018
igehbar, ckduval
**/

#include "GrayscaleFilter.h"
#include "Pixel.h"

//default constructors
GrayscaleFilter::GrayscaleFilter() :
  PixelFilter("") {}

GrayscaleFilter::GrayscaleFilter(string name) : PixelFilter(name){}

GrayscaleFilter::GrayscaleFilter(const GrayscaleFilter& f) :
  PixelFilter(f.name) {}

// Destructor
GrayscaleFilter::~GrayscaleFilter() {}

//This uses the the 1st suggested algorithm 
// calls luminance uing the Pixel passed 
// the value returned from the luminance will be the new Red, Green
// and Blue channels
 Pixel GrayscaleFilter::apply_transform(const Pixel& pix) const{
  uint8_t lum = pix.luminance();
  Pixel pixelnew(lum,lum,lum);

  return pixelnew;
}
