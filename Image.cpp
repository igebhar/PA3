/**
Isabella Gebhart and Clare DuVal
CPSC 002 Spring 2018
igehbar, ckduval
**/

#include "Image.h"

Image::Image (ifstream& in) :
 HDR (Image::read_header(in)), PIX (Image::read_pixels(HDR, in)) {}
Image::Image (const Image& img) :
  HDR(img.header()), PIX(img.pixels()) {}
Image::~Image () {}

// accessors1
const Header& Image::header () const { return this->HDR; }
const vector<Pixel>& Image::pixels () const { return this->PIX; }

// Get one pixel
Pixel& Image::operator() (int x, int y) {
  int ndx = (this->HDR.width() * y) + x;
  return this->PIX[ndx];
}

// This function reads the header information from the images
/// it used the in file and returns information about the header
Header Image::read_header (ifstream& in) {
  string magic;
  int w, h, mc;

  in >> magic;
  Image::ignore_comments(in);
  in >> w;
  Image::ignore_comments(in);
  in >> h;
  Image::ignore_comments(in);
  in >> mc;
  in.ignore(256, '\n');
  return Header(magic, w, h, mc);
}

//This function ignores comments. Will be used to ignore
//comments and white space in the header function
void Image::ignore_comments (ifstream& in) {
  char c;
  in.get(c);

  while (isspace(c) || c == '#') {
    if (c == '#')
      in.ignore(256, '\n');
    in.get(c);
  }

  in.unget();
}


// Reads pixels using a pixel array. takes in header information
// and the input file returns a vector of pixels from the image
vector<Pixel> Image::read_pixels (const Header& hdr, ifstream& in) {
  int num_pixels = hdr.width() * hdr.height();
  vector<Pixel> pixels(num_pixels);

  if (hdr.magic() == "P3") {
    uint r,g,b;
    for (Pixel& p : pixels) {
      in >> r >> g >> b;
      p = Pixel(r, g, b);
    }
  } else {
    uint8_t r,g,b;
    for (Pixel& p : pixels) {
      r = in.get();
      g = in.get();
      b = in.get();
      p = Pixel(r, g, b);
    }
  }

  return pixels;
}

void Image::make_p3 () { this->HDR.magic() = "P3"; }
void Image::make_p6 () { this->HDR.magic() = "P6"; }

// Uses outfile to write a header this helps create files
void Image::write_header (ofstream& out) const {
  out << this->HDR.magic() << " "
      << this->HDR.width() << " "
      << this->HDR.height() << " "
      << this->HDR.max_color() << "\n";
}

//Assigns pixels to the outfile helping create the proper outfile
// uawa .at(i) as suggested in the write up to ensure bounds checking
void Image::write_to (ofstream& out) const {
  write_header(out);

  if (this->HDR.magic() == "P3") {
    for (const Pixel& p : this->PIX) {
      out << (int) p.r() << ' '
          << (int) p.g() << ' '
          << (int) p.b() << ' ';
    }
  } else {
    for (const Pixel& p : this->PIX) {
      out << p.r() << p.g() << p.b();
    }
  }
}
