#include "File.hpp"

#include <sstream>

File::File(const char *fname)
{
	file_ = fopen(fname, "w");
	if (file_ < 0) {
		throw FileException(HDR "Could not open file to write");
	}
}

File::~File()
{
	fclose(file_);
}

File &File::addString(const char *s)
{
	fprintf(file_, "%s", s);
	return *this;
}

File &File::addString(const std::string &s)
{
	return addString(s.c_str());
}

File &File::addInt(int a)
{
	std::stringstream s;
	s << a;
	return addString(s.str());
}

File &File::addLF()
{
	return addString("\n");
}

