#pragma once
#include <vector>
#include "Action.h"

class Rules {
public:
	Rules(vector<Action> a);
	vector<Action> getActions() const;

private:
	vector<Action> actions;
};

