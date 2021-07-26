#include <iostream>
#include <string>

extern "C"
{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

bool CheckLua(lua_State *L, int r)
{
    if(r != LUA_OK)
    {
//        lua_getglobal(L, "a");
        std::string errormsg = lua_tostring(L, -1);
        std::cout << errormsg << std::endl;
        return false;
    }
    return true;
}

struct Player
{
    std::string title;
    std::string name;
    std::string family;
    int level;
};

int lua_HostFunction(lua_State* L)
{
    float a = (float)lua_tonumber(L, 1);
    float b = (float)lua_tonumber(L, 2);
    std::cout << "[C++] HOSTFUNCTION" << std::endl;

    float c = a * b;

    lua_pushnumber(L, c);

    return 1;
}

int main(int argc, char *argv[])
{
    Player player;

    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    lua_register(L, "HostFunction", lua_HostFunction);

    if(CheckLua(L, luaL_dofile(L, "/home/victor/gitProjects/Lua_CPP/lua_cpp/luatest.lua")))
    {

//        lua_getglobal(L, "getPlayer");
        lua_getglobal(L, "doAThing");

        if(lua_isfunction(L, -1))
        {
            lua_pushnumber(L, 5.f);
            lua_pushnumber(L, 6.f);

            if(CheckLua(L, lua_pcall(L, 2, 1, 0)))
            {


//                if(lua_istable(L, -1))
//                {
//                    lua_pushstring(L, "Name");
//                    lua_gettable(L, -2);
//                    player.name = lua_tostring(L, -1);
//                    lua_pop(L, 1);

//                    lua_pushstring(L, "Family");
//                    lua_gettable(L, -2);
//                    player.family = lua_tostring(L, -1);
//                    lua_pop(L, 1);

//                    lua_pushstring(L, "Title");
//                    lua_gettable(L, -2);
//                    player.title = lua_tostring(L, -1);
//                    lua_pop(L, 1);

//                    lua_pushstring(L, "Level");
//                    lua_gettable(L, -2);
//                    player.level = lua_tonumber(L, -1);
//                    lua_pop(L, 1);
//                }

//                std::cout << player.title << " " << player.name << " of " << player.family
//                                  << " [Level: " << player.level << "]" << std::endl;
            }

        }

  //-------------------------
//        lua_getglobal(L, "addStuff");
//        if(lua_isfunction(L, -1))
//        {
//            lua_pushnumber(L, 3.5f);
//            lua_pushnumber(L, 7.1f);

//            if(CheckLua(L, lua_pcall(L, 2, 1, 0)))
//            {
//                std::cout << "[C++] result: " << (float)lua_tonumber(L, -1) << std::endl;
//            }

//        }
/////////////////----------------------------------
//        lua_getglobal(L, "player");
//        if(lua_istable(L, -1))
//        {
//            lua_pushstring(L, "Name");
//            lua_gettable(L, -2);
//            player.name = lua_tostring(L, -1);
//            lua_pop(L, 1);

//            lua_pushstring(L, "Family");
//            lua_gettable(L, -2);
//            player.family = lua_tostring(L, -1);
//            lua_pop(L, 1);

//            lua_pushstring(L, "Title");
//            lua_gettable(L, -2);
//            player.title = lua_tostring(L, -1);
//            lua_pop(L, 1);

//            lua_pushstring(L, "Level");
//            lua_gettable(L, -2);
//            player.level = lua_tonumber(L, -1);
//            lua_pop(L, 1);
//        }


//        std::cout << player.title << " " << player.name << " of " << player.family
//                  << " [Level: " << player.level << "]" << std::endl;
        std::cout << "[C++]" << " doAThing called" << std::endl;

    }

    lua_close(L);

    return 0;
}
