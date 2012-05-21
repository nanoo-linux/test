#pragma once

#include <string>

class Vector
{
	public:
		Vector(double x=0, double y=0);
		Vector(const Vector &);
		double operator *=(const Vector &) const;
		Vector &operator *=(double);
		Vector &operator +=(const Vector &);
		double x() const;
		double y() const;
		std::string str() const;
	private:
		double x_;
		double y_;
};

Vector operator +(const Vector &, const Vector &);
double operator *(const Vector &, const Vector &);
