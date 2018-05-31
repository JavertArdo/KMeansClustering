#include "ReadData.hpp"
#include "KDataPoint.hpp"

#include <fstream>
#include <sstream>

std::vector<KDataPointPtr> ReadData::ReadPoints(std::string path)
{
	std::vector<KDataPointPtr> points;
	std::ifstream file;
	std::string line;
	char split = ',';

	try
	{
		// Opening file
		file.open(path);

		// Reading file
		while (std::getline(file, line))
		{
			std::stringstream xs;
			std::stringstream ys;
			double x;
			double y;
			bool c = false;

			// Splitting one line
			for (long unsigned int i=0; i<line.size(); i++)
			{
				if (line[i] == split) {
					c = true;
					i++;
				}

				if (!c) {
					xs << line[i];
				} else {
					ys << line[i];
				}
			}

			x = std::stod(xs.str());
			y = std::stod(ys.str());

			points.push_back(std::make_shared<KDataPoint>(x, y));
		}

		// Closing file
		file.close();
	}
	catch (...) {}

	return points;
}