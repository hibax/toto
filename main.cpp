// WonderDev.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


struct Point
{
	int x;
	int y;
};


string generateAction(const int& counter, const vector<string> &legalActions) {
	string action = "";

	if (counter % 2 == 0) {
		action = "MOVE&BUILD 0 N S";
	}
	else {
		action = "MOVE&BUILD 0 S N";
	}

	if (std::find(legalActions.begin(), legalActions.end(), action) == legalActions.end())
	{
		action = legalActions.at(0);
	}
}



int main()
{
	int size;
	cin >> size; cin.ignore();
	int unitsPerPlayer;
	cin >> unitsPerPlayer; cin.ignore();

	int counter = 0;

	// game loop
	while (1) {
		for (int i = 0; i < size; i++) {
			string row;
			cin >> row; cin.ignore();
		}

		for (int i = 0; i < unitsPerPlayer; i++) {
			Point pos;
			cin >> pos.x >> pos.y; cin.ignore();
		}
		for (int i = 0; i < unitsPerPlayer; i++) {
			int otherX;
			int otherY;
			cin >> otherX >> otherY; cin.ignore();
		}

		vector<string> legalActions;

		int legalActionsSize;
		cin >> legalActionsSize; cin.ignore();
		for (int i = 0; i < legalActionsSize; i++) {
			string type;
			int index;
			string dir1;
			string dir2;
			cin >> type >> index >> dir1 >> dir2; cin.ignore();
			legalActions.push_back(type + " " + to_string(index) + " " + dir1 + " " + dir2);
		}

		// Write an action using cout. DON'T FORGET THE "<< endl"
		// To debug: cerr << "Debug messages..." << endl;
		counter++;
		cout << generateAction(counter, legalActions) << endl;

	}
}