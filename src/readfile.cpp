#include "readfile.h"

ReadFile::ReadFile()
{

}

bool ReadFile::readFile(const std::string &path)
{
    std::ifstream mazeFile;
    mazeFile.open(path);
    mazeFile.seekg(0, std::ios::beg);

    int i = 0;
    int j = 0;

    while (mazeFile.good())
    {
        std::string a;
        std::string b;
        std::getline(mazeFile, a);
        std::istringstream mazeStream(a);

        j = 0;
        while (std::getline(mazeStream, b, ','))
        {
            if (b == "")
            {
                std::cout << std::endl << "ERROR: There is a missing cell in your file!" << std::endl;
                return false;
            }

            Node* temp = new Node(b, i, j, NULL);

            nodeMap[i][j] = *temp;

            if(b == "F" || b == "S")
                findFS(b, i, j);

            delete temp;

            j++;
        }
        i++;
    }

    if(nodeMap.empty())
    {
        std::cout << std::endl << "ERROR: Your file is either empty or the path is invalid!" << std::endl;
        return false;
    }

    mazeFile.close();
    return true;
}

void ReadFile::findFS(std::string b, int x, int y)
{
    if(b == "F")
    {
        F.content = b;
        F.x = x;
        F.y = y;
        F.backNode = NULL;
     }

    if(b == "S")
    {
        S.content = b;
        S.x = x;
        S.y = y;
        S.backNode = NULL;
    }
}
