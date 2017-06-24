#pragma once
#include <vector>
#include "Grid.h"
#include "Unit.h"

using namespace std;

class Board {
public:
	Board(Grid &g, vector<Unit> &ours, vector<Unit> &others, vector<string> &legalActions);

	string generateAction(const int& counter);

private:
	Grid grid;
	vector<Unit> ourUnits;
	vector<Unit> otherUnits;
	vector<string> legalActions;
};