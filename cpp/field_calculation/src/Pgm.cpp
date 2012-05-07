#include "Pgm.hpp"

Pgm::Pgm(int x, int y, int d)
: x_(x), y_(y), depth_(d)
{
	if (d > 0xffff) {
		throw PgmException(__FILE__ ":" STR(__LINE__) ":Depth is too high");
	}
	image_.reserve(x_);
	for (int i=0; i<x_; ++i) {
		vector <int> v(y_);
		image_.push_back(v);
	}
}

Pgm &Pgm::setPixel(const int x, const int y, const int color)
{
	if (x > x_ || y > y_ || color > depth_) {
		throw PgmException(__FILE__ ":" STR(__LINE__) ":Value(s) out of range");
	}
	image_[x][y] = color;
	return *this;
}

Pgm &Pgm::incPixel(const int x, const int y)
{
	if (x > x_ || y > y_) {
		throw PgmException(__FILE__ ":" STR(__LINE__) ":Value(s) out of range");
	}
	int c = image_[x][y];
	if (c == depth_) {
		throw PgmException(__FILE__ ":" STR(__LINE__) ":Overexposed!");
	}
	image_[x][y] = c+1;
	return *this;
}

void Pgm::save(const File &f)
{
	f.addString("P2").addLF().addInt(x_).addLF().addInt(y_).addLF();
	f.addInt(depth_).addLF();
	vector <vector <int> > ::reverse_iterator i1;
	vector <int> ::iterator i2;
	for (i1=image_.rbegin(); i1!=image_.rend(); ++i1) {
		for (i2=i1->begin(); i2!=i1->end(); ++i2) {
			f.addInt(*i2).addLF();
		}
	}
}
