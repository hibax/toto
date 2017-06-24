// WonderDev.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <assert.h>
#include "gtest/gtest.h"
#include "Action.h"
#include "Grid.h"
#include "Point.h"
#include "Unit.h"
#include "Board.h"


/*
	Uncomment in Coding Game

int main()
{
	int size;
	cin >> size; cin.ignore();
	int unitsPerPlayer;
	cin >> unitsPerPlayer; cin.ignore();

	int counter = 0;

	// game loop
	while (1) {
		for (int i = 0; i < size; i++) {
			string row;
			cin >> row; cin.ignore();
		}

		for (int i = 0; i < unitsPerPlayer; i++) {
			Point pos;
			cin >> pos.x >> pos.y; cin.ignore();
		}
		for (int i = 0; i < unitsPerPlayer; i++) {
			int otherX;
			int otherY;
			cin >> otherX >> otherY; cin.ignore();
		}

		vector<string> legalActions;

		int legalActionsSize;
		cin >> legalActionsSize; cin.ignore();
		for (int i = 0; i < legalActionsSize; i++) {
			string type;
			int index;
			string dir1;
			string dir2;
			cin >> type >> index >> dir1 >> dir2; cin.ignore();
			legalActions.push_back(type + " " + to_string(index) + " " + dir1 + " " + dir2);
		}

		// Write an action using cout. DON'T FORGET THE "<< endl"
		// To debug: cerr << "Debug messages..." << endl;
		counter++;
		cout << generateAction(counter, legalActions) << endl;

	}
}
*/

/*
	main for local test
*/
int main(int argc, char** argv) {
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
	ourUnits.push_back(Unit({2, 2}));
	vector<Unit> otherUnits;
	otherUnits.push_back(Unit({3, 3}));

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

	assert(grid.getCell(1, 2) == 4);
	assert(grid.getCell(4, 1) == 0);
	assert(grid.getCell(4, 0) == -1);
	assert(grid.getCell(2, 3) == 2);

	Board board(grid, ourUnits, otherUnits, legalActions);

	assert(board.generateAction(counter) == "MOVE&BUILD 0 S N");

	cout << board.generateAction(counter) << endl;;

	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS(); 

}