#include "VFlipFilter.h"
#include "Header.h"

VFlipFilter::VFlipFilter() :
  SimpleFilter("") {}

VFlipFilter::VFlipFilter(string name) : SimpleFilter(name){}

VFlipFilter::VFlipFilter(const VFlipFilter& f) :
  SimpleFilter(f.name)  {}


void VFlipFilter::apply(Image& img) const{
  int height = img.header().height();
  int width = img.header().width();
  int tempheight = height;
 int tempwidth = width;
  Image copy(img);
  for (int i = 0; i < width; i++) {
  for (int j = 0; j < height; j++) {
      img(i,j) = copy(tempwidth,tempheight--);
    }
  tempheight = height;
  tempwidth--;
}
}
