#include "PointCharge.hpp"

PointCharge::PointCharge
(int x, int y, double c)
: x_(x), y_(y), charge_(c)
{}

int PointCharge::x() const
{
	return x_;
}

int PointCharge::y() const
{
	return y_;
}

double PointCharge::charge() const
{
	return charge_;
}
