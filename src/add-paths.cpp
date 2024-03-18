#include "../public/include/add-paths.hpp"

void addPaths(std::vector<std::vector<int>> *maze)
{
    std::random_device seed;
    std::mt19937 random(seed());

    int totalArea = (*maze).size() * (*maze)[0].size();
    double percentageWalls = 0.1;
    int minWalls = totalArea * percentageWalls;
    int maxWalls = totalArea * (percentageWalls * 1.2);

    std::uniform_int_distribution<int> number(minWalls, maxWalls);
    int walls = number(random);

    for (int i = 0; i < walls; i++)
    {
        int randomX = std::uniform_int_distribution<int>(1, (*maze)[0].size() - 2)(random);
        int randomY = std::uniform_int_distribution<int>(1, (*maze).size() - 2)(random);

        if ((*maze)[randomY][randomX] == -1)
        {
            (*maze)[randomY][randomX] = 2;
        }
    }
}
