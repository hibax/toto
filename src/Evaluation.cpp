#include "Evaluation.h"
#include <utility>
#include "Action.h"
#include "Board.h"


using namespace std;

static const int SCORING_LEVEL = 3;

namespace Evaluation {

	int scoreUnit(const Unit & unit, const Grid & grid);
	bool isScoring(const Cell & unitPosition, const Grid & grid);
	bool isBlocked(const Cell & unitPosition, const Grid & grid);

	template <>
	int score(const pair<Action, Board> & move) {
		const Board & board = move.second;

		const Grid & grid = board.getGrid();
		int score = 0;
		for (const Unit & unit : board.getOurUnits()) {
			score += scoreUnit(unit, grid);
		}
		for (const Unit & unit : board.getOtherUnits()) {
			score -= scoreUnit(unit, grid);
		}


		return score;
	}

	int scoreUnit(const Unit & unit, const Grid & grid) {
		if (isBlocked(unit.getPosition(), grid)) {
			return -2;
		}

		if (isScoring(unit.getPosition(), grid)) {
			return 1;
		}

		return 0;
	}

	bool isScoring(const Cell & unitPosition, const Grid & grid) {
		return grid.getCell(unitPosition) == SCORING_LEVEL;
	}

	bool isBlocked(const Cell & unitPosition, const Grid & grid) {
		for (const DIRECTION & direction : DIRECTIONS) {
			const Cell & dst = Board::getDestinationCell(unitPosition, direction);

			if (!grid.canMove(unitPosition, dst)) {
				return false;
			}
		}

		return true;
	}

}



