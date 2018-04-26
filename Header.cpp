/**
Isabella Gebhart and Clare DuVal
CPSC 002 Spring 2018
igehbar, ckduval
**/

#include "Header.h"

Header::Header () :
  MAGIC(""), W(0), H(0), MC(0) {}
Header::Header (const Header& HDR) :
  MAGIC(HDR.MAGIC), W(HDR.W), H(HDR.H), MC(HDR.MC) {}
Header::Header (string m, int w, int h, int mc) :
  MAGIC(m), W(w), H(h), MC(mc) {}
Header::~Header () {}

// Simple getter
 string Header::magic () const { return this->MAGIC; }
int Header::width () const { return this->W; }
int Header::height () const { return this->H; }
int Header::max_color () const { return this->MC; }

// Ref getter
string& Header::magic () { return this->MAGIC; }
int& Header::width () { return this->W; }
int& Header::height () { return this->H; }
int& Header::max_color () { return this->MC; }

// This will grab the header nformation 
Header& Header::operator= (const Header& hdr) {
  this->MAGIC = hdr.MAGIC;
  this->W     = hdr.W;
  this->H     = hdr.H;
  this->MC    = hdr.MC;
  return *this;
}

ostream& operator<< (ostream& out, const Header& hdr) {
  return out << hdr.magic() <<  endl
      << hdr.width() <<  endl
      << hdr.height() <<  endl
      << hdr.max_color() <<  endl;
}
