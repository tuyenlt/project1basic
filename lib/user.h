#ifndef USER_H
#define USER_H
#include <string>

class user
{
    int id;
    std::string name;
    int timeleft; // minute
public:
    user();
    user(int,std::string,int);
    std::string get_name();
    void set_id(int);
    void set_name(std::string);
    void set_timeleft(int);
    int get_id();
    int get_timeleft();
    void add_time(int);
    ~user();
};

#endif