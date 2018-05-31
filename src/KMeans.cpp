#include "KMeans.hpp"
#include "KDataPoint.hpp"
#include "KCenterPoint.hpp"

#include <math.h>

double KMeans::Distance(KCenterPointPtr center, KDataPointPtr point)
{
	double d = std::sqrt(std::pow((center->x - point->x), 2) + std::pow((center->y - point->y), 2));
	return d;
}

double KMeans::Error(std::vector<KCenterPointPtr>* centers, std::vector<KDataPointPtr>* points)
{
	double error = 0;

	for (unsigned int i=0; i<points->size(); i++)
	{
		for (unsigned int j=0; j<centers->size(); j++)
		{
			if ((*points).at(i)->GetCenter() == (*centers).at(j)) {
				error += std::pow(Distance((*centers).at(j), (*points).at(i)), 2);
			}
		}
	}

	error /= points->size();

	return error;
}

void KMeans::FindNearest(std::vector<KCenterPointPtr>* centers, KDataPointPtr point)
{
	int start = 0;
	double dimension = Distance((*centers).at(0), point);

	for (unsigned int i=1; i<centers->size(); i++)
	{
		double d = Distance((*centers).at(i), point);

		if (d < dimension) {
			start = i;
			dimension = d;
		}
	}

	point->SetCenter((*centers).at(start));
}

void KMeans::Clusterize(std::vector<KCenterPointPtr>* centers, std::vector<KDataPointPtr>* points, std::vector<double>* errors)
{
	int it = 1;

	do
	{
		for (unsigned int i=0; i<points->size(); i++)
		{
			FindNearest(centers, (*points).at(i));
		}

		// Calculating error
		errors->push_back(Error(centers, points));

		for (unsigned int i=0; i<centers->size(); i++)
		{
			double x = 0;
			double y = 0;
			int count = 0;

			// Count the sum of all x, y positions
			for (unsigned int j=0; j<points->size(); j++)
			{
				if ((*points).at(j)->GetCenter() == (*centers).at(i)) {
					x += (*points).at(j)->x;
					y += (*points).at(j)->y;
					count++;
				}
			}

			// Divide by number of data point assigned to center
			if (count != 0) {
				x /= count;
				y /= count;

				// Assign new centroid position
				(*centers).at(i)->x = x;
				(*centers).at(i)->y = y;
			}
		}
		// Stops algorithm if no changes in error
		if (errors->at(it-1)-errors->at(it) == 0) {
			break;
		}

		it++;
	} while (true);
}
