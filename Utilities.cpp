#include "Utilities.h"

std::string exec(std::string command)
{
    std::string data;
    FILE * stream;
    stream = popen(command.c_str(),"r");
    if(!stream)
    {
        return "error occured in: exec";
    }
    char * buff = new char[BUFFER_SIZE];
    while(!feof(stream))
    {
        if(fgets(buff,BUFFER_SIZE,stream)!=NULL)
        {
            data+=buff;
        }
    }
    return data;
}

std::vector<std::string> divyString(std::string a, char d)
{
    std::vector<std::string> result;
    std::string buff;
    for(int i = 0;i<a.size();i++)
    {
        if(a[i]==d)
        {
            result.push_back(buff);
            buff.clear();
            continue;
        }
        buff+=a[i];
    }
    if(buff!="")
    {
        result.push_back(buff);
    }
    return result;
}
std::string getClearName(std::string a)
{
    for(;a.size()>0&&a[a.size()-1]!='.';)
    {

        a.erase(a.end()-1,a.end());
    }
    a.erase(a.end()-1,a.end());
    return a;
}
std::string replace(std::string a,char c,char d)
{
    for(int i = 0;i<a.size();i++)
    {
        if(a[i]==c){a[i]=d;}
    }
    return a;
}