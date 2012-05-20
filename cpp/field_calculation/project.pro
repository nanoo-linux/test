TEMPLATE = app
TARGET = ficmp

CONFIG -= qt
OBJECTS_DIR = obj

SOURCES += src/main.cpp \
		src/Field.cpp \
		src/File.cpp \
		src/Pgm.cpp \
		src/VectorField.cpp \
		src/Geometry.cpp \
		src/RFile.cpp \
		src/PointCharge.cpp \
		src/Rays.cpp \
		src/Ray.cpp \
		src/Engine.cpp \
		src/Vector.cpp

HEADERS += src/Pgm.hpp \
		src/File.hpp \
		src/Field.hpp \
		src/Exception.hpp \
		src/VectorField.hpp \
		src/iGeometry.hpp \
		src/Geometry.hpp \
		src/RFile.hpp \
		src/PointCharge.hpp \
		src/Rays.hpp \
		src/Ray.hpp \
		src/Engine.hpp \
		src/Vector.hpp
