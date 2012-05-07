#include "Ray.hpp"

Ray::Ray()
: q_(), vq_()
{}

Vector Ray::q() const
{
	return q_;
}

Vector Ray::vq() const
{
	return vq_;
}

Ray &Ray::q(Vector &q)
{
	q_ = q;
	return *this;
}

Ray &Ray::vq(Vector &vq)
{
	vq_ = vq;
	return *this;
}

Ray &Ray::applyF(Vector &F, double dt)
{
	//TODO
}
