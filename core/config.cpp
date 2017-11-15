#include "../include/core/config.h"

Cfg::Cfg()
{
    Open();
    Load();
    Close();
}

Cfg::Cfg(stdstr iname)
{
    name = iname;
    Open();
    Load();
    Close();
}

Cfg::~Cfg()
{
    Close();
}

void Cfg::Open()
{
    fp = new ifstream(name);
    if (!fp->is_open())
    {
        delete fp;
        std::ofstream newcfg(name, std::ios::out);
        newcfg << "//Config file\n//Dont forget the ';' at the end of a line.\n[Main]\n//Theme has two kind\n//Dark and White\nTheme = Dark;";
        newcfg.close();
        fp = new ifstream(name);
    }
}

void Cfg::Load()
{
    stdstr line;
    stdstr root = "";
    int pos;
    map<stdstr, stdstr> group;
    while (getline(*fp, line))
    {
        pos = 0;
        printf("line : %s\n", line.c_str());

        if (line.size() < 1)
            continue;
        
        if (line[0] == '/')
            continue;

        if (line[0] == '[')
        {
            //meet the new root, save the old root to the map
            if (root != "")
                content[root] = group;
            group.clear();


            //set to new root
            char* tmpstr = new char[line.size() - 1]{ 0 };
            for (; pos < line.size() - 2; ++pos)
                tmpstr[pos] = line[pos + 1];
            root = stdstr(tmpstr);
            delete tmpstr;
            continue;
        }

        char* key = new char[line.size() - 1]{ 0 };
        for (; line[pos] != ' ' && line[pos] != '='; ++pos)
            key[pos] = line[pos];
        
        char* value = new char[line.size() - 1]{ 0 };
        for (int i = 0; line[pos] != ';'; ++pos)
        {
            if (line[pos] == ' ' || line[pos] == '=')
                continue;
            value[i++] = line[pos];
        }

        group[stdstr(key)] = stdstr(value);
        delete key;
        delete value;
    }
    content[root] = group;
    group.clear();
}

void Cfg::Close()
{
    fp->close();
    delete fp;
}

void Cfg::SetRoot(stdstr iroot)
{
    root = iroot;
}

stdstr Cfg::ReadString(stdstr ikey)
{
    return ReadString(root, ikey);
}

int Cfg::ReadInt(stdstr ikey)
{
    return ReadInt(root, ikey);
}

float Cfg::ReadFloat(stdstr ikey)
{
    return ReadFloat(root, ikey);
}

Color Cfg::ReadColor(stdstr ikey)
{
    return ReadColor(root, ikey);
}

stdstr Cfg::ReadString(stdstr iroot, stdstr ikey)
{
    return content[iroot][ikey];
}

int Cfg::ReadInt(stdstr iroot, stdstr ikey)
{
    return atoi(content[iroot][ikey].c_str());
}

float Cfg::ReadFloat(stdstr iroot, stdstr ikey)
{
    return atof(content[iroot][ikey].c_str());
}

Color Cfg::ReadColor(stdstr iroot, stdstr ikey)
{
    return Str2Clr(content[iroot][ikey]);
}
