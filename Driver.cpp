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
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    if (argc != 3) {
      std::cerr << "USAGE: ./out <in.ppm> <out.ppm>";
      return 1;
    }

    //Open filters
    std::ifstream in(argv[1]);
    std::ofstream out (argv[2]);

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
    vector<int> choice;
    int c = 0;

    while (c != (-1)) {
      cin >> c;
      choice.push_back(c);
    }

    Image puppy(in);

    //
    for (c = 0; choice.at(c) != -1; c++) {
      //Sharpen
      if (choice.at(c) == 1) {
        SharpenFilter sharp;
        sharp.apply(puppy);
      }
      //Blur
      else if (choice.at(c) == 2) {
          BlurFilter blur;
          blur.apply(puppy);
      }
      //Horizontal Flip
      else if (choice.at(c) == 3) {
          HFlipFilter hFlip;
          hFlip.apply(puppy);
      }
      //Vertical Flip
      else if (choice.at(c) == 4) {
          VFlipFilter vFlip;
          vFlip.apply(puppy);
      }
      //Binary
      else if (choice.at(c) == 5) {
          BinaryFilter binary;
          binary.apply(puppy);
      }
      //Black and White
      else if (choice.at(c) == 6) {
        GrayscaleFilter bw;
        bw.apply_transform(puppy);
      } else {
        cout << "You entered a number other than:" << endl;
        cout << "-1, 1, 2, 3, 4, 5, or 6. Please," << endl;
        cout << "try again." << endl;
        return 1;
      }
    }

    //Write output image .ppm
    puppy.write_to(out);

    //Close files
    in.close();
    out.close();

    return 0;
}
