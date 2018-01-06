#include "workonfile.h"
#include "readfile.h"
#include "node.h"
#include "point2d.h"

WorkOnFile::WorkOnFile()
{

}

bool WorkOnFile::solveMaze(std::map<int,std::map<int, Node>> &nodeMap, Node F, Node S, std::vector<Point2D> &solution)
{
    q.push(F);

    while (!q.empty() && !complete)
    {

        Node *current = &(q.front());
        current = &(nodeMap[(*current).x][(*current).y]);

        Node* right = &(nodeMap[(*current).x][(*current).y + 1]);   //Because I am going from "F" to "S" I have to reverse
        move(right, current, S, solution);                          //the UP, DOWN, LEFT, RIGHT way of traversing the map.
                                                                    //So, I'm going RIGHT, LEFT, DOWN, UP.
        Node* left = &(nodeMap[(*current).x][(*current).y - 1]);
        move(left, current, S, solution);

        Node* down = &(nodeMap[(*current).x + 1][(*current).y]);
        move(down, current, S, solution);

        Node* up = &(nodeMap[(*current).x - 1][(*current).y]);
        move(up, current, S, solution);

        q.pop();
    }

    if(!complete)
        std::cout << std::endl << "ERROR: Couldn't find a path from 'S' to 'F'!" << std::endl;

    return complete;
}

void WorkOnFile::move(Node* direction, Node* current, Node S, std::vector<Point2D> &solution)
{
    if(isWalkable(*direction) && (*direction).backNode == nullptr)
    {
        (*direction).backNode = current;
        if((*direction).content == "S")
        {
            S.backNode = current;
            std::cout << std::endl << "Found path from S to F!! ";
            outputPath(S, solution);
            complete = true;
        }
        q.push(*direction);
    }
}

bool WorkOnFile::isWalkable(Node adjacent)
{
    if(adjacent.content == "0" || adjacent.content == "S")
        return true;
    else
        return false;
}

void WorkOnFile::outputPath(Node &S, std::vector<Point2D> &solution)
{
    std::cout << "The Path is - " << std::endl << "( " << S.y << ", " << S.x << " )" << std::endl;
    Node* temp = S.backNode;

    Point2D temp2D;
    temp2D.x = S.x;
    temp2D.y = S.y;
    solution.push_back(temp2D);
    while (temp != nullptr)
    {
        std::cout << "( " << temp->y << ", " << temp->x << " )" << std::endl;
        temp2D.x = temp->x;
        temp2D.y = temp->y;
        solution.push_back(temp2D);
        temp = temp->backNode;
    }
}
