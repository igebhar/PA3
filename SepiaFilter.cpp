#include "SepiaFilter.h"
#include "Pixel.h"

SepiaFilter::SepiaFilter() :
  PixelFilter("") {}

SepiaFilter::SepiaFilter(string name) : PixelFilter(name){}

SepiaFilter::SepiaFilter(const SepiaFilter& f) :
  PixelFilter(f.name)  {}
SepiaFilter::~SepiaFilter() {}


 Pixel SepiaFilter::apply_transform(const Pixel& pix) const{
   double Gvalue, Rvalue, Bvalue;

   Gvalue = pix.g()/ 255.0;
   Bvalue=  pix.b()/ 255.0;
   Rvalue =  pix.r()/255.0;

  double LinearR= Pixel::gamma_expansion(Rvalue);
  double LinearG=Pixel::gamma_expansion(Gvalue);
  double LinearB=Pixel::gamma_expansion(Bvalue);

  double outRed = (LinearR * .393)+(LinearG* .769)+ (LinearB * .189);
  double outGreen =  (LinearR * .349)+(LinearG* .686)+ (LinearB * .168);
  double outBlue =  (LinearR * .272)+(LinearG* .534)+ (LinearB * .131);

   double finalR, finalG, finalB;

  if(outRed >  1.0){
    finalR = Pixel::inverse_gamma(1.0);
  }
    else{
      finalR = Pixel::inverse_gamma(outRed);
    }



  if(outGreen >  1.0){
    finalG = Pixel::inverse_gamma(1.0);
  }
    else{
      finalG = Pixel::inverse_gamma(outGreen);
    }



  if(outBlue >  1.0){
    finalB = Pixel::inverse_gamma(1.0);
  }
    else{
      finalB = Pixel::inverse_gamma(outBlue);
    }


Pixel pixelnew(finalR,finalG, finalB);
  return pixelnew;
}
