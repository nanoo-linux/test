#pragma once

#include "Vector.hpp"

class Ray
{
	public:
		Ray();
		Vector q() const;
		Vector vq() const;
		Ray &q(Vector &);
		Ray &vq(Vector &);
		Ray &applyF(Vector &, double dt);
	private:
		Vector q_;
		Vector vq_;
};
