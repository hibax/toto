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
	EXPECT_EQ(-CLOSING_BUILDING_VALUE + 4, Evaluation::score(make_pair(actionCloseBuilding, board.play(actionCloseBuilding))));

	Action actionBlockingEnemy(ACTION_TYPE::MOVEBUILD, 0, DIRECTION::E, DIRECTION::SE);
	EXPECT_EQ(BLOCKING_VALUE + 2, Evaluation::score(make_pair(actionBlockingEnemy, board.play(actionBlockingEnemy))));


	pair<Action, Board> bestState = Algo::getBest(make_pair(Action(), board));
	EXPECT_EQ(actionBlockingEnemy.getAsString(), bestState.first.getAsString());

}

