
#include <algorithm>
#include <vector>
#include <iostream>
#include "Algo.h"
#include "Rules.h"

using namespace std;

namespace Algo
{
	Action getBest(const Board & board) {
		Node<Move> rootNode(Move(Action(), board));

		nextNodes(rootNode, true, 0);

		auto action = evaluatePaths(rootNode);


		return action;
	}

}



void nextNodes(Node<Move> & node, bool myTurn, int nbTurns)
{
	for (const Move & move : GameRules::produceNextValidBoards(node.getValue().second, myTurn)) {
		Node<Move> child(move);
		if (nbTurns < 3) {
			nextNodes(child, !myTurn, nbTurns + 1);
		}
		node.connect(child);
	}
}

int mergeScores(const vector<int> & scores) {
	auto result = minmax_element(scores.begin(), scores.end());

	return (*result.first < 0) ? *result.first : *result.second;
}


int evaluateSubPaths(const Node<Move> & node) {
	vector<int> scores;

	for (Node<Move> & child : node.getChildren()) {
		scores.push_back(evaluateSubPaths(child));
	}

	if (scores.empty()) {
		return Evaluation::score(node.getValue().second);
	} else {
		return mergeScores(scores);
	}
	
} 

Action evaluatePaths(const Node<Move> & rootNode) {
	int bestScore = 0;
	Action action;

	for (Node<Move> & child : rootNode.getChildren()) {
		const int score = evaluateSubPaths(child);
		if (score > bestScore) {
			bestScore = score;
			action = child.getValue().first;
		}
	}

	return action;
} 



