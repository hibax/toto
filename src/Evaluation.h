#pragma once


static const int CELL_SCORING_LEVEL = 3;
static const int CELL_LAST_LEVEL = 4;
static const int SCORING_VALUE = 5;
static const int BLOCKING_VALUE = 50;
static const int CLOSING_BUILDING_VALUE = 10;



namespace Evaluation {
	template <typename T>
	int score(const T & state);
}
