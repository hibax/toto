#include "Evaluation.h"
#include <utility>
#include "Action.h"
#include "Board.h"


using namespace std;

static const int SCORING_LEVEL = 3;

namespace Evaluation {

	int scoreUnit(const Unit & unit, const Board & board);
	bool isScoring(const Cell & unitPosition, const Grid & grid);
	bool isBlocked(const Cell & unitPosition, const Board & board);
	bool isClosingBuilding(const Cell & buildPosition, const Grid & grid);

	template <>
	int score(const pair<Action, Board> & move) {
		const Board & board = move.second;
		const Action & action = move.first;

		int index = action.getIndex();
		const Cell & myPosition = board.getUnit(index).getPosition();
		const Cell & myDestination = Board::getDestinationCell(myPosition, action.getDirMove());



		const Cell & buildCell = Board::getDestinationCell(myDestination, action.getDirBuild());


		int score = 0;

		//if (isClosingBuilding(buildCell, grid)) {
		//	score -= 1;
		//}

		for (const Unit & unit : board.getOurUnits()) {
			score += scoreUnit(unit, board);
		}
		//for (const Unit & unit : board.getOtherUnits()) {
		//	score -= scoreUnit(unit, grid);
		//}


		return score;
	}

	int scoreUnit(const Unit & unit, const Board & board) {
		if (isBlocked(unit.getPosition(), board)) {
			return -2;
		}

		const Grid & grid = board.getGrid();
		if (isScoring(unit.getPosition(), grid)) {
			return 2;
		}

		return 0;
	}

	bool isClosingBuilding(const Cell & buildPosition, const Grid & grid) {
		return grid.getCell(buildPosition) == SCORING_LEVEL;
	}

	bool isScoring(const Cell & unitPosition, const Grid & grid) {
		return grid.getCell(unitPosition) == SCORING_LEVEL;
	}

	bool isBlocked(const Cell & unitPosition, const Board & board) {
		for (const DIRECTION & direction : DIRECTIONS) {
			const Cell & dst = Board::getDestinationCell(unitPosition, direction);

			if (!board.canMove(unitPosition, dst)) {
				return false;
			}
		}

		return true;
	}

}



