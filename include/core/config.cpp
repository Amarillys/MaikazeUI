#include "config.h"

Cfg::Cfg()
{
    Open();
}

Cfg::Cfg(stdstr iname)
{
    name = iname;
    Open();
}

Cfg::~Cfg()
{
    Close();
}

void Cfg::Open()
{
    fp = fopen(name.c_str(), "r");
    if (fp != nullptr)
        return;

    printf("failed to load the config file.\n");
    broken = true;
}

void Cfg::Close()
{
    if (fp != nullptr)
        fclose(fp);
}

void Cfg::SetRoot(stdstr iroot)
{
    root = iroot;
}

stdstr Cfg::ReadString(stdstr ikey)
{
    return stdstr();
}

int Cfg::ReadInt(stdstr ikey)
{
    return 0;
}

float Cfg::ReadFloat(stdstr ikey)
{
    return 0.0f;
}

Color Cfg::ReadColor(stdstr ikey)
{
    return Color();
}
