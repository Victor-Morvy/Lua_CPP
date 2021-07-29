#ifndef LUASCRIPTPARSER_H
#define LUASCRIPTPARSER_H

#include <iostream>
#include <string>
#include <map>

extern "C"
{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

class LuaScriptParser // as a shareMem
{
public:

    void setShare(std::string sMem, std::string txtValue);
    std::string getShare(std::string sMem);

    static LuaScriptParser* getHandle();

    LuaScriptParser(){};

    std::map<std::string, std::string>* getStrMap(){return &strMap;}

protected:
    std::map<std::string, std::string> strMap;

    static LuaScriptParser* _obj;

};



#endif // LUASCRIPTPARSER_H
