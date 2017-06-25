#include "Evaluation.h"
#include <utility>
#include "Action.h"
#include "Board.h"


using namespace std;

namespace Evaluation {

	template <>
	int score(const pair<Action, Board> & move) {
		return 2;
	}



}



