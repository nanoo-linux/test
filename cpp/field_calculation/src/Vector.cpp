#include "Vector.hpp"

#include <sstream>

Vector::Vector(double x, double y)
: x_(x), y_(y)
{}

Vector::Vector(const Vector &v)
: x_(v.x_), y_(v.y_)
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

Vector operator *(const Vector &v, double d)
{
	return Vector(v) *= d;
}

std::string Vector::str() const
{
	std::stringstream s;
	//s << "<" << x_ << ":" << y_ << ">";
	s << x_ << "\t" << y_ ;
	return s.str();
}

double Vector::x() const
{
	return x_;
}

double Vector::y() const
{
	return y_;
}
