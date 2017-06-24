#include "Rules.h"



Rules::Rules(vector<Action> a) : actions(a) {};
vector<Action> Rules::getActions() const { return actions; }

