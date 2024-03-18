#include <vector>
#include <random>
#include "../../public/include/random-algorithm.hpp"
#include "../../public/include/dfs-algorithm.hpp"

void randomAlgorithm(std::vector<std::vector<int>> *maze)
{
    std::random_device seed;
    std::mt19937 random(seed());

    std::vector<void (*)(std::vector<std::vector<int>> *)> algorithms =
        {
            dfsAlgorithm
        };

    std::uniform_int_distribution<int> chooseAlgo(0, algorithms.size() - 1);
    int algoIndex = chooseAlgo(random);

    algorithms[algoIndex](maze);
}