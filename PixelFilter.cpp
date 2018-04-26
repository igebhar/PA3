/**
Isabella Gebhart and Clare DuVal
CPSC 002 Spring 2018
igehbar, ckduval
**/

#include "PixelFilter.h"

//Constructors
PixelFilter::PixelFilter() :
  Filter() {}

PixelFilter::PixelFilter(string name) :
  Filter(name) {}

PixelFilter::PixelFilter(const PixelFilter& f) :
  Filter(f.name)  {}

//Deconstructor
PixelFilter::~PixelFilter() {}

//Function makes sure the pixel rgb values are
//inbetween 0 and 255 (int)
int PixelFilter::clamp (int lo, int hi, int x) {
  return std::max(lo, std::min(x, hi));
}

//Function makes sure the pixel rgb values are
//inbetween 0 and 255 (double)
double PixelFilter::clamp (double lo, double hi, double x) {
  return std::max(lo, std::min(x, hi));
}

//Changes image to vector then transforms the vector
void PixelFilter::apply(Image& img) const {
  //Saves height and width to ints
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
