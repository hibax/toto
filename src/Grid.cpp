#include "Grid.h"

using namespace std;

Grid::Grid(const vector<vector<int> > &cells, int size): cells(cells), size(size) {}

int Grid::getCell(const Point &p) const { return cells.at(p.x).at(p.y); }
int Grid::getCell(int row, int column) const { return cells.at(row).at(column); }
void Grid::setCell(const Point &p, const int &i) { cells.at(p.x).at(p.y) = i; }
void Grid::setCell(int row, int column, int height) { cells.at(row).at(column) = height; }
bool Grid::inGrid(int row, int column) const { return (row < size) && (column < size); }


void Grid::fillGrid(Grid & grid, const vector<string> &rows, const int &size) {

	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			char c = rows.at(y).at(x);
			int a = int(c);
			switch (c)
			{
			case '.':
				grid.setCell(x, y, -1);
				break;
			case '0':
				grid.setCell(x, y, 0);
				break;
			case '1':
				grid.setCell(x, y, 1);
				break;
			case '2':
				grid.setCell(x, y, 2);
				break;
			case '3':
				grid.setCell(x, y, 3);
				break;
			case '4':
				grid.setCell(x, y, 4);
				break;
			default:
				break;
			}
		}
	}
}
