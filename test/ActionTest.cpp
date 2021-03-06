#include <limits.h>
#include "gtest/gtest.h"
#include "Action.h"

using namespace std;

TEST(Action, testGetAsString) {
	Action action(ACTION_TYPE::MOVEBUILD, 1, DIRECTION::NE, DIRECTION::S);

	string expectedAction = "MOVE&BUILD 1 NE S";

	EXPECT_EQ(expectedAction, action.getAsString());
}

