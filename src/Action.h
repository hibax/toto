#pragma once
#include <string>

using namespace std;

enum ACTION_TYPE
{
	MOVEBUILD, MOVE, BUILD
};

enum DIRECTION
{
	N, NE, E, SE, S, SW, W, NW
};


static string to_string(ACTION_TYPE actionType);
static string to_string(DIRECTION direction);

class Action {
public:
	Action();
	Action(ACTION_TYPE at, int i, DIRECTION dm, DIRECTION db);
	string getAsString() const;
	void setActionType(ACTION_TYPE at);
	void setIndex(int i);
	void setDirMove(DIRECTION dm);
	void setDirBuild(DIRECTION db);

private:
	ACTION_TYPE actionType;
	int index;
	DIRECTION dirMove;
	DIRECTION dirBuild;
};

