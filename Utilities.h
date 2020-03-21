#ifndef UTILITIES
#define UTILITIES

#define BUFFER_SIZE 256

#include <string>
#include <iostream>
#include <unistd.h>
#include <vector>


std::string exec(std::string command);
std::vector<std::string> divyString(std::string a,char d);
std::string getClearName(std::string a);
std::string replace(std::string a,char c,char d);

#endif /*UTILITIES*/