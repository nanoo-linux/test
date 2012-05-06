#include "VectorField.hpp"
#include "Field.hpp"
#include "File.hpp"
#include <utility>

int main()
{
	File f1("field.pgm");
	File f2("vector.pgm");
	Field f(100, 100, std::make_pair <double, double> (1, 1));
	f.addQ(30, 30, -12.);
	f.addQ(60, 60, 10.);
	f.refine().pgm().save(f1);
	VectorField vf(f);
	vf.pgm().save(f2);
}
