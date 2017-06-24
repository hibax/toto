#pragma once
#include "Point.h"


class Unit {
public:
	Unit(Point p);
	const Point getPosition() const;
	void setPosition(const Point &p);

private:
	Point position;
};
