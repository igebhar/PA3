/**
Isabella Gebhart and Clare DuVal
CPSC 002 Spring 2018
igehbar, ckduval
**/

#include <iostream>
#include <string>
#include "Pixel.h"
#include "Header.h"
#include "Image.h"
#include "Filter.h"
#include "SharpenFilter.h"
#include "BlurFilter.h"
#include "HFlipFilter.h"
#include "VFlipFilter.h"



int main(int argc, char const *argv[]) {
    if (argc != 3) {
      std::cerr << "USAGE: ./out <in.ppm> <out.ppm>";
      return 1;
    }

    // Open files
    std::ifstream in(argv[1]);
    std::ofstream out(argv[2]);


    if (!(in && out)) {
      std::cerr << "Could not open input/output\n";
      return 1;
    }

    //Creates 2 images with the input
    Image input(in); //To be altered by K3
    // this creates a copy of the puppy
    VFlipFilter input2;
    //Sharpens both images with corresponding matrix (K3/K5)
    input2.apply(input);

    //Writes a new image according to the returned img from sharpen
    input.write_to(out);

    //Closes the files
    in.close();
    out.close();

    return 0;
}
