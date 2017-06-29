#include <limits.h>
#include "gtest/gtest.h"
#include "Board.h"
#include "Algo.h"

using namespace std;

TEST(Board, testGenerateAction) {

	int counter = 1;

	int size = 5;
	int unitsPerPlayer = 1;
	vector<string> rows;
	rows.push_back(".000.");
	rows.push_back("00000");
	rows.push_back("04104");
	rows.push_back("03234");
	rows.push_back("00003");

	vector<Unit> ourUnits;
	ourUnits.push_back(Unit(0, { 0, 0 }));
	vector<Unit> otherUnits;
	otherUnits.push_back(Unit(1, { 3, 3 }));

	vector<string> legalActions;
	legalActions.push_back("MOVE&BUILD 0 E N");
	legalActions.push_back("MOVE&BUILD 0 E NE");
	legalActions.push_back("MOVE&BUILD 0 E NW");
	legalActions.push_back("MOVE&BUILD 0 E SW");
	legalActions.push_back("MOVE&BUILD 0 E W");
	legalActions.push_back("MOVE&BUILD 0 N E");
	legalActions.push_back("MOVE&BUILD 0 N N");
	legalActions.push_back("MOVE&BUILD 0 N NE");
	legalActions.push_back("MOVE&BUILD 0 N NW");
	legalActions.push_back("MOVE&BUILD 0 N S");
	legalActions.push_back("MOVE&BUILD 0 N SE");
	legalActions.push_back("MOVE&BUILD 0 N W");
	legalActions.push_back("MOVE&BUILD 0 NE E");
	legalActions.push_back("MOVE&BUILD 0 NE N");
	legalActions.push_back("MOVE&BUILD 0 NE NE");
	legalActions.push_back("MOVE&BUILD 0 NE NW");
	legalActions.push_back("MOVE&BUILD 0 NE S");
	legalActions.push_back("MOVE&BUILD 0 NE SW");
	legalActions.push_back("MOVE&BUILD 0 NE W");
	legalActions.push_back("MOVE&BUILD 0 NW E");
	legalActions.push_back("MOVE&BUILD 0 NW N");
	legalActions.push_back("MOVE&BUILD 0 NW NE");
	legalActions.push_back("MOVE&BUILD 0 NW NW");
	legalActions.push_back("MOVE&BUILD 0 NW SE");
	legalActions.push_back("MOVE&BUILD 0 NW SW");
	legalActions.push_back("MOVE&BUILD 0 NW W");
	legalActions.push_back("MOVE&BUILD 0 S N");
	legalActions.push_back("MOVE&BUILD 0 S NE");
	legalActions.push_back("MOVE&BUILD 0 S S");
	legalActions.push_back("MOVE&BUILD 0 S SE");
	legalActions.push_back("MOVE&BUILD 0 S SW");
	legalActions.push_back("MOVE&BUILD 0 S W");


	vector<vector<int> > cells(size, vector<int>(size));
	Grid grid(cells, size);
	grid.fillGrid(grid, rows, size);

	Board board(grid, ourUnits, otherUnits, legalActions);

	pair<Action, Board> result = Algo::getBest(make_pair(Action(), board));

	Action actionToPerform = result.first;
	string actionAsString = actionToPerform.getAsString();

	EXPECT_NE(actionToPerform.getAsString(), "MOVE&BUILD 0 N N");

	EXPECT_EQ(board.generateAction(counter), "MOVE&BUILD 0 S N");

}


TEST(Board, testCantClimb) {


	int size = 5;
	int unitsPerPlayer = 1;
	vector<string> rows;
	rows.push_back("00000");
	rows.push_back("00000");
	rows.push_back("00000");
	rows.push_back("00000");
	rows.push_back("30000");

	vector<Unit> ourUnits;
	ourUnits.push_back(Unit(0, { 0, 3 }));
	vector<Unit> otherUnits;
	otherUnits.push_back(Unit(1, { 3, 3 }));

	vector<string> legalActions;


	vector<vector<int> > cells(size, vector<int>(size));
	Grid grid(cells, size);
	grid.fillGrid(grid, rows, size);

	Board board(grid, ourUnits, otherUnits, legalActions);

	pair<Action, Board> result = Algo::getBest(make_pair(Action(), board));

	Action actionToPerform = result.first;
	string actionAsString = actionToPerform.getAsString();

	EXPECT_NE(actionAsString.substr(0, actionAsString.size()-2), "MOVE&BUILD 0 S");

}


TEST(Board, cantSeeEnemies) {


	int size = 5;
	int unitsPerPlayer = 1;
	vector<string> rows;
	rows.push_back("00000");
	rows.push_back("00000");
	rows.push_back("00000");
	rows.push_back("00000");
	rows.push_back("30000");

	vector<Unit> ourUnits;
	ourUnits.push_back(Unit(0, { 0, 3 }));
	ourUnits.push_back(Unit(1, { 2, 3 }));
	vector<Unit> otherUnits;
	otherUnits.push_back(Unit(0, { -1, -1 }));
	otherUnits.push_back(Unit(1, { -1, -1 }));

	vector<string> legalActions;


	vector<vector<int> > cells(size, vector<int>(size));
	Grid grid(cells, size);
	grid.fillGrid(grid, rows, size);

	Board board(grid, ourUnits, otherUnits, legalActions);

	pair<Action, Board> result = Algo::getBest(make_pair(Action(), board));

	Action actionToPerform = result.first;
	string actionAsString = actionToPerform.getAsString();

	EXPECT_NE(actionAsString.substr(0, actionAsString.size() - 2), "MOVE&BUILD 0 S");

}

