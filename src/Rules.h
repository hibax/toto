#pragma once
#include <vector>


namespace GameRules {

	template <typename T>
	std::vector<T> produceNextStates(const T & state, bool myTurn);
}

