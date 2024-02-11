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

namespace lua::zio
{

Zio::Zio(lua_State *Lstate, lua_Reader lreader, void *additional_data)
: reader(lreader),
  data(additional_data),
  L(Lstate)
{
}

int Zio::luaZ_fill()
{
  size_t size = 0;
  lua_State *Lcopy = this->L;
  const char *buff = nullptr;
  lua_unlock(Lcopy);
  buff = this->reader(Lcopy, this->data, &size);
  lua_lock(Lcopy);
  if (buff == nullptr || size == 0) { return EOZ; }
  this->n = size - 1; /* discount char being returned */
  this->p = buff;
  return static_cast<unsigned char>(*(this->p++));
}

/* --------------------------------------------------------------- read --- */
size_t Zio::luaZ_read (void *b, size_t input_n) {
  while (input_n != 0U) {
    size_t m = 0;
    if (this->n == 0) {  /* no bytes in buffer? */
      if (luaZ_fill() == EOZ)  /* try to read more */
        return input_n;  /* no more input; return number of missing bytes */
      else {
        this->n++;  /* luaZ_fill consumed first byte; put it back */
        this->p--;
      }
    }
    m = (input_n <= this->n) ? input_n : this->n;  /* min. between n and z->n */
    memcpy(b, this->p, m);
    this->n -= m;
    this->p += m;
    b = reinterpret_cast<char*>(b) + m;
    input_n -= m;
  }
  return 0;
}

}// namespace lua::zio

