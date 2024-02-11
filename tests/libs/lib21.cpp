#ifdef __cplusplus
extern "C"{
#endif

#include "lua.h"

#ifdef __cplusplus
}
#endif

int luaopen_lib2 (lua_State *L);

LUAMOD_API int luaopen_lib21 (lua_State *L) {
  return luaopen_lib2(L);
}


