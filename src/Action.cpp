#include "Action.h"

namespace Utils {
	static string to_string(ACTION_TYPE actionType) {
		switch (actionType) {
		case MOVEBUILD:
			return "MOVE&BUILD";
		case MOVE:
			return "MOVE";
		case BUILD:
			return "BUILD";
		default:
			return "";
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
		default:
			return "";
		}
	}
}


Action::Action(ACTION_TYPE at, int i, DIRECTION dm, DIRECTION db):
	actionType(at), index(i), dirMove(dm), dirBuild(db) {}

string Action::getAsString() const {
	return Utils::to_string(actionType) + " " + to_string(index) + " " + Utils::to_string(dirMove) + " " + Utils::to_string(dirBuild);
}

void Action::setActionType(ACTION_TYPE at) { actionType = at; }
void Action::setIndex(int i) { index = i; }
void Action::setDirMove(DIRECTION dm) { dirMove = dm; }
void Action::setDirBuild(DIRECTION db) { dirBuild = db; }
int Action::getIndex() const { return index; }
DIRECTION Action::getDirMove() const { return dirMove; }
DIRECTION Action::getDirBuild() const { return dirBuild; }
