#include "Unit.h"

Unit::Unit(Point p) : position(p) {}
const Point Unit::getPosition() const { return position; }
void Unit::setPosition(const Point &p) { position = p; }

