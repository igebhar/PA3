/**
Isabella Gebhart and Clare DuVal
CPSC 002 Spring 2018
igehbar, ckduval
**/

#include "SimpleFilter.h"

SimpleFilter::SimpleFilter() :
  Filter() {}

SimpleFilter::SimpleFilter(string name) :
  Filter(name) {}

SimpleFilter::SimpleFilter(const SimpleFilter& f) :
  Filter(f.name)  {}

SimpleFilter::~SimpleFilter() {}

int SimpleFilter::clamp (int lo, int hi, int x) {
  return std::max(lo, std::min(x, hi));
}

double SimpleFilter::clamp (double lo, double hi, double x) {
  return std::max(lo, std::min(x, hi));
}

//void SimpleFilter::apply(Image& img) const {
  //int k_center = k.size()/2;
//  int img_rows = img.header().height();
//  int img_cols = img.header().width();

  // Make reference image
//  Image copy(img);

  // Apply kernel to each pixel
  // Omit outer edges. Simplest solution
  //for (int y = 0; y < img_rows; y++) {
//  for (int x = 0; x < img_cols; x++) {
  //    img(x,y); //= this->apply_kernel(copy, x, y, k);
//    }
//}
//}
