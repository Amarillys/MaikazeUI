#include "..\include\core\locale.h"

LocaleFile::LocaleFile(stdstr ifile)
{
    name = ifile;
    Open();
    Load();
    Close();    
}

void LocaleFile::SetLocale(stdstr icurlang)
{
    curLang = icurlang;
}

void LocaleFile::Open()
{
    fp = new ifstream(name);
    if (!fp->is_open())
    {
        delete fp;
        std::ofstream newcfg(name, std::ios::out);
        newcfg << "//Locale file\n//Dont forget the ';' at the end of a line.\n[English]\n";
        newcfg.close();
        fp = new ifstream(name);
    }
}
