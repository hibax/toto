#include "Board.h"
#include <algorithm>


Board::Board(Grid &g, vector<Unit> &ours, vector<Unit> &others, vector<string> &legalActions) :
	grid(g), ourUnits(ours), otherUnits(others), legalActions(legalActions)
{}

string Board::generateAction(const int& counter) {
	string action = "";

	if (counter % 2 == 0) {
		action = "MOVE&BUILD 0 N S";
	}
	else {
		action = "MOVE&BUILD 0 S N";
	}

	if (std::find(legalActions.begin(), legalActions.end(), action) == legalActions.end())
	{
		action = legalActions.at(0);
	}
	return action;
}