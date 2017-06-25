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



typedef pair<int, int> State;


State a(1, 1);
State b(2, 2);
State c(3, 3);
State d(4, 4);
State e(5, 5);
State f(6, 6);
State g(7, 7);


namespace Evaluation {
	template<>
	int score(const State & state) {
		if (state.second == b.second) {
			return 10;
		} else if (state.second == c.second) {
			return -3;
		} else if (state.second == d.second) {
			return 100;
		} else if (state.second == f.second) {
			return 5;
		}

		return 0;
	}
}


template <>
vector<State> GameRules::produceNextStates(const State & state, bool myTurn) {
	if (state.second == a.second) {
		return {e, g};
	} else if (state.second == e.second) {
		return {d, c};
	} else if (state.second == g.second) {
		return {b, f};
	}

	return vector<State>();


}

TEST_F(AlgoTest,EvaluateSimplePaths){
    
	Node<State> root(a);
	Node<State> left(b);
	Node<State> right(c);

	root.connect(left);
	root.connect(right);


    EXPECT_EQ(left.getValue().first,evaluatePaths(root).first);
}

TEST_F(AlgoTest,EvaluateMorePaths){
    
	Node<State> root(a);
	Node<State> leftRoot(e);
	Node<State> leftLeft(d);
	Node<State> leftRight(c);
	Node<State> rightRoot(g);
	Node<State> rightLeft(b);
	Node<State> rightRight(f);

	leftRoot.connect(leftLeft);
	leftRoot.connect(leftRight);
	rightRoot.connect(rightLeft);
	rightRoot.connect(rightRight);
	root.connect(leftRoot);
	root.connect(rightRoot);

    EXPECT_EQ(rightRoot.getValue().first,evaluatePaths(root).first);
}

TEST_F(AlgoTest, ComuteMoreTurns) {
	Node<State> root(a);

	computeTurns(root, true, 1);

	EXPECT_EQ(2, root.getChildren()[0].getChildren().size());
	EXPECT_EQ(2, root.getChildren()[1].getChildren().size());
}

