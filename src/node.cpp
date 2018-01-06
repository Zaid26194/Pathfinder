#include "node.h"

Node::Node()
{

}

Node::Node(std::string s = "", int x = 0, int y = 0, Node* backpointer = NULL): content(s), x(x), y(y), backNode(backpointer)
{

}
