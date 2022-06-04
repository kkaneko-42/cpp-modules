#include <iostream>
#include <string>
#include "Point.hpp"

static Fixed getCrossProductZ( Point const &a, Point const &b );

bool bsp( Point const &a, Point const &b, Point const &c, Point const &point )
{
	Point AP( point - a );
	Point BP( point - b );
	Point CP( point - c );
	Point AB( b - a );
	Point BC( c - b );
	Point CA( a - c );

	if (getCrossProductZ(AB, BP) > 0
		&& getCrossProductZ(BC, CP) > 0
		&& getCrossProductZ(CA, AP) > 0)
		return (true);
	if (getCrossProductZ(AB, BP) < 0
			&& getCrossProductZ(BC, CP) < 0
			&& getCrossProductZ(CA, AP) < 0)
		return (true);
	else
		return (false);
}

static Fixed getCrossProductZ( Point const &a, Point const &b )
{
	return ((a.getX() * b.getY()) - (a.getY() * b.getX()));
}
