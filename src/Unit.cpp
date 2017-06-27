#include "Unit.h"

Unit::Unit(int id, Cell p) : id(id), position(p) {}
const Cell Unit::getPosition() const { return position; }
void Unit::setPosition(const Cell &p) { position = p; }
Unit Unit::move(const Cell & destination) const { return Unit(id, destination); }
int Unit::getId() const { return id; }

