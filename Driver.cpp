/*
Isabella Gebhart and Clare DuVal
CPSC 002 Spring 2018
igehbar, ckduval
**/

//File Includes
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

//Library Includes
#include <iostream>
#include <string>
#include <vector>

//Namespace
using namespace std;

//MAIN
int main(int argc, char const *argv[]) {
    //Error if there's too many/few command line arguments
    if (argc != 3) {
      std::cerr << "USAGE: ./out <in.ppm> <out.ppm>";
      return 1;
    }

    //Open In/Out Files
    std::ifstream in(argv[1]);
    std::ofstream out(argv[2]);

    //BASIC FILE NAMES
    //Sharpen 100/100
    std::string one = "sharpen_100.ppm";
    std::ofstream sharpen(one);

    //Binary 100/100
    std::string two = "binary_100.ppm";
    std::ofstream binary(two);

    //Grayscale 100/100
    std::string three = "grayscale_100.ppm";
    std::ofstream grayscale(three);

    //Sepia 100/100
    std::string four = "sepia_100.ppm";
    std::ofstream sepia(four);

    //Blur 100/100
    std::string five = "blur_100.ppm";
    std::ofstream blur(five);

    //Horizontal 100/100
    std::string six = "horizontal_100.ppm";
    std::ofstream horizontal(six);

    //Vertical 100/100
    std::string seven = "vertical_100.ppm";
    std::ofstream vertical(seven);

    //COMBINATION FILES
    //Sharpen, Binary, Horizontal
    std::string eight = "shar_bin_hf_100.ppm";
    std::ofstream shar_bin_hf(eight);

    //Sharpen, Sepia, Vertical
    std::string nine = "shar_sep_vf_100.ppm";
    std::ofstream shar_sep_vf(nine);

    //Sharpen, Grayscale, Horizontal
    std::string ten = "shar_gs_hf_100.ppm";
    std::ofstream shar_gs_hf(ten);

    //Blur, Grayscale, Vertical
    std::string eleven = "blur_gs_vf_100.ppm";
    std::ofstream blur_gs_vf(eleven);

    //Blur, Binary, Horizontal
    std::string twelve = "blur_bin_hf_100.ppm";
    std::ofstream blur_bin_hf(twelve);

    //Blur, Sepia, Vertical
    std::string thirteen = "blur_sep_vf_100.ppm";
    std::ofstream blur_sep_vf(thirteen);

    //Grayscale, Vertical, Horizontal
    std::string fourteen = "stud_creation_100.ppm";
    std::ofstream stud_creation(fourteen);

    //Error Messages for opening files
    if (!(in && out)) {
      std::cerr << "Could not open input/output\n";
      return 1;
    }

    //Image of puppy.ppm
    Image puppy(in);

    //Image altered by sharpen class
    Image sharpen100(puppy);
    SharpenFilter sharp;
    sharp.apply(sharpen100);
    //Write to a ppm Image
    sharpen100.write_to(sharpen);

    //Image altered by binary class
    Image binary100(puppy);
    BinaryFilter bin;
    bin.apply_transform(binary100);
    //Write to a ppm image
    binary100.write_to(binary);

    //Image altered by grayscale class
    Image grayscale100(puppy);
    GrayscaleFilter gs;
    gs.apply_transform(grayscale100);
    //Write to a ppm image
    grayscale100.write_to(grayscale);

    //Image altered by sepia class
    Image sepia100(puppy);
    SepiaFilter sep;
    sep.apply(sepia100);
    //Write to a ppm image
    sepia100.write_to(sepia);

    //Image altered by blur class
    Image blur100(puppy);
    BlurFilter blurone;
    blurone.apply(blur100);
    //Write to a ppm image
    blur100.write_to(blur);

    //Image altered by horizontal flip class
    Image horizontal100(puppy);
    HFlipFilter hFlip;
    hFlip.apply(horizontal100);
    //Write to a ppm image
    horizontal100.write_to(horizontal);

    //Image altered by vertical class
    Image vertical100(puppy);
    VFlipFilter vFlip;
    vFlip.apply(vertical100);
    //Write to a ppm image
    vertical100.write_to(vertical);

    //Combination files
    //Image altered by sharpen,
    //blur, and horizontal classes
    Image shar_bin_hf_100(puppy);
    SharpenFilter sharpone;
    sharpone.apply(shar_bin_hf_100);
    BinaryFilter bin1;
    bin1.apply_transform(shar_bin_hf_100);
    HFlipFilter hFlip1;
    hFlip1.apply(shar_bin_hf_100);
    //Write to a ppm image
    shar_bin_hf_100.write_to(shar_bin_hf);

    //Image altered by sharpen,
    //sepia, and vertical classes
    Image shar_sep_vf_100(puppy);
    SharpenFilter sharp1;
    sharp1.apply(shar_sep_vf_100);
    SepiaFilter sep1;
    sep1.apply(shar_sep_vf_100);
    VFlipFilter vFlip1;
    vFlip1.apply(shar_sep_vf_100);
    //Write to a ppm image
    shar_sep_vf_100.write_to(shar_sep_vf);

    //Image altered by sharpen, 
    //grayscale, and horizontal classes
    Image shar_gs_hf_100(puppy);
    SharpenFilter sharp2;
    sharp2.apply(shar_gs_hf_100);
    GrayscaleFilter gs2;
    gs2.apply_transform(shar_gs_hf_100);
    HFlipFilter hFlip2;
    hFlip2.apply(shar_gs_hf_100);
    //Write to a ppm image
    shar_gs_hf_100.write_to(shar_gs_hf);

    //Image altered by blur, 
    //grayscale, and vertical classes
    Image blur_gs_vf_100(puppy);
    BlurFilter blur3;
    blur3.apply(blur_gs_vf_100);
    GrayscaleFilter gs3;
    gs3.apply_transform(blur_gs_vf_100);
    VFlipFilter vFlip3;
    vFlip3.apply(blur_gs_vf_100);
    //Write to a ppm image
    blur_gs_vf_100.write_to(blur_gs_vf);

    //Image altered by blur,
    //binary, and horizontal classes
    Image blur_bin_hf_100(puppy);
    BlurFilter blur4;
    blur4.apply(blur_bin_hf_100);
    BinaryFilter bin4;
    bin4.apply_transform(blur_bin_hf_100);
    HFlipFilter hFlip4;
    hFlip4.apply(blur_bin_hf_100);
    //Write to a ppm image
    blur_bin_hf_100.write_to(blur_bin_hf);

    //Image altered by blur, sepia,
    //and vertical classes
    Image blur_sep_vf_100(puppy);
    BlurFilter blur5;
    blur5.apply(blur_sep_vf_100);
    SepiaFilter sep5;
    sep5.apply(blur_sep_vf_100);
    VFlipFilter vFlip5;
    vFlip5.apply(blur_sep_vf_100);
    //Write to a ppm image
    blur_sep_vf_100.write_to(blur_sep_vf);

    //Image altered by grayscale,
    //vertical, and horizontal classes
    Image stud_creation_100(puppy);
    GrayscaleFilter gs6;
    gs6.apply_transform(stud_creation_100);
    VFlipFilter vFlip6;
    vFlip6.apply(stud_creation_100);
    HFlipFilter hFlip6;
    hFlip6.apply(stud_creation_100);
    //Write to a ppm image
    stud_creation_100.write_to(stud_creation);

    //Close all files
    in.close();
    out.close();
    sharpen.close();
    binary.close();
    grayscale.close();
    sepia.close();
    blur.close();
    horizontal.close();
    vertical.close();
    shar_bin_hf.close();
    shar_sep_vf.close();
    shar_gs_hf.close();
    blur_gs_vf.close();
    blur_bin_hf.close();
    blur_sep_vf.close();
    stud_creation.close();

    return 0;
}

