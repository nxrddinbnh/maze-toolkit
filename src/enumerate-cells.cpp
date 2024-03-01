#include <vector>
#include <queue>
#include "../public/include/enumerate-cells.hpp"

void enumerateCells(std::vector<std::vector<int>>* maze)
{
    std::queue<std::pair<int, int>> queue;
    std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    std::vector<std::vector<bool>> isVisited((*maze).size(), std::vector<bool>((*maze)[0].size(), false));

    for (int i = 0; i < (*maze).size(); ++i)
    {
        if ((*maze)[i][(*maze)[0].size() - 1] == 3)
        {
            (*maze)[i][(*maze)[0].size() - 1] = 1;
            isVisited[i][(*maze)[0].size() - 1] = true;
            queue.push({i, (*maze)[0].size() - 1});
            break;
        }
    }

    while (!queue.empty())
    {
        int currentX = queue.front().second;
        int currentY = queue.front().first;
        queue.pop();

        for (std::pair<int, int> dir : directions)
        {
            int nextX = currentX + dir.second;
            int nextY = currentY + dir.first;

            if (nextX >= 0 && nextX < (*maze)[0].size() && nextY >= 0 && nextY < (*maze).size())
            {
                if ((*maze)[nextY][nextX] != -1 && !isVisited[nextY][nextX])
                {
                    (*maze)[nextY][nextX] = (*maze)[currentY][currentX] + 1;
                    isVisited[nextY][nextX] = true;
                    queue.push({nextY, nextX});
                }
            }
        }
    }
}