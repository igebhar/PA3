/**
Isabella Gebhart and Clare DuVal
CPSC 002 Spring 2018
igehbar, ckduval
**/

#include "HFlipFilter.h"
#include "Header.h"

HFlipFilter::HFlipFilter() :
  SimpleFilter("") {}

HFlipFilter::HFlipFilter(string name) : SimpleFilter(name){}

HFlipFilter::HFlipFilter(const HFlipFilter& f) :
  SimpleFilter(f.name)  {}


void HFlipFilter::apply(Image& img) const{
  int height = img.header().height();
  int width = img.header().width();
  Image copy(img);
    for (int i = width-1; i >= 0; i--) {
      for (int j = 0; j < height; j++) {
      img(width-1- i,j) = copy(i,j);
          }

    }
}
