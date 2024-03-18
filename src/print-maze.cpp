#include "../public/include/print-maze.hpp"

void printMaze(std::vector<std::vector<int>> *maze)
{
    std::cout << std::endl;

    for (int height = 0; height < (*maze).size(); height++)
    {
        for (int width = 0; width < (*maze)[0].size(); width++)
        {
            if ((*maze)[height][width] == -1)
            {
                std::cout << "# ";
            }
            else if ((*maze)[height][width] == 2147483646)
            {
                std::cout << ". ";
            }
            else
            {
                std::cout << "  ";
            }
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}
