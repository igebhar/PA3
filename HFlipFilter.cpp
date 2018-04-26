/**
Isabella Gebhart and Clare DuVal
CPSC 002 Spring 2018
igehbar, ckduval
**/

#include "HFlipFilter.h"
#include "Header.h"

//Default constructors
HFlipFilter::HFlipFilter() :
  SimpleFilter("") {}

HFlipFilter::HFlipFilter(string name) : SimpleFilter(name){}

HFlipFilter::HFlipFilter(const HFlipFilter& f) :
  SimpleFilter(f.name)  {}

// this goes through the columns and flips them horizontally
//takes the width and substracts 1 and then subtracts again
//this will give the proper value for the width as seen in the
// example matrix
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
