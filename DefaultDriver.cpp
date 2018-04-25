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

    //Output File String Names
    std::string one = "sharpen_100.ppm";
    std::ofstream sharpen(one);

    std::string two = "binary_100.ppm";
    std::ofstream binary(two);

    std::string three = "grayscale_100.ppm";
    std::ofstream grayscale(three);

    std::string four = "sepia_100.ppm";
    std::ofstream sepia(four);

    std::string five = "blur_100.ppm";
    std::ofstream blur(five);

    std::string six = "horizontal_100.ppm";
    std::ofstream horizontal(six);

    std::string seven = "vertical_100.ppm";
    std::ofstream vertical(seven);

    //Combination File Names
    std::string eight = "shar_bin_hf_100.ppm";
    std::ofstream shar_bin_hf(eight);

    std::string nine = "shar_sep_vf_100.ppm";
    std::ofstream shar_sep_vf(nine);

    std::string ten = "shar_gs_hf_100.ppm";
    std::ofstream shar_gs_hf(ten);

    std::string eleven = "blur_gs_hf_100.ppm";
    std::ofstream blur_gs_hf(eleven);

    std::string twelve = "blur_bin_hf_100.ppm";
    std::ofstream blur_bin_hf(twelve);

    std::string thirteen = "blur_sep_vf_100.ppm";
    std::ofstream blur_sep_vf(thirteen);

    std::string fourteen = "stud_creation_100.ppm";
    std::ofstream stud_creation(fourteen);

    //Error Messages for opening files
    if (!(in && out)) {
      std::cerr << "Could not open input/output\n";
      return 1;
    }

    Image puppy(in);

    Image sharpen100(puppy);
    SharpenFilter sharp;
    sharp.apply(sharpen100);
    sharpen100.write_to(sharpen);

    Image binary100(puppy);
    BinaryFilter bin;
    bin.apply_transform(binary100);
    binary100.write_to(binary);

    Image grayscale100(puppy);
    GrayscaleFilter gs;
    gs.apply_transform(grayscale100);
    grayscale100.write_to(grayscale);

    Image sepia100(puppy);
    SepiaFilter sep;
    sep.apply(sepia100);
    sepia100.write_to(sepia);

    Image blur100(puppy);
    BlurFilter blurone;
    blurone.apply(blur100);
    blur100.write_to(blur);

    Image horizontal100(puppy);
    HFlipFilter hFlip;
    hFlip.apply(horizontal100);
    horizontal100.write_to(horizontal);

    Image vertical100(puppy);
    VFlipFilter vFlip;
    vFlip.apply(vertical100);
    vertical100.write_to(vertical);

    //Combination files
    Image shar_bin_hf_100(puppy);
    SharpenFilter sharpone;
    sharpone.apply(shar_bin_hf_100);
    BinaryFilter bin1;
    bin1.apply_transform(shar_bin_hf_100);
    HFlipFilter hFlip1;
    hFlip1.apply(shar_bin_hf_100);
    shar_bin_hf_100.write_to(shar_bin_hf);

    Image shar_sep_vf_100(puppy);
    SharpenFilter sharp1;
    sharp1.apply(shar_sep_vf_100);
    SepiaFilter sep1;
    sep1.apply(shar_sep_vf_100);
    VFlipFilter vFlip1;
    vFlip1.apply(shar_sep_vf_100);
    shar_sep_vf_100.write_to(shar_sep_vf);

    Image shar_gs_hf_100(puppy);
    SharpenFilter sharp2;
    sharp2.apply(shar_gs_hf_100);
    GrayscaleFilter gs2;
    gs2.apply_transform(shar_gs_hf_100);
    HFlipFilter hFlip2;
    hFlip2.apply(shar_gs_hf_100);
    shar_gs_hf_100.write_to(shar_gs_hf);

    Image blur_gs_vf_100(puppy);
    BlurFilter blur3;
    blur3.apply(blur_gs_vf_100);
    GrayscaleFilter gs3;
    gs3.apply_transform(blur_gs_vf_100);
    VFlipFilter vFlip3;
    vFlip3.apply(blur_gs_vf_100);
    blur_gs_vf_100.write_to(blur_gs_vf);

    Image blur_bin_hf_100(puppy);
    BlurFilter blur4;
    blur4.apply(blur_bin_hf_100);
    BinaryFilter bin4;
    bin4.apply_transform(blur_bin_hf_100);
    HFlipFilter hFlip4;
    hFlip4.apply(blur_bin_hf_100);
    blur_bin_hf_100.write_to(blur_bin_hf);

    Image blur_sep_vf_100(puppy);
    BlurFilter blur5;
    blur5.apply(blur_sep_vf_100);
    SepiaFilter sep5;
    sep5.apply(blur_sep_vf_100);
    VFlipFilter vFlip5;
    vFlip5.apply(blur_sep_vf_100);
    blur_sep_vf_100.write_to(blur_sep_vf);

    Image stud_creation_100(puppy);
    GrayscaleFilter gs6;
    gs6.apply_transform(stud_creation_100);
    VFlipFilter vFlip6;
    vFlip6.apply(stud_creation_100);
    HFlipFilter hFlip6;
    hFlip6.apply(stud_creation_100);
    stud_creation_100.write_to(stud_creation);

    //Close files
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

