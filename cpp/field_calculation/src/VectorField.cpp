#include "VectorField.hpp"
#include <cmath>

using std::vector;
using std::pair;
using std::make_pair;

VectorField::VectorField(const Field &f)
{
	if (!f.refined()) {
		throw VectorFieldException("VectorField::VectorField: Field is not refined");
	}

	std::pair <int, int> size = f.size();
	x_ = size.first -1;
	y_ = size.second -1;
	max_ = 0;
	pair <bool, double> p;
	pair <bool, double> px;
	pair <bool, double> py;
	const pair <double, double> m = f.mesh();
	double vx, vy;
	v_.reserve(x_);
	for (int i=0; i<x_; ++i) {
		vector <pair <double, double> > v;
		for (int j=0; j<y_; ++j) {
			p = f(i, j);
			px = f(i+1, j);
			py = f(i, j+1);
			vx = (px.second - p.second)/ m.first;
			vy = (py.second - p.second)/ m.second;
			const double t = sqrt(vx*vx + vy*vy);
			max_ = t > max_ ? t : max_;
			max_ = max_ > vx ? max_ : vx;
			max_ = max_ > vy ? max_ : vy;
			v.push_back(make_pair(vx, vy));
		}
		v_.push_back(v);
	}
}

pair <double, double> VectorField::operator ()(int x, int y)
{
	if (x > x_ || y > y_) {
		throw VectorFieldException("VectorField::op(): out of range");
	}
	return v_[x][y];
}

Pgm VectorField::pgm() const
{
	Pgm pgm(x_, y_);
	double k = 65535./(max_);
	for (int i=0; i<x_; ++i) {
		for (int j=0; j<y_; ++j) {
			const double a = v_[i][j].first;
			const double b = v_[i][j].second;
			const double c = sqrt(a*a + b*b);
			pgm.setPixel(i, j, int(c*k));
		}
	}
	return pgm;
}
