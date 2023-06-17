#ifdef OPCODE

/**************************/
OPCODE(NO_OP)
/**************************/
OPCODE(POP_TOP)
OPCODE(DUP_TOP)
OPCODE(ROT_TWO)
OPCODE(ROT_THREE)
OPCODE(PRINT_EXPR)
/**************************/
OPCODE(LOAD_CONST)
OPCODE(LOAD_NONE)
OPCODE(LOAD_TRUE)
OPCODE(LOAD_FALSE)
OPCODE(LOAD_INTEGER)
OPCODE(LOAD_ELLIPSIS)
OPCODE(LOAD_FUNCTION)
OPCODE(LOAD_NULL)
/**************************/
OPCODE(LOAD_FAST)
OPCODE(LOAD_NAME)
OPCODE(LOAD_NONLOCAL)
OPCODE(LOAD_GLOBAL)
OPCODE(LOAD_ATTR)
OPCODE(LOAD_METHOD)
OPCODE(LOAD_SUBSCR)

OPCODE(STORE_FAST)
OPCODE(STORE_NAME)
OPCODE(STORE_GLOBAL)
OPCODE(STORE_ATTR)
OPCODE(STORE_SUBSCR)

OPCODE(DELETE_FAST)
OPCODE(DELETE_NAME)
OPCODE(DELETE_GLOBAL)
OPCODE(DELETE_ATTR)
OPCODE(DELETE_SUBSCR)
/**************************/
OPCODE(BUILD_LONG)
OPCODE(BUILD_TUPLE)
OPCODE(BUILD_LIST)
OPCODE(BUILD_DICT)
OPCODE(BUILD_SET)
OPCODE(BUILD_SLICE)
OPCODE(BUILD_STRING)
/**************************/
OPCODE(BUILD_TUPLE_UNPACK)
OPCODE(BUILD_LIST_UNPACK)
OPCODE(BUILD_DICT_UNPACK)
OPCODE(BUILD_SET_UNPACK)
/**************************/
OPCODE(BINARY_TRUEDIV)
OPCODE(BINARY_POW)

OPCODE(BINARY_ADD)
OPCODE(BINARY_SUB)
OPCODE(BINARY_MUL)
OPCODE(BINARY_FLOORDIV)
OPCODE(BINARY_MOD)

OPCODE(COMPARE_LT)
OPCODE(COMPARE_LE)
OPCODE(COMPARE_EQ)
OPCODE(COMPARE_NE)
OPCODE(COMPARE_GT)
OPCODE(COMPARE_GE)

OPCODE(BITWISE_LSHIFT)
OPCODE(BITWISE_RSHIFT)
OPCODE(BITWISE_AND)
OPCODE(BITWISE_OR)
OPCODE(BITWISE_XOR)

OPCODE(BINARY_MATMUL)

OPCODE(IS_OP)
OPCODE(CONTAINS_OP)
/**************************/
OPCODE(JUMP_ABSOLUTE)
OPCODE(POP_JUMP_IF_FALSE)
OPCODE(JUMP_IF_TRUE_OR_POP)
OPCODE(JUMP_IF_FALSE_OR_POP)
OPCODE(SHORTCUT_IF_FALSE_OR_POP)
OPCODE(LOOP_CONTINUE)
OPCODE(LOOP_BREAK)
OPCODE(GOTO)
/**************************/
OPCODE(CALL)
OPCODE(CALL_TP)
OPCODE(RETURN_VALUE)
OPCODE(YIELD_VALUE)
/**************************/
OPCODE(LIST_APPEND)
OPCODE(DICT_ADD)
OPCODE(SET_ADD)
/**************************/
OPCODE(UNARY_NEGATIVE)
OPCODE(UNARY_NOT)
OPCODE(UNARY_STAR)
/**************************/
OPCODE(GET_ITER)
OPCODE(FOR_ITER)
/**************************/
OPCODE(IMPORT_NAME)
OPCODE(IMPORT_NAME_REL)
OPCODE(IMPORT_STAR)
/**************************/
OPCODE(UNPACK_SEQUENCE)
OPCODE(UNPACK_EX)
/**************************/
OPCODE(BEGIN_CLASS)
OPCODE(END_CLASS)
OPCODE(STORE_CLASS_ATTR)
/**************************/
OPCODE(WITH_ENTER)
OPCODE(WITH_EXIT)
/**************************/
OPCODE(ASSERT)
OPCODE(EXCEPTION_MATCH)
OPCODE(RAISE)
OPCODE(RE_RAISE)
OPCODE(POP_EXCEPTION)
/**************************/
OPCODE(SETUP_DOCSTRING)
OPCODE(FORMAT_STRING)
/**************************/
OPCODE(INC_FAST)
OPCODE(DEC_FAST)
OPCODE(INC_GLOBAL)
OPCODE(DEC_GLOBAL)
#endif