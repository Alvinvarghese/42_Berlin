#ifndef HARL_H
#define HARL_H

#include <iostream>

class Harl
{
public:
    void complain(std::string level);
private:
    void debug();
    void info();
    void warning();
    void error();
};

#endif