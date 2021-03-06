#include "Grid.h"

const static int HOLE = -1;
const static int CEILING = 4;


Grid::Grid(): cells(), size(0) {}
Grid::Grid(const vector<vector<int> > &cells, int size): cells(cells), size(size) {}

int Grid::getCell(const Cell &p) const { return cells.at(p.column).at(p.row); }
int Grid::getCell(int column, int row) const { return cells.at(column).at(row); }
void Grid::setCell(const Cell &p, const int &i) { cells.at(p.column).at(p.row) = i; }
void Grid::setCell(int column, int row, int height) { cells.at(column).at(row) = height; }
bool Grid::inGrid(int column, int row) const { return (row < size) && (column < size) && row >= 0 && column >= 0; }

bool Grid::isInGame(const Cell & cell) const { 
	const int cellHeight = getCell(cell);
	return cellHeight > HOLE && cellHeight < CEILING;
}

bool Grid::canMove(const Cell & source, const Cell & destination) const {
	if (!inGrid(destination.column, destination.row) || !isInGame(destination)) {
		return false;
	}

	return (getCell(source) + 1) >= getCell(destination);
}

bool Grid::canBuild(const Cell & buildCell) const {
	if (!inGrid(buildCell.column, buildCell.row)) {
		return false;
	}

	return isInGame(buildCell);
}

Grid Grid::build(const Cell & cell) const {
	Grid grid(cells, size);
	grid.setCell(cell, grid.getCell(cell) + 1);

	return grid;
}

void Grid::fillGrid(Grid & grid, const vector<string> &rows, const int &size) {

	for (int row = 0; row < size; row++) {
		for (int column = 0; column < size; column++) {
			const char c = rows.at(row).at(column);
			switch (c)
			{
			case '.':
				grid.setCell(column, row, -1);
				break;
			case '0':
				grid.setCell(column, row, 0);
				break;
			case '1':
				grid.setCell(column, row, 1);
				break;
			case '2':
				grid.setCell(column, row, 2);
				break;
			case '3':
				grid.setCell(column, row, 3);
				break;
			case '4':
				grid.setCell(column, row, 4);
				break;
			default:
				break;
			}
		}
	}
}
