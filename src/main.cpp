#include <iostream>
#include <vector>
#include "../public/include/create-grid.hpp"
#include "../public/include/generate-maze.hpp"
#include "../public/include/add-paths.hpp"
#include "../public/include/set-entry-exit.hpp"
#include "../public/include/enumerate-cells.hpp"
#include "../public/include/solve-maze.hpp"
#include "../public/include/print-maze.hpp"

int main()
{
    int algorithm;
    int width, height;
    char answer;

    std::cout << "Welcome to 'maze-toolkit', where mazes come to life! Developed by nxrddinbnh" << std::endl;
    std::cout << "Let's kick off this maze adventure, shall we?" << std::endl << std::endl;

    std::cout << "Choose your maze generation algorithm:" << std::endl;
    std::cout << "(1) Depth-First Search (DFS)" << std::endl;
    std::cout << "(2) Random Selection" << std::endl;
    std::cin >> algorithm;

    std::cout << "Excellent! Now, let's set the dimensions of your maze (width height): " << std::endl;

    do 
    {
        std::cin >> width >> height;
        
        if (!(width % 2) || !(height % 2))
        {
            std::cout << "Whoopsie! I'm only into odd numbers. Evens are just too perfect for me. Try again with odd dimensions." << std::endl;
        }
    } while (!(width % 2) || !(height % 2));

    std::vector<std::vector<int>> maze(height, std::vector<int>(width, 0));
    std::cout << "Voila! Behold your maze masterpiece!" << std::endl << std::endl;

    createGrid(&maze);
    generateMaze(&maze, &algorithm);
    addPaths(&maze);
    setEntryExit(&maze);
    printMaze(&maze);

    std::cout << std::endl << "Would you like me to solve the maze for you? (y / n)" << std::endl;
    std::cin >> answer;

    if (answer == 'y') 
    {
        std::cout << "Alrighty then! Let's find the way out." << std::endl;
        enumerateCells(&maze);
        solveMaze(&maze);
        printMaze(&maze);
    }
    else
    {
        std::cout << "Whenever you're ready, boss! Just hit [m] and I'll sort it out in a jiffy." << std::endl;
        std::cin >> answer;

        if (answer == 'm' || answer == 'M')
        {
            enumerateCells(&maze);
            solveMaze(&maze);
            printMaze(&maze);
        }
    }

    return 0;
}