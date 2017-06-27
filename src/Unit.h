#pragma once
#include "Cell.h"


class Unit {
public:
	Unit(int id, Cell p);
	const Cell getPosition() const;
	void setPosition(const Cell &p);
	int getId() const;
	Unit move(const Cell & destination) const;

private:
	int id;
	Cell position;
};
