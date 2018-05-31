#ifndef K_MEANS_HPP
#define K_MEANS_HPP

#include "Settings.hpp"

#include <vector>

class KMeans
{
private:
	static double Distance(KCenterPointPtr center, KDataPointPtr point);
	static double Error(std::vector<KCenterPointPtr>* centers, std::vector<KDataPointPtr>* points);
	static void FindNearest(std::vector<KCenterPointPtr>* centers, KDataPointPtr point);

public:
	static void Clusterize(std::vector<KCenterPointPtr>* centers, std::vector<KDataPointPtr>* points, std::vector<double>* errors);
};

#endif