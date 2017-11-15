/**/
#ifndef  MAIKAZE_LOCALE_H_
#define MAIKAZE_LOCALE_H_

#include "config.h"

class LocaleFile : public Cfg
{
public:
    LocaleFile(stdstr ifile);
    void SetLocale(stdstr icurlang);
    stdstr curLang;
    
private:
    void Open();

};

#endif // ! MAIKAZE_LOCALE_H_