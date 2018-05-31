#include "Init.hpp"
#include "KDataPoint.hpp"
#include "KCenterPoint.hpp"

#include <algorithm>
#include <stdlib.h>

std::vector<KCenterPointPtr> Init::Forgy(std::vector<KDataPointPtr>* points, int n)
{
	std::vector<KCenterPointPtr> centers;
	std::vector<int> values;

	for (int i=0; i<n; i++)
	{
		int r = rand()%(points->size()-1);

		if (std::find(values.begin(), values.end(), r) != values.end()) {
			i--;
		} else {
			values.push_back(r);
			centers.push_back(std::make_shared<KCenterPoint>(points->at(r)->x, points->at(r)->y));
		}
	}

	return centers;
}
