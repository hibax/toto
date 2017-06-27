#include "Rules.h"
#include "Action.h"
#include "Board.h"
#include <utility>


using namespace std;


namespace GameRules {

	template <>
	vector<pair<Action, Board> > produceNextStates(const pair<Action, Board> & state, bool myTurn) {

		vector<pair<Action, Board> > nextStates;

		Board currentBoard = get<1>(state);
		vector<Action> actions = currentBoard.produceAllLegalActions(myTurn);

		for (Action action : actions) {
			nextStates.push_back(make_pair(action, currentBoard.play(action)));
		}

		return nextStates;
	}
}

