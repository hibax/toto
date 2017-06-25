#pragma once
#include <vector>
#include <string>
#include "Grid.h"
#include "Unit.h"
#include "Action.h"

using namespace std;

class Board {
public:
	Board(Grid &g, vector<Unit> &ours, vector<Unit> &others, vector<string> &legalActions);

	string generateAction(const int& counter);

	Cell getOurUnitPosition(int index) const;

	bool isValid(const Action & action) const;

	Board play(const Action & action) const;

private:
	Cell getPosition(int index) const;

	Grid grid;
	vector<Unit> ourUnits;
	vector<Unit> otherUnits;
	vector<string> legalActions;
};