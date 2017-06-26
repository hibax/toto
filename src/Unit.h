#pragma once
#include "Cell.h"


class Unit {
public:
	Unit(int id, Cell p);
	const Cell getPosition() const;
	void setPosition(const Cell &p);
	int getId() const;

private:
	int id;
	Cell position;
};
