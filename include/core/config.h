/*
v0.00 Maikaze Simple Configer
*/
#define _CRT_SECURE_NO_WARNINGS
#include "base.h"

class Cfg
{
public:
    Cfg();
    Cfg(stdstr iname);
    ~Cfg();

    /*When this class was created, Open() will be automatically called.*/
    void Open();
    void Close();
    void SetRoot(stdstr iroot);

    stdstr ReadString(stdstr ikey);
    int ReadInt(stdstr ikey);
    float ReadFloat(stdstr ikey);
    Color ReadColor(stdstr ikey);

private:
    stdstr name = "maikaze.cfg";
    stdstr root = "main";
    bool broken = false;
    FILE* fp = nullptr;
};
