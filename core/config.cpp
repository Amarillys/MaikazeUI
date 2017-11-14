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
    fp.open(name, std::ios::in);
    if (fp.is_open())
        return;

    printf("failed to load the config file.\n");
    broken = true;
}

void Cfg::Load()
{
    if (broken)
        return;

    /*while (!fp.eof())
    {
        fp.getline();
    }*/

}

void Cfg::Close()
{
    /*if (fp != nullptr)
        fclose(fp);*/
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
    return stdstr();
}

int Cfg::ReadInt(stdstr iroot, stdstr ikey)
{
    return 0;
}

float Cfg::ReadFloat(stdstr iroot, stdstr ikey)
{
    return 0.0f;
}

Color Cfg::ReadColor(stdstr iroot, stdstr ikey)
{
    return Color();
}
