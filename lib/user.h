#ifndef USER_H
#define USER_H
#include <string>

class user
{
    int id;
    std::string name;
    int money; // minute
public:
    user();
    user(int,std::string,int);
    std::string get_name();
    void set_id(int);
    void set_name(std::string);
    void set_money(int);
    int get_id();
    int get_money();
    void add_time(int);
    ~user();
};

#endif