#include "Evaluation.h"
#include <utility>
#include "Action.h"
#include "Board.h"
#include "Utils.h"


using namespace std;


namespace Evaluation {

	int scoreUnit(const Unit & unit, const Cell & buildPosition, const Board & board);
	bool isScoring(const Cell & unitPosition, const Grid & grid);
	bool isBlocked(const Cell & unitPosition, const Board & board);
	bool isClosingBuilding(const Cell & buildPosition, const Grid & grid);

	template <>
	int score(const pair<Action, Board> & move) {
		const Board & board = move.second;
		const Action & action = move.first;
		const Grid & grid = board.getGrid();

		int index = action.getIndex();
		const Cell & myPosition = board.getUnit(index).getPosition();
		const Cell & buildCell = Board::getDestinationCell(myPosition, action.getDirBuild());


		int score = 0;

		score += grid.getCell(myPosition);

		if (abs(board.getGrid().getCell(myPosition) - board.getGrid().getCell(buildCell)) > 1) {
			score -= grid.getCell(buildCell);
		}
		else {
			score += grid.getCell(buildCell);
		}

		if (isClosingBuilding(buildCell, grid)) {
			score -= CLOSING_BUILDING_VALUE;
		}

		if (isScoring(myPosition, grid)) {
			score += SCORING_VALUE;
		}

		for (const Unit & unit : board.getOurUnits()) {
			score += scoreUnit(unit, buildCell, board);
		}
		for (const Unit & unit : board.getOtherUnits()) {
			score -= scoreUnit(unit, buildCell, board);
		}


		return score;
	}

	int scoreUnit(const Unit & unit, const Cell & buildPosition, const Board & board) {
		int score = 0;

		if (board.getGrid().getCell(unit.getPosition()) >= 2 && Utils::distance(unit.getPosition(), buildPosition) == 1) {
			// If we build a scoring cell
			if (board.getGrid().getCell(buildPosition) == CELL_SCORING_LEVEL) {
				score += SCORING_VALUE;
			}
			// If we close a cell
			if (board.getGrid().getCell(buildPosition) == CELL_LAST_LEVEL) {
				score -= SCORING_VALUE;
			}
		}

		if (isBlocked(unit.getPosition(), board)) {
			score -= BLOCKING_VALUE;
		}
		return score;
	}

	bool isClosingBuilding(const Cell & buildPosition, const Grid & grid) {
		return grid.getCell(buildPosition) == CELL_LAST_LEVEL;
	}

	bool isScoring(const Cell & unitPosition, const Grid & grid) {
		return grid.getCell(unitPosition) == CELL_SCORING_LEVEL;
	}

	bool isBlocked(const Cell & unitPosition, const Board & board) {
		for (const DIRECTION & direction : DIRECTIONS) {
			const Cell & dst = Board::getDestinationCell(unitPosition, direction);

			if (board.getGrid().canMove(unitPosition, dst, board.getOurUnits(), board.getOtherUnits())) {
				return false;
			}
		}

		return true;
	}

}



