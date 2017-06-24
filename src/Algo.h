
#include <algorithm>
#include <vector>

using namespace std;


struct Action
{
	int i;
public:
	Action(int v) : i(v) {}
	Action() : i(0) {}
};

struct Board
{
	int id;
public:
	Board() : id(0) {}
	Board(int id) : id(id) {}
};

namespace GameRules {

	vector<pair<Action, Board> > produceNextValidBoards(const Board & board, bool myTurn);

}

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




