#include <iostream>
#include <cstring>
#include "Lesson.h"


int main(int argc,char * argv[])
{
    if(argc!=2)
    {
        std::cout<<"USAGE: notatkor [-pull] [-push]"<<std::endl;
        return 1;
    }

    Lesson l1;
    if(!strcmp(argv[1],"-pull"))
    {
        l1.upload();
    }
    else if(!strcmp(argv[1],"-push"))
    {
        l1.apply();
    }
    else
    {
        return 1;
    }
    return 0;
}