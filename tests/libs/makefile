# change this variable to point to the directory with Lua headers
# of the version being tested
LUA_DIR = ../../src/

CC = g++

# compilation should generate Dynamic-Link Libraries
CFLAGS = -Wall -std=c++20 -O2 -I$(LUA_DIR) -fPIC -shared

# libraries used by the tests
all: lib1.so lib11.so lib2.so lib21.so lib2-v2.so
	touch all

lib1.so: lib1.cpp $(LUA_DIR)/luaconf.h $(LUA_DIR)/lua.h
	$(CC) $(CFLAGS) -o lib1.so lib1.cpp

lib11.so: lib11.cpp $(LUA_DIR)/luaconf.h $(LUA_DIR)/lua.h
	$(CC) $(CFLAGS) -o lib11.so lib11.cpp

lib2.so: lib2.cpp $(LUA_DIR)/luaconf.h $(LUA_DIR)/lua.h
	$(CC) $(CFLAGS) -o lib2.so lib2.cpp

lib21.so: lib21.cpp $(LUA_DIR)/luaconf.h $(LUA_DIR)/lua.h
	$(CC) $(CFLAGS) -o lib21.so lib21.cpp

lib2-v2.so: lib21.cpp $(LUA_DIR)/luaconf.h $(LUA_DIR)/lua.h
	$(CC) $(CFLAGS) -o lib2-v2.so lib22.cpp

clean:
	rm *.so
