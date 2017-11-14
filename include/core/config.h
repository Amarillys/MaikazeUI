/*
v0.00 Maikaze Simple Configer
*/
#define _CRT_SECURE_NO_WARNINGS
#include "base.h"
#include <fstream>
#include <map>

using std::map;
using std::fstream;

class Cfg
{
public:
    Cfg();
    Cfg(stdstr iname);
    ~Cfg();

    /*When this class was created, Open() will be automatically called.*/
    void SetRoot(stdstr iroot);

    stdstr ReadString(stdstr ikey);
    int ReadInt(stdstr ikey);
    float ReadFloat(stdstr ikey);
    Color ReadColor(stdstr ikey);

    stdstr ReadString(stdstr iroot, stdstr ikey);
    int ReadInt(stdstr iroot, stdstr ikey);
    float ReadFloat(stdstr iroot, stdstr ikey);
    Color ReadColor(stdstr iroot, stdstr ikey);

private:
    void Open();
    void Load();
    void Close();

    stdstr name = "maikaze.cfg";
    stdstr root = "main";
    bool broken = false;
    fstream fp;

    map<stdstr, map<stdstr, stdstr>> content;
};
