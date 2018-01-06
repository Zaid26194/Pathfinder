#ifndef READFILE_H
#define READFILE_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>

#include "node.h"

class ReadFile //Primary purpose is to read and properly store the information from the files
{
public:
    ReadFile();
    bool readFile(const std::string &path);
    void findFS(std::string b, int x, int y);
    std::map<int,std::map<int, Node>> nodeMap;
    Node F;
    Node S;
};

#endif // READFILE_H
