#include "gtest/gtest.h"
#include "Algo.h"
#include "Rules.h"

class AlgoTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  virtual void TearDown() {
  }
};



Board a(1);
Board b(2);
Board c(3);
Board d(4);
Board e(5);
Board f(6);
Board g(7);

namespace Evaluation {
	int score(const Board & board) {
		if (board.id == b.id) {
			return 10;
		} else if (board.id == c.id) {
			return -3;
		} else if (board.id == d.id) {
			return 100;
		} else if (board.id == f.id) {
			return 5;
		}

		return 0;
	}
}

Action toAction(int id) {
	return std::move(Action(MOVE, id, N, N));
}

vector<pair<Action, Board> > GameRules::produceNextValidBoards(const Board & board, bool myTurn) { return vector<pair<Action, Board> >(); }

TEST_F(AlgoTest,EvaluateSimplePaths){
    
	Node<Move> root(Move(toAction(1), a));
	Node<Move> left(Move(toAction(2), b));
	Node<Move> right(Move(toAction(3), c));

	root.connect(left);
	root.connect(right);


    EXPECT_EQ(left.getValue().first.getIndex(),evaluatePaths(root).getIndex());
}

TEST_F(AlgoTest,EvaluateMorePaths){
    
	Node<Move> root(Move(toAction(1), a));
	Node<Move> leftRoot(Move(toAction(2), e));
	Node<Move> leftLeft(Move(toAction(3), d));
	Node<Move> leftRight(Move(toAction(4), c));
	Node<Move> rightRoot(Move(toAction(5), g));
	Node<Move> rightLeft(Move(toAction(6), b));
	Node<Move> rightRight(Move(toAction(7), f));

	leftRoot.connect(leftLeft);
	leftRoot.connect(leftRight);
	rightRoot.connect(rightLeft);
	rightRoot.connect(rightRight);
	root.connect(leftRoot);
	root.connect(rightRoot);

    EXPECT_EQ(rightRoot.getValue().first.getIndex(),evaluatePaths(root).getIndex());
}

