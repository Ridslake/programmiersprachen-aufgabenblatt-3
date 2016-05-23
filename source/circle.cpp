#include "circle.hpp"
#include <cmath>
#define M_PI   3.14159265358979323846 


Circle::Circle():	//default
rad_{1}{}

Circle::Circle(float rad): //custom
rad_{rad}{}

void Circle::setradius(float r)	//set r
{
	rad_=r;
}

float Circle::getradius()	//get r
{
	return rad_;
}

bool Circle::operator<(Circle const& b) //comparison
{
	return rad_ < b.rad_;
}
bool Circle::operator>(Circle const& b)
{
	return rad_ > b.rad_;
}		
bool Circle::operator==(Circle const& b)
{
	return rad_ == b.rad_;
}
