#include <iostream>
#include <string>
#include "lib/user.h"
#include "lib/user_data_acess.h"
#include <windows.h>



int main()
{
    int opt = 1; 
    while(opt != 3)
    {
        system("cls");
        std::cout << "whatcha gonna do:" << std::endl;
        std::cout << "1:checking user data" << std::endl;
        std::cout << "2:addding user:" << std::endl;
        std::cout << "3:quit" << std::endl;
        std::cout << "enter your option:";
        std::cin >> opt;
        switch (opt)
        {
            case 1:
                show_all_user();
                break;
            case 2:
                add_user();
                break;
            default:
                break;
        }
    }
    return 1;
}