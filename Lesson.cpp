#include "Lesson.h"

int Lesson::apply()
{
    std::string name = exec("ls -A Tmp/ |grep .md");
    
    std::string dir;

    if(name=="")
    {
        return 2;
    }
    name = divyString(name,'\n')[0];
    dir = replace(getClearName(name),'.','/');
    dir = "Notes/"+dir;

    if(exec("test -d \""+dir+ "\" && echo true")=="true\n")
    {
        return 1;
    }

    exec("mkdir -p \""+ dir+"\"");

    std::vector<std::string> name2 = divyString(name,'.');
    if(name2.size()<2)
    {
        std::cerr<<"undefined error occured"<<std::endl;
        return 3;
    }

    exec("mv \"Tmp/"+name + "\" \"Tmp/"+name2[name2.size()-2] + '.' + name2[name2.size()-1]+"\"");

    name = name2[name2.size()-2] + '.' + name2[name2.size()-1];

    std::string all = exec("ls -A Tmp/");
    std::vector<std::string> files = divyString(all,'\n');

    for(int i = 0;i<files.size();i++)
    {
        if(exec("test -f \"Tmp/"+files[i]+"\" && echo true")=="true\n")
        {
            std::cout<<"executing for: "<<files[i]<<std::endl;
            exec("cp \"Tmp/"+files[i]+"\"" + " \"" + dir+"\"");
            exec("rm \"Tmp/"+files[i]+"\"");
        }
    }
    update("new note: "+name);
    return 0;
}
Lesson::Lesson()
{
    std::ifstream file("config.txt",std::ios::binary);
    file>>repo;
    exec("git -C ./Notes/ remote add origin " + repo);
}
void Lesson::update(std::string msg)
{
    exec("git -C ./Notes add -A");
    exec("git -C ./Notes commit -m \"" +  msg+"\"" );
    exec("git -C ./Notes push origin master -f");
    exec("git -C ./Notes status");
    return;
}
void Lesson::upload()
{
    exec("git -C ./Notes pull origin master");
}