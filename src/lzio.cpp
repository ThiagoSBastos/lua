/*
** $Id: lzio.c $
** Buffered streams
** See Copyright Notice in lua.h
*/

#define lzio_c
#define LUA_CORE

#include "lprefix.h"


#include <string.h>

#include "lua.h"

#include "llimits.h"
#include "lmem.h"
#include "lstate.h"
#include "lzio.h"

pZIO createZIO(lua_State *L, lua_Reader reader, void *data)
{
  return new lua::zio::Zio(L, reader, data);
}

void destroyZIO(pZIO z) { delete z; }

namespace lua::zio
{

Zio::Zio(lua_State *Lstate, lua_Reader lreader, void *additional_data)
: reader(lreader),
  data(additional_data),
  L(Lstate)
{
}

}// namespace lua::zio

int luaZ_fill(pZIO z)
{
  size_t size = 0;
  lua_State *L = z->L;
  const char *buff = nullptr;
  lua_unlock(L);
  buff = z->reader(L, z->data, &size);
  lua_lock(L);
  if (buff == nullptr || size == 0) { return EOZ; }
  z->n = size - 1; /* discount char being returned */
  z->p = buff;
  return static_cast<unsigned char>(*(z->p++));
}

/* --------------------------------------------------------------- read --- */
size_t luaZ_read (pZIO z, void *b, size_t n) {
  while (n != 0U) {
    size_t m = 0;
    if (z->n == 0) {  /* no bytes in buffer? */
      if (luaZ_fill(z) == EOZ)  /* try to read more */
        return n;  /* no more input; return number of missing bytes */
      else {
        z->n++;  /* luaZ_fill consumed first byte; put it back */
        z->p--;
      }
    }
    m = (n <= z->n) ? n : z->n;  /* min. between n and z->n */
    memcpy(b, z->p, m);
    z->n -= m;
    z->p += m;
    b = reinterpret_cast<char*>(b) + m;
    n -= m;
  }
  return 0;
}
