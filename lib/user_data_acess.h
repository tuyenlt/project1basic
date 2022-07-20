#ifndef USER_DATA_ACESS_H
#define USER_DATA_ACESS_H
#include <vector>
#include "user.h"

std::vector<user> get_user_data();
void save_user_data(std::vector <user>);
void add_user();
void show_user(std::vector<user>);
void delete_user();
void search_user();

#endif