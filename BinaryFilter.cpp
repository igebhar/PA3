/**
Isabella Gebhart and Clare DuVal
CPSC 002 Spring 2018
igehbar, ckduval
**/

#include "BinaryFilter.h";
#include "Pixel.h"

Pixel BinaryFilter::WHITE (255, 255, 255);
Pixel BinaryFilter::BLACK (0,0,0);

BinaryFilter::BinaryFilter() :
  PixelFilter("Binary"), primary(BinaryFilter::WHITE),
    secondary(BinaryFilter::BLACK) {}

//BinaryFilter::BinaryFilter(string name) : PixelFilter(name){}

BinaryFilter::BinaryFilter(const BinaryFilter& bf) :
  PixelFilter(bf.name), primary(bf.primary), secondary(bf.secondary)  {}
BinaryFilter::~BinaryFilter() {}


 Pixel BinaryFilter::apply(const Pixel& pix) const{
  uint8_t lum = pix.luminance();
  return gray > 128 ? this->primary : this->secondary;
}

//Print
