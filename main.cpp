#include <iostream>
#include <string>
#include "lib/user.h"
#include "lib/user_data_acess.h"
#include <windows.h>
#include <vector>


int main() 
{
    int opt = 0; 
    while(opt != 5)
    {
        system("cls");
        std::cout << "whatcha gonna do:" << std::endl;
        std::cout << "1:checking user data" << std::endl;
        std::cout << "2:addding user" << std::endl;
        std::cout << "3:search user" << std::endl;
        std::cout << "4:delete user" << std::endl;
        std::cout << "5:quit" << std::endl;
        std::cout << "enter your option:";
        std::cin >> opt;
        switch (opt)
        {
            case 1:
                show_user(get_user_data());
                opt = 0;
                break;
            case 2:
                add_user();
                opt = 0;
                break;
            case 3:
                search_user();
                opt = 0;
            case 4:
                delete_user();
            case 5:
                break;
            default:
                break;
        }
    }
    return 1;
}