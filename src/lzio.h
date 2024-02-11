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

#ifdef __cplusplus
extern "C" {
#endif

#define EOZ	(-1)			/* end of stream */

namespace lua::zio {
struct Zio
{
// public:
  explicit Zio(lua_State *Lstate, lua_Reader lreader, void *additional_data);

  size_t n = 0; /* bytes still unread */
  const char *p = nullptr; /* current position in buffer */
  lua_Reader reader; /* reader function */
  void *data = nullptr; /* additional data */
  lua_State *L = nullptr; /* Lua state (for reader) */
};

}// namespace lua::zio


using pZIO = lua::zio::Zio*; // handle
pZIO createZIO(lua_State *L, lua_Reader reader, void *data);
void destroyZIO(pZIO z);

#define zgetc(z)  (((z)->n--)>0 ?  cast_uchar(*(z)->p++) : luaZ_fill(z))

typedef struct Mbuffer {
  char *buffer;
  size_t n;
  size_t buffsize;
} Mbuffer;

#define luaZ_initbuffer(L, buff) ((buff)->buffer = NULL, (buff)->buffsize = 0)

#define luaZ_buffer(buff)	((buff)->buffer)
#define luaZ_sizebuffer(buff)	((buff)->buffsize)
#define luaZ_bufflen(buff)	((buff)->n)

#define luaZ_buffremove(buff,i)	((buff)->n -= (i))
#define luaZ_resetbuffer(buff) ((buff)->n = 0)


#define luaZ_resizebuffer(L, buff, size) \
	((buff)->buffer = luaM_reallocvchar(L, (buff)->buffer, \
				(buff)->buffsize, size), \
	(buff)->buffsize = size)

#define luaZ_freebuffer(L, buff)	luaZ_resizebuffer(L, buff, 0)

LUAI_FUNC size_t luaZ_read (pZIO z, void *b, size_t n);	/* read next n bytes */

LUAI_FUNC int luaZ_fill(pZIO z);

#ifdef __cplusplus
}
#endif

#endif
