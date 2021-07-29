#include "luascriptparser.h"


LuaScriptParser* LuaScriptParser::_obj = nullptr;

std::string LuaScriptParser::getShare(std::string sMem)
{
    try {
        return strMap[sMem];
    }  catch (...) {
        return nullptr;
    }
}

void LuaScriptParser::setShare(std::string sMem, std::string txtValue)
{
    strMap[sMem] = txtValue;
}

LuaScriptParser *LuaScriptParser::getHandle()
{
    if(!_obj)
        _obj = new LuaScriptParser;

    return _obj;
}

