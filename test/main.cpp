#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "Catch.h"

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#include "pathfinder.h"
#include "point2d.h"

bool pathsAreEqual( const std::vector<Point2D> &path1, const std::vector<Point2D> &path2 )
{
    if( path1.size() < path2.size() )
    {
        fprintf(stdout, "Path is impossibly short\n");
        return false;
    }
    else if( path1.size() > path2.size() )
    {
        fprintf( stderr, "Path is too long\n");
        return false;
    }
    for( auto i = static_cast<size_t>(0); i < path1.size(); i++ )
    {
        if( path1[i] != path2[i] )
        {
            fprintf(stdout, "Step %u is (%2d, %2d) but should be (%2d, %2d)\n", i, path1[i].x, path1[i].y, path2[i].x, path2[i].y);
            return false;
        }
    }
    return true;
}

std::vector<Point2D> solutionFileToVector( const std::string &pathToFile )
{
    std::vector<Point2D> solution;
    std::ifstream mazeFile( pathToFile );
    std::string line;
    while( std::getline( mazeFile, line ) )
    {
        int x = 0;
        int y = 0;
        sscanf(line.c_str(), "(%d, %d)", &y, &x); // This is a hack. Nothing to see here...
        solution.push_back( {x,y} );
    }
    return solution;
}

void matchTestFile( const std::string &sectionName, const std::string &path )
{
    SECTION( sectionName )
    {
        std::string csv = path;
        csv.append(".csv");
        std::string solutionFile = path;
        solutionFile.append("_solution.txt" );
        Pathfinder p;
        std::vector<Point2D> output;
        p.solveFile( csv, output );
        std::vector<Point2D> solution = solutionFileToVector( solutionFile );
        REQUIRE( pathsAreEqual( output, solution ) );
    }
}

TEST_CASE( "Error cases", "[error]" )
{
    Pathfinder p;
    std::vector<Point2D> output;

    SECTION( "Empty file" )
    {
        REQUIRE( p.solveFile( "error_empty.csv", output ) == false );
    }
    SECTION( "Commas but no values" )
    {
        REQUIRE( p.solveFile( "error_empty3x3.csv", output ) == false );
    }
    SECTION( "Missing cell" )
    {
        REQUIRE( p.solveFile( "error_missingcell5x5.csv", output ) == false );
    }
    SECTION( "Invalid file" )
    {
        REQUIRE( p.solveFile( "WumbologicallyUnstable.cs", output ) == false );
    }
    SECTION( "No valid path" )
    {
        REQUIRE( p.solveFile( "nopath9x9.csv", output ) == false );
    }
}

TEST_CASE( "Single path", "[single]" )
{
    matchTestFile( "No middle path spaces", "minimal1x2" );
    matchTestFile( "Simple maze uneven dimensions", "simple4x5_1" );
    matchTestFile( "Simple square maze 1", "simple5x5_1" );
    matchTestFile( "Simple square maze 2", "simple5x5_2" );
    matchTestFile( "Simple square maze 3", "simple5x5_3" );
    matchTestFile( "Big maze", "onepath16x16" );
}

TEST_CASE( "Multiple Paths", "[multiple]" )
{
    matchTestFile( "One shortest path", "twopaths_oneshortest9x9" );
    matchTestFile( "Two paths same length 1", "twopaths_samelength3x3" );
    matchTestFile( "Two paths same length 2", "twopaths_samelength9x9" );
}

