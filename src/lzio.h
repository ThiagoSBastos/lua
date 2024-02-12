/*
** $Id: lzio.h $
** Buffered streams
** See Copyright Notice in lua.h
*/

#ifndef lzio_h
#define lzio_h

#ifdef __cplusplus
extern "C" {
#endif
#include "lua.h"
#include "lmem.h"
#ifdef __cplusplus
}
#endif

constexpr int EOZ = (-1);			/* end of stream */

namespace lua::zio {

class Zio
{
public:
  explicit Zio(lua_State *Lstate, lua_Reader lreader, void *additional_data);
  size_t luaZ_read (void *b, size_t n);	/* read next n bytes */
  int luaZ_fill(); // TODO: make it private

  friend constexpr int zgetc(Zio* z);

private:
  size_t n = 0; /* bytes still unread */
  const char *p = nullptr; /* current position in buffer */
  lua_Reader reader; /* reader function */
  void *data = nullptr; /* additional data */
  lua_State *L = nullptr; /* Lua state (for reader) */
};

constexpr int zgetc(lua::zio::Zio* z) {
    if (z->n-- > 0) {
        return cast_uchar(*(z)->p++);
    }
    else {
        return z->luaZ_fill();
    }
}

}// namespace lua::zio


class Mbuffer {
public:
  // TODO: change this to a constructor as soon as SParser becomes a class
  constexpr void luaZ_initbuffer(lua_State* L) {
    this->buffer = nullptr;
    this->buffsize = 0;
  }
  [[nodiscard]] constexpr const char* luaZ_buffer() const { return this->buffer; }
  [[nodiscard]] constexpr size_t luaZ_sizebuffer() const { return this->buffsize; }
  constexpr void luaZ_resetbuffer() { this->n = 0; }
  constexpr void luaZ_buffremove(int i) { this->n -= (i); }
  constexpr void luaZ_resizebuffer(lua_State* L, size_t size) {
    this->buffer = luaM_reallocvchar(L, this->buffer, this->buffsize, size);
    this->buffsize = size;
  }
  constexpr void luaZ_freebuffer(lua_State* L) { luaZ_resizebuffer(L, 0); }
  char *buffer;
  size_t n;
  size_t buffsize;
};



#define luaZ_bufflen(buff) ((buff)->n)



#endif
