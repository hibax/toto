#include "Grid.h"

const static int HOLE = -1;
const static int CEILING = 4;


Grid::Grid(): cells(), size(0) {}
Grid::Grid(const vector<vector<int> > &cells, int size): cells(cells), size(size) {}

int Grid::getCell(const Cell &p) const { return cells.at(p.row).at(p.column); }
int Grid::getCell(int row, int column) const { return cells.at(row).at(column); }
void Grid::setCell(const Cell &p, const int &i) { cells.at(p.row).at(p.column) = i; }
void Grid::setCell(int row, int column, int height) { cells.at(row).at(column) = height; }
bool Grid::inGrid(int row, int column) const { return (row < size) && (column < size) && row >= 0 && column >= 0; }

bool Grid::isInGame(const Cell & cell) const { 
	const int cellHeight = getCell(cell);
	return cellHeight > HOLE && cellHeight < CEILING;
}

bool Grid::canMove(const Cell & source, const Cell & destination) const {
	if (!inGrid(destination.row, destination.column) || !isInGame(destination)) {
		return false;
	}

	return (getCell(source) + 1) >= getCell(destination);
}

bool Grid::canBuild(const Cell & source, const Cell & destination) const {
	if (!inGrid(destination.row, destination.column)) {
		return false;
	}

	return isInGame(destination);
}

void Grid::fillGrid(Grid & grid, const vector<string> &rows, const int &size) {

	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			const char c = rows.at(y).at(x);
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
