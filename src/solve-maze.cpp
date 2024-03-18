#include "../public/include/solve-maze.hpp"
#include "../public/include/enumerate-cells.hpp"

bool solveMaze(std::vector<std::vector<int>> *maze)
{
    enumerateCells(maze);

    int entryY, currentX = 0, currentY, newX, newY, value;
    std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int i = 0; i < (*maze).size(); ++i)
    {
        if ((*maze)[i][0] != -1)
        {
            entryY = i;
            currentY = entryY;
            value = (*maze)[entryY][0];
            (*maze)[entryY][0] = 2147483646;
            break;
        }
    }

    while (value != 1)
    {
        bool foundPath = false;
        for (std::pair<int, int> dir : directions)
        {
            int nextX = currentX + dir.second;
            int nextY = currentY + dir.first;

            if (nextX >= 0 && nextX < (*maze)[0].size() && nextY >= 0 && nextY < (*maze).size())
            {
                if (value > (*maze)[nextY][nextX] && (*maze)[nextY][nextX] != -1)
                {
                    value = (*maze)[nextY][nextX];
                    newX = nextX;
                    newY = nextY;
                    foundPath = true;
                }
            }
        }

        if (!foundPath)
        {
            return false;
        }

        currentX = newX;
        currentY = newY;
        (*maze)[currentY][currentX] = 2147483646;
    }

    return true;
}
