#pragma once


struct Cell
{
	int column;
	int row;

	Cell(int column, int row) : column(column), row(row)
	{}
	
	Cell() : column(0), row(0)
	{}
};
