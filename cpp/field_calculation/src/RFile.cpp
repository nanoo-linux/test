#include "RFile.hpp"

#include <string>
#include <cstdlib>

RFile::RFile(const char *filename)
{
	file_ = fopen(filename, "r");
	if (file_ == NULL) {
		throw RFileException(__FILE__ ":" STR(__LINE__) ": Could not open file to read");
	}
}

RFile::~RFile()
{
	fclose(file_);
}

std::string RFile::readString()
{
	char *bytes;
	int n = fscanf(file_, "%ms", &bytes);
	if (n == 1) {
		std::string s(bytes);
		free(bytes);
		return s;
	} else {
		throw RFileException(__FILE__ ":" STR(__LINE__) ": Could not read string");
	}
}

int RFile::readInt()
{
	int ret;
	int n = fscanf(file_, "%d", &ret);
	if (n == 1) {
		return ret;
	} else {
		throw RFileException(__FILE__ ":" STR(__LINE__) ": Could not read int");
	}
}

double RFile::readDouble()
{
	double ret;
	int n = fscanf(file_, "%lf", &ret);
	if (n == 1) {
		return ret;
	} else {
		throw RFileException(__FILE__ ":" STR(__LINE__) ": Could not read double");
	}
}

int RFile::readBytes(char *buffer, int size)
{
	char byte;
	int r;
	for (int i=0; i<size; ++i) {
		r = fscanf(file_, "%c", &byte);
		if (r == 1) {
			buffer[i] = byte;
		} else {
			return i;
		}
	}
	return size;
}
