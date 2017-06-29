#pragma once

#include <algorithm>
#include <vector>
#include <iostream>
#include "Rules.h"
#include "Evaluation.h"

using namespace std;

namespace Algo
{
	template <typename T>
	T getBest(const T & currentState) {
		Node<T> rootNode(currentState);

		computeTurns(rootNode, true, 0);

		auto state = evaluatePaths(rootNode);


		return state;
	}

}


template <typename T>
void computeTurns(Node<T> & node, bool myTurn, int maxNbTurns)
{
	for (const T & nextState : GameRules::produceNextStates(node.getValue(), myTurn)) {
		Node<T> child(nextState);
		if (maxNbTurns > 0) {
			computeTurns(child, !myTurn, maxNbTurns - 1);
		}
		node.connect(child);
	}
}

int mergeScores(const vector<int> & scores);

template <typename T>
int evaluateSubPaths(const Node<T> & node) {
	vector<int> scores;

	for (Node<T> & child : node.getChildren()) {
		scores.push_back(evaluateSubPaths(child));
	}

	if (scores.empty()) {
		return Evaluation::score(node.getValue());
	} else {
		return mergeScores(scores);
	}
	
} 

template <typename T>
T evaluatePaths(const Node<T> & rootNode) {
	int bestScore = -99999;
	T state = rootNode.getValue();

	for (Node<T> & child : rootNode.getChildren()) {
		const int score = evaluateSubPaths(child);
		if (score >= bestScore) {
			bestScore = score;
			state = child.getValue();
		}
	}

	return state;
} 



