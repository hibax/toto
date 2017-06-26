#include "Unit.h"

Unit::Unit(Cell p) : position(p) {}
const Cell Unit::getPosition() const { return position; }
void Unit::setPosition(const Cell &p) { position = p; }

