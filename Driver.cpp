/*
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
#include "KernelFilter.h"
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
    std::ofstream out(argv[2]);

    //Welcome Message
    std::cerr << "~******************************************~" << endl;
    std::cerr << " Welcome to Izzy and Clare's Filter Machine" << endl;
    std::cerr << "~******************************************~" << endl;

    std::cerr << "Please choose up to 6 filters to apply to your" << endl;
    std::cerr << "imported image. Note: The filters will be" << endl;
    std::cerr << "in the order you put them. When you've finished" << endl;
    std::cerr << "your list, enter -1." << endl;

    std::cerr << "1. Sharpen" << endl;
    std::cerr << "2. Blur" << endl;
    std::cerr << "3. Horizontal Flip" << endl;
    std::cerr << "4. Vertical Flip" << endl;
    std::cerr << "5. Binary Filter" << endl;
    std::cerr << "6. Black and White" << endl;

    //Filter Vector
    vector<Filter*> combo;
    int c = 0;
    int r, g, b;

    Image puppy(in);

    cin >> c;
    while ((c != (-1)) && (combo.size() <= 6)) {
      if (c == 1) {
	SharpenFilter* sharpen = new SharpenFilter();
        combo.push_back(sharpen);
      } else if (c == 2) {
	BlurFilter* blur = new BlurFilter();
	combo.push_back(blur);
      } else if (c == 3) {
	HFlipFilter* hFlip = new HFlipFilter();
	combo.push_back(hFlip);
      } else if (c ==4) {
	VFlipFilter* vFlip = new VFlipFilter();
	combo.push_back(vFlip);
      } else if (c == 5) {
	std::cerr << "What 3 rgb values would you like for color 1?\n";
	cin >> r >> g >> b;
	Pixel pix1 (r, g, b);
	std::cerr << "What 3 rbg values would you like for color2?\n";
	cin >> r >> g >> b;
	Pixel pix2 (r, g, b);
	BinaryFilter* binary (pix1, pix2) = new BinaryFilter;
	combo.push_back(binary);
      } else if (c == 6) {
	GrayscaleFilter* grayscale = new GrayscaleFilter;;
	combo.push_back(grayscale);
      } else if (c == 7) {
	SepiaFilter* sepia = new GrayscaleFilter;
	combo.push_back(sepia);
      } else {
	std::cerr << "Error, not an option between 1 and 7, try again.\n";
      }
      cin >> c;
    }

    int order = 0;

std::cerr << combo.size() << endl;

//******
    for (order = 0; order < (int)combo.size(); order++) {
	combo.at(order)->apply(puppy);
}
/*
	if (combo.at(order) == &sharpen) {
	  combo.at(order)->apply(puppy);
	} else if (combo.at(order) == &blur) {
	  combo.at(order)->apply(puppy);
	} else if (combo.at(order) == &hFlip) {
	  combo.at(order)->apply(puppy);
	} else if (combo.at(order) == &vFlip) {
	  combo.at(order)->apply(puppy);
	} else if (combo.at(order) == &binary) {
          combo.at(order)->apply(puppy);
        } else if (combo.at(order) == &grayscale) {
          combo.at(order)->apply(puppy);
        } else if (combo.at(order) == &sepia) {
          combo.at(order)->apply(puppy);
        } 
    }
    
    //For loop of applying filters
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

      }
      //Black and White
      else if (choice.at(c) == 6) {

      } 
      //Sepia
      else if (choice.at(c) == 7) {

      } else {
        std::cerr << "You entered a number other than:" << endl;
        std::cerr << "-1, 1, 2, 3, 4, 5, or 6. Please," << endl;
        std::cerr << "try again." << endl;
        return 1;
        }
    }
*/
    //Write output image .ppm
    puppy.write_to(out);
    combo.clear();

    //Close files
    in.close();
    out.close();

    return 0;
}
