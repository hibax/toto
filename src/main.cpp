// WonderDev.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <assert.h>
#include "gtest/gtest.h"
#include "Action.h"
#include "Grid.h"
#include "Cell.h"
#include "Unit.h"
#include "Board.h"


/*
	main for local test
*/
int main(int argc, char** argv) {

	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS(); 
}