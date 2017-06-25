
#include <algorithm>
#include <vector>
#include "Action.h"

using namespace std;


struct Board
{
	int id;
public:
	Board() : id(0) {}
	Board(int id) : id(id) {}
};


namespace Evaluation {
	int score(const Board & board);
}

typedef pair<Action, Board> Move;



namespace Algo {
	Action getBest(const Board & board);
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

void nextNodes(Node<Move> & node, bool myTurn, int nbTurns);

Action evaluatePaths(const Node<Move> & rootNode);




