# Pathfinder
This was a C++ project I did for class during September 2017. The purpose was to find the shortest path from start to finish of a map 
read in from a .csv file using Breadth First Search.

When the project was provided to me, the only files in there were the ones
that were created when the project was made, the main.cpp in the "test" folder, and the .csv and .txt files in in the "data" folder. 

I had to code the actual functionality found in the "src" folder as well as the main.cpp in the "app" folder. The way the code works is

* It first takes in a path to a .csv that has
     * "0" to denote walkable space
     * "1" to denote unwalkable spaces or walls
     * "S" to denote the Start position
     * "F" to denote the Finish position
* Running the main.cpp found in the "app" folder creates a PathFinder object and runs the runCMD() function.
* The runCMD() function takes in the path to the .csv file from the user and calls PathFinder's solveFile() function.
* The solveFile() function creates a ReadFile object which is responsible for parsing the data in the .csv file and creating a map of nodes
that will later be used to find a potential path. The function also checks for any errors in the file
* If the file is valid then a WorkOnFile object is created and its solveMaze() function is called.
* The solveMaze() function pushes the node storing "F" (for Finish) to a queue and finds the shortest way to "S" using Breadth First Search.
* If a solution is found then it prints the path from "S" to "F", otherwise it says "ERROR: Couldn't find a path from 'S' to 'F'!"

You will need to install QT to run the code. Extract the .zip file and open the “Pathfinder.pro” file. There are 2 mains. One is in the "test" folder that goes through all the .csv files found in the "data" folder (This can take a bit of setting up to do because you have configure the project properly). The other main is found in the "app" folder and is for when you want to test a .csv file made by you (or use the path for a .csv file found in the "data" folder). The second main is easier to use if you want to test the working of the algorithm.
