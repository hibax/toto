#include <limits.h>
#include "gtest/gtest.h"
#include "Grid.h"

using namespace std;

TEST(Grid, testFillGrid) {

	int size = 5;
	vector<string> rows;
	rows.push_back(".000.");
	rows.push_back("00000");
	rows.push_back("04104");
	rows.push_back("03234");
	rows.push_back("00003");


	vector<vector<int> > cells(size, vector<int>(size));
	Grid grid(cells, size);
	grid.fillGrid(grid, rows, size);

	EXPECT_EQ(grid.getCell(1, 2), 4);
	EXPECT_EQ(grid.getCell(4, 1), 0);
	EXPECT_EQ(grid.getCell(4, 0), -1);
	EXPECT_EQ(grid.getCell(2, 3), 2);

	EXPECT_TRUE(grid.inGrid(4, 0));
	EXPECT_TRUE(grid.inGrid(0, 0));
	EXPECT_TRUE(grid.inGrid(4, 4));
	EXPECT_FALSE(grid.inGrid(-1, 4));
	EXPECT_FALSE(grid.inGrid(4, 5));
}

