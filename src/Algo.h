#pragma once

#include <algorithm>
#include <vector>

using namespace std;



namespace Algo {
	template <typename T> 
	T getBest(const T & currentState);
}



template <typename T> 
class Node
{
public:
	Node(const T & value) : value(value), children()
	{}

	void connect(const Node<T> & node) {
		children.push_back(move(node));
	}

	std::vector<Node<T>> getChildren() const {
		return children;
	}

	T getValue() const {
		return value;
	}


private:
	T value;
	std::vector<Node<T>> children;
};

template <typename T>
void computeTurns(Node<T> & node, bool myTurn, int maxNbTurns);

template <typename T>
T evaluatePaths(const Node<T> & rootNode);



#include "Algo.hpp"
