#include "WriteData.hpp"
#include "KCenterPoint.hpp"

#include <fstream>
#include <sstream>

void WriteData::WriteCenterPosition(std::vector<KCenterPointPtr>* centers, std::string path)
{
	std::ofstream file;

	try
	{
		// Opening file
		file.open(path);

		for (unsigned int i=0; i<centers->size(); i++) {
			std::stringstream x;
			std::stringstream y;
			x << centers->at(i)->x;
			y << centers->at(i)->y;
			file << x.str() + "," + y.str() + "\n";
		}

		// Closing file
		file.close();
	}
	catch (...) {}
}

void WriteData::WriteError(std::vector<double>* errors, std::string path)
{
	std::ofstream file;

	try
	{
		// Opening file
		file.open(path);

		for (unsigned int i=0; i<errors->size(); i++) {
			std::stringstream error;
			error << errors->at(i);
			file << error.str() + "\n";
		}

		// Closing file
		file.close();
	}
	catch (...) {}
}