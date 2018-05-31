#ifndef K_CENTERPOINT_HPP
#define K_CENTERPOINT_HPP

#include "KPoint.hpp"

#include <vector>

class KCenterPoint : public KPoint
{
public:
	KCenterPoint(double x, double y)
		: KPoint(x, y)
	{}
	virtual ~KCenterPoint() {}
};

#endif