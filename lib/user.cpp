#include "user.h"
#include <iostream>

user :: user(){
    this -> name = "user_number";
    this -> money = 0;
}

user :: user(int id,std::string name,int money){
    this -> name = name;
    this -> id = id;
    this -> money = money;
}

void user :: set_id(int id){
    this -> id = id;
}

void user :: set_name(std::string name){
    this -> name = name;
}

void user :: set_money(int money){
    this -> money = money;
}

std::string user :: get_name(){
    return this -> name;
}

int user :: get_id(){
    return this -> id;
}

int user :: get_money(){
    return this -> money;
}

void user :: add_time(int time){
    this -> money += time;
}

user :: ~user(){

};