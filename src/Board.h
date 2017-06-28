#pragma once
#include <vector>
#include <string>
#include "Grid.h"
#include "Unit.h"
#include "Action.h"

using namespace std;

class Board {
public:
	Board();
	Board(Grid &g, vector<Unit> &ours, vector<Unit> &others, vector<string> &legalActions);

	string generateAction(const int& counter);

	Cell getOurUnitPosition(int index) const;

	vector<Unit> getOurUnits() const;
	vector<Unit> getOtherUnits() const;
	const Unit& getUnit(int index) const;
	Grid getGrid() const;

	bool isValid(const Action & action) const;

	bool canBuild(const Cell & sourceCell, const Cell & destinationCell) const;
	bool canMove(const Cell & sourceCell, const Cell & destinationCell) const;

	Board play(const Action & action) const;

	static Cell getDestinationCell(const Cell & position, DIRECTION direction);

	vector<Action> produceUnitLegalActions(const Unit & unit) const;

	vector<Action> produceAllLegalActions(bool myTurn) const;

private:
	Cell getPosition(int index) const;

	Grid grid;
	vector<Unit> ourUnits;
	vector<Unit> otherUnits;
	vector<string> legalActions;
};