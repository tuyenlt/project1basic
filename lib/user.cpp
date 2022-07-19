#include "user.h"
#include <iostream>

user :: user(){
    this -> name = "user_number";
    this -> timeleft = 0;
}

user :: user(int id,std::string name,int timeleft){
    this -> name = name;
    this -> id = id;
    this -> timeleft = timeleft;
}

void user :: set_id(int id){
    this -> id = id;
}

void user :: set_name(std::string name){
    this -> name = name;
}

void user :: set_timeleft(int timeleft){
    this -> timeleft = timeleft;
}

std::string user :: get_name(){
    return this -> name;
}

int user :: get_id(){
    return this -> id;
}

int user :: get_timeleft(){
    return this -> timeleft;
}

void user :: add_time(int time){
    this -> timeleft += time;
}

user :: ~user(){

};