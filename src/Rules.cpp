#include "Rules.h"
#include "Action.h"
#include "Board.h"
#include <utility>


using namespace std;


namespace GameRules {

	template <>
	vector<pair<Action, Board> > produceNextStates(const pair<Action, Board> & state, bool myTurn) {

		const Board & board = state.second;
		vector<pair<Action, Board> > nextStates;
		auto actions = board.produceAllLegalActions(myTurn);


		for (const Action & action : actions) {
			nextStates.push_back(make_pair(action, board.play(action)));
		}

		return nextStates;
	}
}

