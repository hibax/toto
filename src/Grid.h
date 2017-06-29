#pragma once
#include <vector>
#include <string>
#include "Cell.h"
#include "Unit.h"

using namespace std;

class Grid {
public:
	Grid();
	Grid(const vector<vector<int> > &cells, int size);

	int getCell(const Cell &p) const;
	int getCell(int row, int column) const;
	void setCell(const Cell &p, const int &i);
	void setCell(int row, int column, int height);
	bool inGrid(int row, int column) const;
	bool isInGame(const Cell & cell) const;
	bool canMove(const Cell & source, const Cell & destination) const;
	bool canBuild(const Cell & buildCell) const;
	Grid build(const Cell & cell) const;
	void fillGrid(Grid & grid, const vector<string> &rows, const int &size);

private:
	vector<vector<int> > cells;
	int size;
};
