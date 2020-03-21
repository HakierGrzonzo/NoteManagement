#ifndef LESSON
#define LESSON

#include "Utilities.h"
#include <iostream>
#include <fstream>

class Lesson
{
    std::string repo;
    public:
    Lesson();
    
    int apply();

    void update(std::string msg);
    void upload();
};

#endif /*LESSON*/