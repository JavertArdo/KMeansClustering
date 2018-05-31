#ifndef READDATA_HPP
#define READDATA_HPP

#include "Settings.hpp"

#include <string>
#include <vector>

class ReadData
{
public:
	static std::vector<KDataPointPtr> ReadPoints(std::string path);
};

#endif