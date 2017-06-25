#pragma once
#include <vector>
#include "Action.h"

/*
class Rules {
public:
	Rules(vector<Action> a);
	vector<Action> getActions() const;

private:
	vector<Action> actions;
};
*/

namespace GameRules {
	vector<pair<Action, Board> > produceNextValidBoards(const Board & board, bool myTurn);
}

