#ifndef INIT_HPP
#define INIT_HPP

#include "Settings.hpp"

#include <vector>

class Init
{
public:
	static std::vector<KCenterPointPtr> Forgy(std::vector<KDataPointPtr>* points, int n);
};

#endif