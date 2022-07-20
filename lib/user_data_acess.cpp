#include <iostream>
#include <fstream>
#include <string>
#include "user_data_acess.h"
#include <windows.h>
#include <vector>
#include <stdio.h>
#include <iomanip>


std::vector <user> get_user_data(){
    std::fstream userData;
    userData.open("lib/user_data.txt");
    std::vector<user> all_user;
    std::string data;
    getline(userData,data); 
    if(data == "") return all_user;
    int num_user = std::stoi(data);
    user temp;
    for(int i=0; i<num_user; i++){
        std::getline(userData,data);     
        temp.set_id(std::stoi(data));

        std::getline(userData,data);       
        temp.set_name(data);       

        std::getline(userData,data);
        temp.set_money(std::stoi(data));
        all_user.push_back(temp);       
    }
    userData.close();
    return all_user;
}

void save_user_data(std::vector <user> all_user)
{
    std::fstream userData;
    userData.open("lib/user_data.txt",std::ios::trunc | std::ios::out);
    userData << all_user.size() << std::endl;

    for(int i=0; i<all_user.size(); i++){
        userData << all_user[i].get_id() << std::endl;
        userData << all_user[i].get_name() << std::endl;
        userData << all_user[i].get_money() << std::endl;
    }
    std::cout << "pass through" << std::endl;
    userData.close();
}

void show_user(std::vector<user> users){
    system("cls");
    std::cout << "________________________________________________________"<<std::endl;
    std::cout << "|_Id_|"<<"______________Name______________|"<<"____Money ($)___|"<<std::endl;
    for(int i=0; i<users.size();i++){
        std::cout <<"|"<< std::setw(3) << users[i].get_id() << " |"<< std::setw(31) << users[i].get_name() << " |"<< std::setw(15) << users[i].get_money() << " |\n";
    }
    std::cout << "\n\n";
    system("pause");
}
void add_user(){
    system("cls");
    std::vector<user> current_user = get_user_data();
    int id = current_user.size() + 1;
    std::string name;
    std::string money;
    std::cout << "enter user name" <<std:: endl;
    fflush(stdin);
    std::cin.clear();
    std::getline(std::cin,name);
    if(name.length() < 6){
        std::cout << "name must not less than 6 letter" << std::endl;
        std::cout << "add user fail" << std::endl;
        system("pause");
        return ;
    }
    std::cout << "enter user money: ($)"<< std:: endl;
    std::cin >> money;
    if(money.find_first_not_of("0123456789") != std::string::npos) {
        std::cout << "you must enter money by number " << std::endl;
        std::cout << "add user fail" << std::endl;
        std::cin.clear();
        system("pause");
        return ;
    }
    user new_user(id,name,std::stoi(money));
    current_user.push_back(new_user);
    save_user_data(current_user);
    std::cout << "add user success" << std::endl;
    system("pause");
}

std::vector<user> get_user_by_name(){
    std::vector<user> users = get_user_data();
    std::vector<user> result;
    std::string name;
    system("cls");
    std::cout << "enter user name:" << std::endl;
    fflush(stdin);
    std::cin.clear();
    std::getline(std::cin,name);
    for(int i=0; i<users.size(); i++){
        if(users[i].get_name() == name) result.push_back(users[i]);
    }
    return result;
}

std::vector<user> get_users_by_letter(){
    std::vector<user> users = get_user_data();
    std::vector<user> results;
    std::string letter;
    system("cls");
    std::cout << "enter user name:" << std::endl;
    fflush(stdin);
    std::cin.clear();
    std::getline(std::cin,letter);
    for(int i=0;i<users.size();i++)
    {
        if(users[i].get_name().rfind(letter) != std::string::npos) results.push_back(users[i]);
    }
    return results;
}

std::vector<user> get_user_by_ID(){
    std::vector <user> users = get_user_data();
    std::string id = "";
    system("cls");
    std::cout << "enter user's ID :" << std::endl;
    std::vector<user> result;
    std::cin >> id;
    if(id.find_first_not_of("0123456789") != std::string::npos)
    {
        return result;
    }
    else if(stoi(id) < users.size()){
        result.push_back(users[stoi(id)-1]);
    }
    return result;
}

void search_user(){
    int opt = 0;
    while(opt != 4){
        system("cls");
        std::cout << "1:search by name" << std::endl;
        std::cout << "2:search by id" << std::endl;
        std::cout << "3:search by letter" << std::endl;
        std::cout << "4:back" << std::endl;
        std::cout <<"enter option:";
        std::cin >> opt;
        switch (opt)
        {
        case 1:
            show_user(get_user_by_name());
            break;
        case 2:
            show_user(get_user_by_ID());
            opt = 0;
            break;
        case 3:
            show_user(get_users_by_letter());
            opt = 0;
            break;
        case 4:
            break;
        default:
            std::cout <<"invalid option"<< std::endl;
            system("pause");
            break;
        }
    }
}

void delete_user(){
    int opt = 0;
    std::vector<user> users = get_user_data();
    std::vector<user> del_user;
    std::string pass;
    int delete_pos;
    while(opt != 4){
        system("cls");
        std::cout << "1:delete user by name" << std::endl;
        std::cout << "2:delete user by id" << std::endl;
        std::cout << "3:delete all user" << std::endl;
        std::cout << "4:back" <<std::endl;
        std::cout << "enter option: ";
        std::cin >> opt;
        delete_pos = -1;
        switch (opt)
        {
        case 1:
            del_user = get_user_by_name();
            if(del_user.size() > 0) delete_pos = del_user[0].get_id();
            else{
                std::cout << "user not found !" << std::endl;
                system("pause");
            }
            opt = 0;
            break;
        case 2:
            del_user = get_user_by_ID();
            if(del_user.size() > 0) delete_pos = del_user[0].get_id();
            else{
                std::cout << "user not found !" << std::endl;
                system("pause");
            }
            opt = 0;
            break;
        case 3:
            system("cls");
            std::cout << "enter system pass to continue:" << std::endl;
            std::cin >> pass;
            if(pass == "tuyenlt204"){
                std::fstream userData("lib/user_data.txt",std::ios::trunc | std::ios::out);
                userData.close();
                std::cout << "success!" << std::endl;
                system("pause");
            }
            else{
                std::cout << "wrong passs" << std::endl;
                system("pause");
            }
        case 4:
            break;
        default:
            break;
        }
        if(delete_pos != -1){
            system("cls");
            show_user(del_user);
            std::string ans;
            std::cout <<"confirm delete this user ?" << std::endl;
            std::cout <<"y: yes" << std::endl;
            std::cout <<"other letter: no" << std::endl;
            std::cin >> ans;
            if(ans == "y"){
                users.erase(users.begin() + delete_pos - 1,users.begin() + delete_pos);
                for(int i = delete_pos-1; i<users.size(); i++) users[i].set_id(users[i].get_id() - 1);
                save_user_data(users);
                std::cout << "delete user success" <<std::endl;
            }else std::cout << "delete user fail" << std::endl;
            system("pause");
        }
    }
}