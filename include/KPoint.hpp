#ifndef K_POINT_HPP
#define K_POINT_HPP

class KPoint
{
public:
	double x;
	double y;

	KPoint(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	virtual ~KPoint() {}
};

#endif