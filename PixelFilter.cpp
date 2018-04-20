/**
Isabella Gebhart and Clare DuVal
CPSC 002 Spring 2018
igehbar, ckduval
**/

#include "PixelFilter.h"

PixelFilter::PixelFilter() :
  Filter() {}

PixelFilter::PixelFilter(string name) :
  Filter(name) {}

PixelFilter::PixelFilter(const PixelFilter& f) :
  Filter(f.name)  {}

PixelFilter::~PixelFilter() {}

int PixelFilter::clamp (int lo, int hi, int x) {
  return std::max(lo, std::min(x, hi));
}

double PixelFilter::clamp (double lo, double hi, double x) {
  return std::max(lo, std::min(x, hi));
}

void PixelFilter::apply(Image& img) const {
  int img_rows = img.header().height();
  int img_cols = img.header().width();

  // Make reference image
  Image copy(img);

  // Apply kernel to each pixel
  // Omit outer edges. Simplest solution
  for (int y = 0; y < img_rows; y++) {
    for (int x = 0; x < img_cols; x++) {
      Pixel& pix = img(x,y);
      img(x,y) = this->apply_transform(pix);
    }
  }
}
