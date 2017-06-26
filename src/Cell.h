#pragma once


struct Cell
{
	int row;
	int column;

	Cell(int row, int column) : row(row), column(column)
	{}
	
	Cell() : row(0), column(0)
	{}
};
