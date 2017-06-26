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

static const DIRECTION DIRECTIONS[] = {N, NE, E, SE, S, SW, W, NW};

static string to_str(ACTION_TYPE actionType);
static string to_str(DIRECTION direction);

class Action {
public:
	Action();
	Action(ACTION_TYPE at, int i, DIRECTION dm, DIRECTION db);
	string getAsString() const;
	void setActionType(ACTION_TYPE at);
	void setIndex(int i);
	void setDirMove(DIRECTION dm);
	void setDirBuild(DIRECTION db);
	int getIndex() const;
	DIRECTION getDirMove() const;
	DIRECTION getDirBuild() const;

private:
	ACTION_TYPE actionType;
	int index;
	DIRECTION dirMove;
	DIRECTION dirBuild;
};
