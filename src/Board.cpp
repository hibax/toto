#include "Board.h"
#include <algorithm>


Board::Board() :
	grid(), ourUnits(), otherUnits(), legalActions()
{}
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

vector<Unit> Board::getOurUnits() const { return ourUnits; }
vector<Unit> Board::getOtherUnits() const { return otherUnits; }
Grid Board::getGrid() const { return grid; }

Cell Board::getPosition(int index) const {
	return getUnit(index).getPosition();
}

const Unit& Board::getUnit(int index) const {
	if (index < ourUnits.size()) {
		return ourUnits[index];
	}
	return otherUnits[index - ourUnits.size()];
} 

Cell Board::getDestinationCell(const Cell & position, DIRECTION direction) {
	switch (direction) {
		case N:
			return Cell(position.column, position.row - 1);
		case NE:
			return Cell(position.column + 1, position.row - 1);
		case E:
			return Cell(position.column + 1, position.row);
		case SE:
			return Cell(position.column + 1, position.row + 1);
		case S:
			return Cell(position.column, position.row + 1);
		case SW:
			return Cell(position.column - 1, position.row + 1);
		case W:
			return Cell(position.column - 1, position.row);
		case NW:
			return Cell(position.column - 1, position.row - 1);
	}
}

vector<Action> Board::produceUnitLegalActions(const Unit & unit) const
{
	vector<Action> legalActions;

	for (int dirMove = DIRECTION::N; dirMove != DIRECTION::NW; ++dirMove) {

		for (int dirBuild = DIRECTION::N; dirBuild != DIRECTION::NW; ++dirBuild) {

			Action possibleAction(ACTION_TYPE::MOVEBUILD, unit.getId(), static_cast<DIRECTION>(dirMove), static_cast<DIRECTION>(dirBuild));

			if (isValid(possibleAction)) {
				legalActions.push_back(possibleAction);
			}
		}
	}

	return legalActions;
}

vector<Action> Board::produceAllLegalActions(bool myTurn) const
{
	vector<Action> allActions;
	vector<Unit> units = myTurn? ourUnits : otherUnits;

	for (Unit unit : units) {
		vector<Action> unitActions = produceUnitLegalActions(unit);

		allActions.insert(allActions.end(), unitActions.begin(), unitActions.end());
	}

	return allActions;
}

bool Board::isValid(const Action & action) const {
	const Cell & sourceCell = getPosition(action.getIndex());
	const Cell & destinationCell = getDestinationCell(sourceCell, action.getDirMove());

	bool canMove = grid.canMove(sourceCell, destinationCell, ourUnits, otherUnits);

	const Cell & buildCell = getDestinationCell(destinationCell, action.getDirBuild());
	bool canBuild = grid.canBuild(sourceCell, buildCell, ourUnits, otherUnits);

	return canMove && canBuild;
}

Board Board::play(const Action & action) const {
	
	vector<Unit> newOurUnits(ourUnits);
	vector<Unit> newOtherUnits(otherUnits);

	const Unit & unit = getUnit(action.getIndex());
	auto newUnit = unit.move(getDestinationCell(unit.getPosition(), action.getDirMove()));

	if (action.getIndex() < newOurUnits.size()) {
		newOurUnits[action.getIndex()] = newUnit;
	} else {
		newOtherUnits[action.getIndex() - newOurUnits.size()] = newUnit;
	}

	auto newGrid = grid.build(getDestinationCell(newUnit.getPosition(), action.getDirBuild()));

	vector<string> lA;

	return Board(newGrid, newOurUnits, newOtherUnits, lA);
}


