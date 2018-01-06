#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

class Node //Node class for use to store info and backward pointers
{
public:
    Node();
    Node(std::string s, int x, int y, Node* backpointer);
    std::string content;
    int x, y;
    Node* backNode;

};

#endif // NODE_H
