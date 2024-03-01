#include <vector>
#include "../public/include/create-grid.hpp"

void createGrid(std::vector<std::vector<int>>* maze)
{
    for (int height = 0; height < (*maze).size(); height++)
    {
        for (int width = 0; width < (*maze)[0].size(); width++)
        {
            if (height % 2 == 0)
            {
                (*maze)[height][width] = -1;
            }
            else
            {
                if (width % 2 == 0)
                {
                    (*maze)[height][width] = -1;
                }
                else
                {
                    (*maze)[height][width] = 0;
                }
            }
        }
    }
}