#include "Rules.h"
#include "Action.h"
#include "Board.h"
#include <utility>


using namespace std;


namespace GameRules {

	template <>
	vector<Board> produceNextStates(const Board & state, bool myTurn) {

		vector<Board> nextStates;
		vector<Action> actions = state.produceAllLegalActions(myTurn);


		for (Action action : actions) {
			nextStates.push_back(state.play(action));
		}

		return nextStates;
	}
}

