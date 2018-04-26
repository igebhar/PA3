#include "SepiaFilter.h"
#include "Pixel.h"

//these are the standard constructors
SepiaFilter::SepiaFilter() :
  PixelFilter("") {}

SepiaFilter::SepiaFilter(string name) : PixelFilter(name){}

SepiaFilter::SepiaFilter(const SepiaFilter& f) :
  PixelFilter(f.name)  {}
SepiaFilter::~SepiaFilter() {}

// this is the extra credit sepia filter version 

 Pixel SepiaFilter::apply_transform(const Pixel& pix) const{
   double Gvalue, Rvalue, Bvalue;
//maps the pixel by dividing the channel (RGB by 255.0)
   Gvalue = pix.g()/ 255.0;
   Bvalue=  pix.b()/ 255.0;
   Rvalue =  pix.r()/255.0;
   
//uses gamma expansion to map the pixel to linear gamma_expansion
  double LinearR= Pixel::gamma_expansion(Rvalue);
  double LinearG=Pixel::gamma_expansion(Gvalue);
  double LinearB=Pixel::gamma_expansion(Bvalue);
   
//Calculates the proper sepia values
  double outRed = (LinearR * .393)+(LinearG* .769)+ (LinearB * .189);
  double outGreen =  (LinearR * .349)+(LinearG* .686)+ (LinearB * .168);
  double outBlue =  (LinearR * .272)+(LinearG* .534)+ (LinearB * .131);

   double finalR, finalG, finalB;
   
//converts to proper color space rather than linear space
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

//this goes back to actual color values
finalR = finalR * 255.0;
finalG = finalG * 255.0;
finalB = finalB * 255.0;
   
//puts the values into the correct pixel
Pixel pixelnew((uint8_t)(finalR),(uint8_t)(finalG),(uint8_t)(finalB));
  return pixelnew;
}
