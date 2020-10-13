
#include "Menu.h"
#include <cstdlib>

int main()
{
   
    Menu menu;
    try {
        menu.run();
    }

    catch (std::exception& ex)
    {
        std::cout << ex.what();
        std::cout << "can not read this file!\n";
    }

    return EXIT_SUCCESS;
}
