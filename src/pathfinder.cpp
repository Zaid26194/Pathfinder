#include "pathfinder.h"
#include "readfile.h"
#include "workonfile.h"

Pathfinder::Pathfinder()
{

}

void Pathfinder::runCMD()
{
    std::cout << "Input the file path - " << std::endl;
    std::string tempPath;
    std::getline(std::cin, tempPath);
    solveFile(tempPath, solution);
}

bool Pathfinder::solveFile( const std::string &path, std::vector<Point2D> &solution )
{
    ReadFile r;
    perfect = r.readFile(path);

    if (perfect == true)
    {
        WorkOnFile w;
        perfect = w.solveMaze(r.nodeMap, r.F, r.S, solution);
    }

    if(perfect == false)
        return false;

    return true;
}
