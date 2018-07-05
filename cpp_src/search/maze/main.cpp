#include "Maze.h"

int main()
{
    std::vector<std::vector<int>> vec{
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0}};
    Maze maze(vec);
    maze.display();
    maze.solveByBFS();
    //maze.solveByDFS();
}
