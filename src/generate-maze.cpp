#include <vector>
#include <random>
#include <stack>
#include <algorithm>
#include "../public/include/generate-maze.hpp"

void generateMaze(std::vector<std::vector<int>>* maze, int* algorithm)
{
    std::random_device seed;
    std::mt19937 random(seed());

    std::uniform_int_distribution<int> distributionX(0, (*maze)[0].size() - 1);
    std::uniform_int_distribution<int> distributionY(0, maze->size() - 1);
    std::stack<std::pair<int, int>> stack;
    std::vector<std::pair<int, int>> directions = {{2, 0}, {0, 2}, {-2, 0}, {0, -2}};
    std::vector<int> order = { 0, 1, 2, 3 };
    int startX, startY;

    do
    {
        startX = distributionX(random);
        startY = distributionY(random);
    } while ((*maze)[startY][startX] == -1);

    (*maze)[startY][startX] = 2;
    stack.push(std::make_pair(startY, startX));

    while (!stack.empty())
    {
        int currentX = stack.top().second;
        int currentY = stack.top().first;
        bool found = false;

        std::shuffle(order.begin(), order.end(), random);
        
        for (int i : order)
        {
            int nextX = currentX + directions[i].second;
            int nextY = currentY + directions[i].first;

            if (nextX >= 0 && nextX < (*maze)[0].size() && nextY >= 0 && nextY < (*maze).size())
            {
                if ((*maze)[nextY][nextX] != 2)
                {
                    (*maze)[nextY][nextX] = 2;
                    (*maze)[currentY + (nextY - currentY) / 2][currentX + (nextX - currentX) / 2] = 2;
                    stack.push(std::make_pair(nextY, nextX));
                    found = true;
                    break;
                }
            }
        }

        if (!found) 
        {
            stack.pop();
        }
    }
}