#include "Field.hpp"

#include "Pgm.hpp"
#include <utility>
#include <limits>

using std::make_pair;

Field::Field(int x, int y, pair <double, double> mesh)
: x_(x), y_(y), refined_(false), mesh_(mesh)
{
	min_ = 0;
	max_ = 1;
	v_.reserve(x_);
	for (int i=0; i<x_; ++i) {
		vector <pair <bool, double> > v;
		for (int j=0; j<y_; ++j) {
			v.push_back(make_pair(true, 0.));
		}
		v_.push_back(v);
	}
}

Field &Field::addQ(int x, int y, double p)
{
	if (x > x_ || y > y_) {
		throw FieldException("Field::addQ: out of range");
	}
	v_[x][y] = make_pair (false, p);
	if (min_ > p) {
		min_ = p;
	}
	if (max_ < p) {
		max_ = p;
	}
	return *this;
}

Field &Field::refine(int n)
{
	while (n-- >= 0) {
		for (int i=1; i<x_-1; ++i) {
			for (int j=1; j<y_-1; ++j) {
				if (v_[i][j].first) {
					double v1 = v_[i-1][j].second;
					double v2 = v_[i+1][j].second;
					double v3 = v_[i][j-1].second;
					double v4 = v_[i][j+1].second;
					v_[i][j].second = (v1+v2+v3+v4)/4;
				}
			}
		}
	}
	refined_ = true;
	return *this;
}

Pgm Field::pgm() const
{
	if (!refined_) {
		throw PgmException("Field::image: not refined");
	}
	Pgm pgm(x_, y_);
	double k = 65535./(max_ - min_);
	for (int i=0; i<x_; ++i) {
		for (int j=0; j<y_; ++j) {
			pgm.setPixel(i, j, int(((v_[i][j].second-min_))*k));
		}
	}
	return pgm;
}

std::pair <bool, double> Field::operator ()(int x, int y) const
{
	if (x > x_ || y > y_) {
		throw FieldException("Field::op(): out of range");
	}
	return v_[x][y];
}

std::pair <int, int> Field::size() const
{
	return std::make_pair <int, int> (x_, y_);
}

const std::pair <double, double> Field::mesh() const
{
	return mesh_;
}

bool Field::refined() const
{
	return refined_;
}
