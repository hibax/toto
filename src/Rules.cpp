#include "Rules.h"
#include "Action.h"
#include "Board.h"
#include <utility>


using namespace std;


namespace GameRules {

	template <>
	vector<pair<Action, Board> > produceNextStates(const pair<Action, Board> & state, bool myTurn) {
		return vector<pair<Action, Board> >();
	}
}

