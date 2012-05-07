#pragma once

#include "Exception.hpp"
#include <cstdio>
#include <string>

class RFileException: public Exception
{
	public:
		RFileException(const char *s, int c=-1): Exception(s, c) {}
};

class RFile
{
	public:
		RFile(const char *);
		~RFile();
		std::string readString();
		int readInt();
		double readDouble();
		int readBytes(char *, int);
	private:
		FILE *file_;
};
