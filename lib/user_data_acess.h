#ifndef USER_DATA_ACESS_H
#define USER_DATA_ACESS_H
#include <vector>
#include "user.h"

std::vector<user> get_user_data();
void save_user_data(std::vector <user>);
void add_user();
void find_user();
void show_all_user();
void delete_user();

#endif