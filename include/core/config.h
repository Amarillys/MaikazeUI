/*
v0.00 Maikaze Simple Configer
*/
#ifndef MAIKAZE_CONFIG_H_
#define MAIKAZE_CONFIG_H_
#define _CRT_SECURE_NO_WARNINGS
#include "base.h"
#include <fstream>
#include <string>
#include <map>
#include <vector>

using std::map;
using std::ifstream;
using std::getline;

class Cfg
{
public:
    Cfg();
    Cfg(stdstr iname);
    ~Cfg();

    /*When this class was created, Open() will be automatically called.*/
    void SetRoot(stdstr iroot);
    
    /*utf-8 only*/
    stdstr ReadString(stdstr ikey);
    int ReadInt(stdstr ikey);
    float ReadFloat(stdstr ikey);
    Color ReadColor(stdstr ikey);

    stdstr ReadString(stdstr iroot, stdstr ikey);
    int ReadInt(stdstr iroot, stdstr ikey);
    float ReadFloat(stdstr iroot, stdstr ikey);
    Color ReadColor(stdstr iroot, stdstr ikey);

protected:

    ifstream* fp = nullptr;
    stdstr name = "maikaze.cfg";
    stdstr root = "main";

    virtual void Open();
    void Load();
    void Close();
    
    map<stdstr, map<stdstr, stdstr>> content;
};

#endif