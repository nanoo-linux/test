#include "Geometry.hpp"
#include <vector>
#include "RFile.hpp"

using std::vector;

Geometry::Geometry(const char *file)
{
	try {
		RFile f(file);
		readSize(f);
		while (readOnePoint(f));
	} catch (RFileException &e) {
		throw GeometryException(e.what());
	}
}

vector <PointCharge> &Geometry::points()
{
	return points_;
}

bool Geometry::readOnePoint(RFile &f)
{
	int x;
	int y;
	double c;
	try {
		x = f.readInt();
		y = f.readInt();
		c = f.readDouble();
	} catch (RFileException &e) {
		return false;
	}
	points_.push_back(PointCharge(x, y, c));
	return true;
}

void Geometry::readSize(RFile &f)
{
	size_.first = f.readInt();
	size_.second = f.readInt();
}

std::pair <int, int> Geometry::size() const
{
	return size_;
}
