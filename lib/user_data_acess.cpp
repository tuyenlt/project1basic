#include <iostream>
#include <fstream>
#include <string>
#include "user_data_acess.h"
#include <windows.h>
#include <vector>

std::vector <user> get_user_data(){
    std::fstream userData;
    userData.open("lib/user_data.txt");
    std::vector<user> all_user;
    std::string data;
    userData >> data;
    if(data == "") return all_user;
    int num_user = std::stoi(data);
    user temp;
    for(int i=0; i<num_user; i++){
        std::getline(userData,data);     
        temp.set_id(std::stoi(data));

        std::getline(userData,data);       
        temp.set_name(data);       

        std::getline(userData,data);
        temp.set_timeleft(std::stoi(data));
        all_user.push_back(temp);       
    }
    userData.close();
    return all_user;
}

void save_user_data(std::vector <user> all_user)
{
    std::fstream userData;
    userData.open("lib/user_data.txt",std::ios::trunc);
    userData << all_user.size() << std::endl;

    for(int i=0; i<all_user.size(); i++){
        userData << all_user[i].get_id() << std::endl;
        userData << all_user[i].get_name() << std::endl;
        userData << all_user[i].get_timeleft() << std::endl;
    }
    userData.close();
}

void show_all_user(){
    // system("cls");
    std::vector<user> all_user = get_user_data();
    for(int i=0; i<all_user.size();i++){
        std::cout<< "user id:" << all_user[i].get_id() << std::endl;
        std::cout<< "user name:" << all_user[i].get_name() << std::endl;
        std::cout<< "user timeleft" << all_user[i].get_timeleft() <<" minutes"<<std::endl;
    }
    system("pause");
}
void add_user(){
    system("cls");
    std::vector<user> current_user = get_user_data();
    int id = current_user.size() + 1;
    std::string name;
    int timeleft;
    std::cout << "enter user name" <<std:: endl;
    std::cin >> name;
    std::cout << "enter user timeleft: (minutes)"<< std:: endl;
    std::cin >> timeleft;
    user temp(id,name,timeleft);
    current_user.push_back(temp);
    save_user_data(current_user);
    std::cout << "add user success" << std::endl;
    system("pause");
}