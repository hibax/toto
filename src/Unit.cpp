#include "Unit.h"

Unit::Unit(int id, Cell p) : id(id), position(p) {}
const Cell Unit::getPosition() const { return position; }
void Unit::setPosition(const Cell &p) { position = p; }

int Unit::getId() const { return id; }

