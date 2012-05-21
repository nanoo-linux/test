#include "Engine.hpp"
#include "VectorField.hpp"
#include <limits>
#include <utility>
#include <algorithm>

#include <cstdio>
#include <stdlib.h>

using std::make_pair;
using std::pair;

const double dT = 1e-2;

Engine::Engine(Geometry &g, Rays &r)
: g_(g), r_(r), screen_x_(g.size().first)
{
	screen_.reserve(g.size().second+1);
}

Engine &Engine::simulate()
{
	Field f = prepare_field();
	VectorField vf(f);

	std::vector <Ray> rays = r_.rays();
	std::vector <Ray> ::iterator cray;
	std::vector <Ray> ::iterator _i;
	while (!rays.empty()) {
		cray = rays.begin();
		while (cray!=rays.end()) {
			Vector &r(cray->r());
			//puts(r.str().c_str());
			cray->applyEstaticF(vf(r),dT);
			if (r.x() > screen_x_) {
				screen_[r.y()] += 1;
				_i = cray;
				++cray;
				rays.erase(_i);
				continue;
			}
			if (r.y() < 0 || r.y() > g_.size().second) {
				if (r.x() < 0 || r.x() > g_.size().first) {
					_i = cray;
					++cray;
					rays.erase(_i);
					continue;
				}
			}
			++cray;
		}
		//usleep(500000);
	}
	return *this;
}

Field Engine::prepare_field()
{
	pair <int, int> s = g_.size();
	// TODO: size has to be in mm? or mkm?
	Field f(s.first, s.second, make_pair (s.first*1000., s.second*1000.));
	vector <PointCharge> &pts = g_.points();
	vector <PointCharge> ::iterator it = pts.begin();
	while (it!=pts.end()) {
		f.addQ(it->x(), it->y(), it->charge());
		++it;
	}

	return f.refine();
}

Pgm Engine::pgm()
{
	//TODO:
	throw EngineException("pgm method not implemented");
	return Pgm(10,10);
}

Engine &Engine::save(File &f)
{
	vector <long long> ::iterator it = screen_.begin();
	long long max = *std::max_element(it, screen_.end());
	while (it!=screen_.end()) {
		f.addInt((int)(65535./max*(*it))).addLF();
		++it;
	}
	return *this;
}
