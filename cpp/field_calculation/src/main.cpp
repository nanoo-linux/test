#include "Field.hpp"
#include "File.hpp"

int main()
{
	Field f(100, 100);
	f.addQ(30, 30, -12.);
	f.addQ(60, 60, 10.);
	f.refine().pgm().save(File("dump.pgm"));
}
