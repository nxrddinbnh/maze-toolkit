#include "../public/include/generate-maze.hpp"
#include "../public/include/add-paths.hpp"
#include "../public/include/set-entry-exit.hpp"
#include "../public/include/dfs-algorithm.hpp"
#include "../public/include/random-algorithm.hpp"

void generateMaze(std::vector<std::vector<int>> *maze, int *algorithm)
{
    std::vector<void (*)(std::vector<std::vector<int>> *)> algorithms;

    algorithms.push_back(dfsAlgorithm);
    algorithms.push_back(randomAlgorithm);

    if ((*algorithm - 1) < algorithms.size())
    {
        algorithms[*algorithm - 1](maze);
    }
    else
    {
        algorithms[algorithms.size() - 1](maze);
    }

    setEntryExit(maze);
    addPaths(maze);
}