#include "../public/include/set-entry-exit.hpp"

void setEntryExit(std::vector<std::vector<int>> *maze)
{
    std::random_device seed;
    std::mt19937 random(seed());

    std::uniform_int_distribution<int> randomEntry(1, (*maze).size() - 2);
    std::uniform_int_distribution<int> randomExit(1, (*maze).size() - 2);
    int entry = randomEntry(random);
    int exit = randomExit(random);

    (*maze)[entry][0] = 3;
    (*maze)[entry][1] = 3;
    (*maze)[exit][(*maze)[0].size() - 1] = 3;
    (*maze)[exit][(*maze)[0].size() - 2] = 3;
}