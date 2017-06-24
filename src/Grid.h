#pragma once
#include <vector>
#include "Point.h"

using namespace std;

class Grid {
public:
	Grid(const vector<vector<int> > &cells, int size);

	int getCell(const Point &p) const;
	int getCell(int row, int column) const;
	void setCell(const Point &p, const int &i);
	void setCell(int row, int column, int height);
	bool inGrid(int row, int column) const;
	void fillGrid(Grid & grid, const vector<string> &rows, const int &size);

private:
	vector<vector<int> > cells;
	int size;
};