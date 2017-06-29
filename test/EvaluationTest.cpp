#include <limits.h>
#include "gtest/gtest.h"
#include "Evaluation.h"
#include "Unit.h"
#include "Grid.h"
#include "Algo.h"
#include "Board.h"
#include "Action.h"

using namespace std;


TEST(Evaluation, firstTest){

	int size = 5;
	int unitsPerPlayer = 1;
	vector<string> rows;
	rows.push_back("00000");
	rows.push_back("00000");
	rows.push_back("00000");
	rows.push_back("00032");
	rows.push_back("03210");

	vector<Unit> ourUnits;
	ourUnits.push_back(Unit(0, { 1, 3 }));
	vector<Unit> otherUnits;
	otherUnits.push_back(Unit(1, { 4, 4 }));

	vector<string> legalActions;

	vector<vector<int> > cells(size, vector<int>(size));
	Grid grid(cells, size);
	grid.fillGrid(grid, rows, size);

	Board board(grid, ourUnits, otherUnits, legalActions);

	
	Action actionScore(ACTION_TYPE::MOVEBUILD, 0, DIRECTION::S, DIRECTION::E);
	EXPECT_EQ(2*SCORING_VALUE + 6, Evaluation::score(make_pair(actionScore, board.play(actionScore))));

	Action actionCloseBuilding(ACTION_TYPE::MOVEBUILD, 0, DIRECTION::E, DIRECTION::SW);
	EXPECT_EQ(-CLOSING_BUILDING_VALUE - 4, Evaluation::score(make_pair(actionCloseBuilding, board.play(actionCloseBuilding))));

	Action actionBlockingEnemy(ACTION_TYPE::MOVEBUILD, 0, DIRECTION::E, DIRECTION::SE);
	EXPECT_EQ(BLOCKING_VALUE - 2, Evaluation::score(make_pair(actionBlockingEnemy, board.play(actionBlockingEnemy))));


	pair<Action, Board> bestState = Algo::getBest(make_pair(Action(), board));
	EXPECT_EQ(actionBlockingEnemy.getAsString(), bestState.first.getAsString());

}


TEST(Evaluation, fullOfScoringCells) {

	int size = 7;
	int unitsPerPlayer = 1;
	vector<string> rows;
	rows.push_back("...3...");
	rows.push_back("..333..");
	rows.push_back(".33333.");
	rows.push_back("3333311");
	rows.push_back(".33333.");
	rows.push_back("..333..");
	rows.push_back("...3...");
	
	vector<Unit> ourUnits;
	ourUnits.push_back(Unit(0, { 5, 3 }));
	ourUnits.push_back(Unit(1, { 0, 3 }));

	vector<Unit> otherUnits;
	otherUnits.push_back(Unit(0, { 3, 0 }));
	otherUnits.push_back(Unit(1, { 6, 3 }));

	vector<string> legalActions;

	vector<vector<int> > cells(size, vector<int>(size));
	Grid grid(cells, size);
	grid.fillGrid(grid, rows, size);

	Board board(grid, ourUnits, otherUnits, legalActions);


	Action actionBlockingEnemy(ACTION_TYPE::MOVEBUILD, 0, DIRECTION::E, DIRECTION::SE);


	pair<Action, Board> bestState = Algo::getBest(make_pair(Action(), board));
	//EXPECT_EQ(actionBlockingEnemy.getAsString(), bestState.first.getAsString());

}



TEST(Evaluation, almostBlocked) {

	int size = 7;
	int unitsPerPlayer = 1;
	vector<string> rows;
	rows.push_back("...4...");
	rows.push_back("..034..");
	rows.push_back(".04334.");
	rows.push_back("4043443");
	rows.push_back(".14444.");
	rows.push_back("..433..");
	rows.push_back("...4...");
	

	vector<Unit> ourUnits;
	ourUnits.push_back(Unit(0, { 1, 3 }));
	ourUnits.push_back(Unit(1, { 3, 5 }));

	vector<Unit> otherUnits;
	otherUnits.push_back(Unit(0, { 2, 1 }));
	otherUnits.push_back(Unit(1, { 4, 2 }));

	vector<string> legalActions;

	vector<vector<int> > cells(size, vector<int>(size));
	Grid grid(cells, size);
	grid.fillGrid(grid, rows, size);

	Board board(grid, ourUnits, otherUnits, legalActions);


	Action actionBuildOnMe(ACTION_TYPE::MOVEBUILD, 0, DIRECTION::N, DIRECTION::S);


	pair<Action, Board> bestState = Algo::getBest(make_pair(Action(), board));
	EXPECT_EQ(actionBuildOnMe.getAsString(), bestState.first.getAsString());

}


/*
	One unit is blocked... The other one has to do something eve is score is bad
*/
TEST(Evaluation, doTheLessWorstAction) {

	int size = 7;
	vector<string> rows;
	rows.push_back("...0...");
	rows.push_back("..000..");
	rows.push_back(".00000.");
	rows.push_back("1001010");
	rows.push_back(".11044.");
	rows.push_back("..234..");
	rows.push_back("...1...");

	vector<Unit> ourUnits;
	ourUnits.push_back(Unit(0, { 4, 3 }));
	ourUnits.push_back(Unit(1, { 3, 6 }));

	vector<Unit> otherUnits;
	otherUnits.push_back(Unit(0, { 2, 5 }));
	otherUnits.push_back(Unit(1, { 4, 2 }));

	vector<string> legalActions;

	vector<vector<int> > cells(size, vector<int>(size));
	Grid grid(cells, size);
	grid.fillGrid(grid, rows, size);

	Board board(grid, ourUnits, otherUnits, legalActions);


	Action actionBuildOnMe(ACTION_TYPE::MOVEBUILD, 0, DIRECTION::W, DIRECTION::SW);


	pair<Action, Board> bestState = Algo::getBest(make_pair(Action(), board));
	EXPECT_EQ(actionBuildOnMe.getAsString(), bestState.first.getAsString());

}

TEST(Evaluation, moveNW) {

	int size = 6;
	vector<string> rows;
	rows.push_back(".1221.");
	rows.push_back("122243");
	rows.push_back("223444");
	rows.push_back("233434");
	rows.push_back(".3344.");
	rows.push_back("2.43.3");
	

	vector<Unit> ourUnits;
	ourUnits.push_back(Unit(0, { 3, 5 }));
	ourUnits.push_back(Unit(1, { 4, 3 }));

	vector<Unit> otherUnits;
	otherUnits.push_back(Unit(0, { 1, 4 }));
	otherUnits.push_back(Unit(1, { 4, 0 }));

	vector<string> legalActions;

	vector<vector<int> > cells(size, vector<int>(size));
	Grid grid(cells, size);
	grid.fillGrid(grid, rows, size);

	Board board(grid, ourUnits, otherUnits, legalActions);


	Action actionBuildOnMe(ACTION_TYPE::MOVEBUILD, 0, DIRECTION::NW, DIRECTION::N);


	pair<Action, Board> bestState = Algo::getBest(make_pair(Action(), board));
	EXPECT_EQ(actionBuildOnMe.getAsString(), bestState.first.getAsString());

}

