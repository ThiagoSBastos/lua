/*
** $Id: lopcodes.c $
** Opcodes for Lua virtual machine
** See Copyright Notice in lua.h
*/

#define lopcodes_c
#define LUA_CORE

#include "lprefix.h"


#include "lopcodes.h"


/* ORDER OP */

LUAI_DDEF const lu_byte luaP_opmodes[NUM_OPCODES] = {
/*       MM OT IT T  A  mode		   opcode  */
  opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_MOVE */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iAsBx)		/* OP_LOADI */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iAsBx)		/* OP_LOADF */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABx)		/* OP_LOADK */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABx)		/* OP_LOADKX */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_LOADFALSE */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_LFALSESKIP */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_LOADTRUE */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_LOADNIL */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_GETUPVAL */
 ,opmode(0U, 0U, 0U, 0U, 0U, OpMode::iABC)		/* OP_SETUPVAL */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_GETTABUP */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_GETTABLE */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_GETI */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_GETFIELD */
 ,opmode(0U, 0U, 0U, 0U, 0U, OpMode::iABC)		/* OP_SETTABUP */
 ,opmode(0U, 0U, 0U, 0U, 0U, OpMode::iABC)		/* OP_SETTABLE */
 ,opmode(0U, 0U, 0U, 0U, 0U, OpMode::iABC)		/* OP_SETI */
 ,opmode(0U, 0U, 0U, 0U, 0U, OpMode::iABC)		/* OP_SETFIELD */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_NEWTABLE */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_SELF */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_ADDI */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_ADDK */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_SUBK */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_MULK */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_MODK */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_POWK */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_DIVK */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_IDIVK */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_BANDK */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_BORK */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_BXORK */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_SHRI */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_SHLI */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_ADD */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_SUB */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_MUL */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_MOD */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_POW */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_DIV */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_IDIV */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_BAND */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_BOR */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_BXOR */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_SHL */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_SHR */
 ,opmode(1U, 0U, 0U, 0U, 0U, OpMode::iABC)		/* OP_MMBIN */
 ,opmode(1U, 0U, 0U, 0U, 0U, OpMode::iABC)		/* OP_MMBINI*/
 ,opmode(1U, 0U, 0U, 0U, 0U, OpMode::iABC)		/* OP_MMBINK*/
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_UNM */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_BNOT */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_NOT */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_LEN */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABC)		/* OP_CONCAT */
 ,opmode(0U, 0U, 0U, 0U, 0U, OpMode::iABC)		/* OP_CLOSE */
 ,opmode(0U, 0U, 0U, 0U, 0U, OpMode::iABC)		/* OP_TBC */
 ,opmode(0U, 0U, 0U, 0U, 0U, OpMode::isJ)		/* OP_JMP */
 ,opmode(0U, 0U, 0U, 1U, 0U, OpMode::iABC)		/* OP_EQ */
 ,opmode(0U, 0U, 0U, 1U, 0U, OpMode::iABC)		/* OP_LT */
 ,opmode(0U, 0U, 0U, 1U, 0U, OpMode::iABC)		/* OP_LE */
 ,opmode(0U, 0U, 0U, 1U, 0U, OpMode::iABC)		/* OP_EQK */
 ,opmode(0U, 0U, 0U, 1U, 0U, OpMode::iABC)		/* OP_EQI */
 ,opmode(0U, 0U, 0U, 1U, 0U, OpMode::iABC)		/* OP_LTI */
 ,opmode(0U, 0U, 0U, 1U, 0U, OpMode::iABC)		/* OP_LEI */
 ,opmode(0U, 0U, 0U, 1U, 0U, OpMode::iABC)		/* OP_GTI */
 ,opmode(0U, 0U, 0U, 1U, 0U, OpMode::iABC)		/* OP_GEI */
 ,opmode(0U, 0U, 0U, 1U, 0U, OpMode::iABC)		/* OP_TEST */
 ,opmode(0U, 0U, 0U, 1U, 1U, OpMode::iABC)		/* OP_TESTSET */
 ,opmode(0U, 1U, 1U, 0U, 1U, OpMode::iABC)		/* OP_CALL */
 ,opmode(0U, 1U, 1U, 0U, 1U, OpMode::iABC)		/* OP_TAILCALL */
 ,opmode(0U, 0U, 1U, 0U, 0U, OpMode::iABC)		/* OP_RETURN */
 ,opmode(0U, 0U, 0U, 0U, 0U, OpMode::iABC)		/* OP_RETURN0U */
 ,opmode(0U, 0U, 0U, 0U, 0U, OpMode::iABC)		/* OP_RETURN1U */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABx)		/* OP_FORLOOP */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABx)		/* OP_FORPREP */
 ,opmode(0U, 0U, 0U, 0U, 0U, OpMode::iABx)		/* OP_TFORPREP */
 ,opmode(0U, 0U, 0U, 0U, 0U, OpMode::iABC)		/* OP_TFORCALL */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABx)		/* OP_TFORLOOP */
 ,opmode(0U, 0U, 1U, 0U, 0U, OpMode::iABC)		/* OP_SETLIST */
 ,opmode(0U, 0U, 0U, 0U, 1U, OpMode::iABx)		/* OP_CLOSURE */
 ,opmode(0U, 1U, 0U, 0U, 1U, OpMode::iABC)		/* OP_VARARG */
 ,opmode(0U, 0U, 1U, 0U, 1U, OpMode::iABC)		/* OP_VARARGPREP */
 ,opmode(0U, 0U, 0U, 0U, 0U, OpMode::iAx)		/* OP_EXTRAARG */
};

