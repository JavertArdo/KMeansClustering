#ifndef K_DATAPOINT_HPP
#define K_DATAPOINT_HPP

#include "Settings.hpp"
#include "KPoint.hpp"

class KDataPoint : public KPoint
{
private:
	KCenterPointPtr center;

public:
	KDataPoint(double x, double y)
		: KPoint(x, y)
	{}
	virtual ~KDataPoint() {}

	KCenterPointPtr GetCenter() {
		return center;
	}
	void SetCenter(KCenterPointPtr center) {
		this->center = center;
	}
};

#endif