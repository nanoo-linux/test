#include "Vector.hpp"

#include <sstream>

Vector::Vector(double x, double y)
: x_(x), y_(y)
{}

double Vector::operator *=(const Vector &v) const
{
	return v.x_*x_ + v.y_*y_;
}

Vector &Vector::operator +=(const Vector &v)
{
	x_ += v.x_;
	y_ += v.y_;
	return *this;
}

Vector &Vector::operator *=(double d)
{
	x_ *= d;
	y_ *= d;
	return *this;
}

Vector operator +(const Vector &v, const Vector &w)
{
	return Vector(v) += w;
}

double operator *(const Vector &v, const Vector &w)
{
	return Vector(v) *= w;
}

std::string Vector::str() const
{
	std::stringstream s;
	s << "<" << x_ << ":" << y_ << ">" << std::endl;
	return s.str();
}
