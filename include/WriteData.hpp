#ifndef WRITEDATA_HPP
#define WRITEDATA_HPP

#include "Settings.hpp"

#include <string>
#include <vector>

class WriteData
{
public:
	static void WriteCenterPosition(std::vector<KCenterPointPtr>* centers, std::string path);
	static void WriteError(std::vector<double>* errors, std::string path);
};

#endif