#include <stdio.h>
#include <lua.h>
#include <luaconf.h>
#include <lualib.h>
#include <lauxlib.h>


static int pmain(lua_State* L) {
  fprintf(stderr, "Hello, Lua C API! "); 
  return 1; 
}

static const luaL_Reg exports[] = {
  { "pmain", pmain }, 
  { NULL, NULL }
}; 

int main(int argc, char const* argv[])
{
  lua_State* L = luaL_newstate(); 
  if (L == NULL) {
    fprintf(stderr, "cannot create state: not enough memory"); 
    //return EXIT_FAILURE; 
    return -1; 
  }
  luaL_openlibs(L); 
  //luaL_register(L, NULL, exports); 
  lua_pushcfunction(L, pmain); 
  int status = lua_pcall(L, 0, 0, 0); 
  lua_close(L); 
  return status;
}

