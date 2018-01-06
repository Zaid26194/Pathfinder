#ifndef WORKONFILE_H
#define WORKONFILE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

#include "node.h"
#include "point2d.h"

class WorkOnFile // Primary purpose is to find the shortest path and output it
{
public:
    WorkOnFile();
    bool solveMaze(std::map<int,std::map<int, Node>> &nodeMap, Node F, Node S, std::vector<Point2D> &solution);
    void move(Node* direction, Node* current, Node S, std::vector<Point2D> &solution);
    bool isWalkable(Node adjacent);
    void outputPath(Node &S, std::vector<Point2D> &solution);

    std::queue<Node> q;
    bool complete = false;
};

#endif // WORKONFILE_H
