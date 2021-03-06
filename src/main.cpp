#include <iostream>
#include <sstream>
#include <vector>

#include "KDataPoint.hpp"
#include "KCenterPoint.hpp"
#include "ReadData.hpp"
#include "WriteData.hpp"
#include "Init.hpp"
#include "KMeans.hpp"

#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv)
{
	srand(time(NULL));

	std::stringstream filePath;
	std::stringstream initMethod;
	int numOfCenters;

	filePath << argv[argc-3];
	initMethod << argv[argc-2];
	numOfCenters = std::stoi(argv[argc-1]);

	std::vector<KDataPointPtr> points = ReadData::ReadPoints(filePath.str());
	std::vector<KCenterPointPtr> centers;

	if (initMethod.str() == "forgy") {
		centers = Init::Forgy(&points, numOfCenters);
	} else {
		centers = Init::Forgy(&points, numOfCenters);
	}

	WriteData::WriteCenterPosition(&centers, "./centers_begin.txt");

	std::vector<double> errors = {0};
	KMeans::Clusterize(&centers, &points, &errors);

	WriteData::WriteCenterPosition(&centers, "./centers_end.txt");

	errors.erase(errors.begin());
	WriteData::WriteError(&errors, "./errors.txt");

	return 0;
}