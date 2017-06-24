#include <limits.h>
#include "gtest/gtest.h"
#include "Evaluation.h"

using namespace std;

enum ACTION_TYPE
{
	MOVEBUILD, MOVE, BUILD
};

enum DIRECTION
{
	N, NE, E, SE, S, SW, W, NW
};


static string to_string(ACTION_TYPE actionType) {
	switch (actionType) {
	case MOVEBUILD:
		return "MOVE&BUILD";
	case MOVE:
		return "MOVE";
	case BUILD:
		return "BUILD";
	}
}

static string to_string(DIRECTION direction) {
	switch (direction) {
	case N:
		return "N";
	case NE:
		return "NE";
	case E:
		return "E";
	case SE:
		return "SE";
	case S:
		return "S";
	case SW:
		return "SW";
	case W:
		return "W";
	case NW:
		return "NW";
	}
}

class Action {
public:
	Action() {}
	Action(ACTION_TYPE at, int i, DIRECTION dm, DIRECTION db) : actionType(at), index(i), dirMove(dm), dirBuild(db) {}
	string getAsString() const {
		return to_string(actionType) + " " + to_string(index) + " " + to_string(dirMove) + " " + to_string(dirBuild);
	}
	void setActionType(ACTION_TYPE at) { actionType = at; }
	void setIndex(int i) { index = i; }
	void setDirMove(DIRECTION dm) { dirMove = dm; }
	void setDirBuild(DIRECTION db) { dirBuild = db; }

public:
	ACTION_TYPE actionType;
	int index;
	DIRECTION dirMove;
	DIRECTION dirBuild;
};

TEST(Action, firstTest) {
	Action action(ACTION_TYPE::MOVEBUILD, 1, DIRECTION::NE, DIRECTION::S);

	string expectedAction = "MOVE&BUILD 1 NE S";

	EXPECT_EQ(expectedAction, action.getAsString());
}

