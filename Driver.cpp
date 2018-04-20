//DRIVER.CPP //MAIN

/**
Isabella Gebhart and Clare DuVal
CPSC 002 Spring 2018
igehbar, ckduval
**/

#include "Image.h"
#include "Pixel.h"
#include "Header.h"
#include "BinaryFilter.h"
#include "BlurFilter.h"
#include "Filter.h"
#include "GrayscaleFilter.h"
#include "HFlipFilter.h"
#include "Kernel.h"
#include "PixelFilter.h"
#include "SepiaFilter.h"
#include "SharpenFilter.h"
#include "VFlipFilter.h"

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    if (argc != 3) {
      std::cerr << "USAGE: ./out <in.ppm> <out.ppm>";
      return 1;
    }

    int i = 0;
    //Welcome Message
    cout << "~******************************************~" << endl;
    cout << " Welcome to Izzy and Clare's Filter Machine" << endl;
    cout << "~******************************************~" << endl;

    while (i == 0) {
      cout << "Please choose up to 6 filters to apply to your" << endl;
      cout << "imported image. Note: The filters will be" << endl;
      cout << "in the order you put them. When you've finished" << endl;
      cout << "your list, enter -1." << endl;

      cout << "1. Sharpen" << endl;
      cout << "2. Blur" << endl;
      cout << "3. Horizontal Flip" << endl;
      cout << "4. Vertical Flip" << endl;
      cout << "5. Binary Filter" << endl;
      cout << "6. Black and White" << endl;
    }

    //Filter Vector

    return 0;
}
