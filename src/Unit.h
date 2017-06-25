#pragma once
#include "Cell.h"


class Unit {
public:
	Unit(Cell p);
	const Cell getPosition() const;
	void setPosition(const Cell &p);

private:
	Cell position;
};
