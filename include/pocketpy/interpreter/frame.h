#pragma once

#include "pocketpy/common/memorypool.h"
#include "pocketpy/objects/codeobject.h"
#include "pocketpy/objects/namedict.h"
#include "pocketpy/objects/object.h"
#include "pocketpy/pocketpy.h"

void FastLocals__to_dict(py_TValue* locals, const CodeObject* co) PY_RETURN;
NameDict* FastLocals__to_namedict(py_TValue* locals, const CodeObject* co);

typedef struct ValueStack {
    py_TValue* sp;
    py_TValue* end;
    // We allocate extra places to keep `_sp` valid to detect stack overflow
    py_TValue begin[PK_VM_STACK_SIZE + PK_MAX_CO_VARNAMES * 2];
} ValueStack;

void ValueStack__ctor(ValueStack* self);
void ValueStack__dtor(ValueStack* self);

typedef struct UnwindTarget {
    struct UnwindTarget* next;
    int iblock;
    int offset;
} UnwindTarget;

UnwindTarget* UnwindTarget__new(UnwindTarget* next, int iblock, int offset);
void UnwindTarget__delete(UnwindTarget* self);

typedef struct Frame {
    struct Frame* f_back;
    const CodeObject* co;
    py_StackRef p0;  // unwinding base
    py_GlobalRef module;
    py_Ref globals;  // a module object or a dict object
    py_Ref locals;   // locals base or a proxy object (such as dict)
    bool is_p0_function;
    bool is_locals_proxy;
    int ip;
    UnwindTarget* uw_list;
} Frame;

Frame* Frame__new(const CodeObject* co,
                  py_StackRef p0,
                  py_GlobalRef module,
                  py_Ref globals,
                  py_Ref locals,
                  bool is_p0_function,
                  bool is_locals_proxy);
void Frame__delete(Frame* self);

int Frame__lineno(const Frame* self);
int Frame__iblock(const Frame* self);

int Frame__getglobal(Frame* self, py_Name name) PY_RAISE PY_RETURN;
bool Frame__setglobal(Frame* self, py_Name name, py_TValue* val) PY_RAISE;
int Frame__delglobal(Frame* self, py_Name name) PY_RAISE;

int Frame__getlocal(Frame* self, py_Name name) PY_RAISE PY_RETURN;
bool Frame__setlocal(Frame* self, py_Name name, py_TValue* val) PY_RAISE;
int Frame__dellocal(Frame* self, py_Name name) PY_RAISE;

py_Ref Frame__getclosure(Frame* self, py_Name name);
py_StackRef Frame__getlocal_noproxy(Frame* self, py_Name name);

py_StackRef Frame__locals_sp(Frame* self);

int Frame__prepare_jump_exception_handler(Frame* self, ValueStack*);

UnwindTarget* Frame__find_unwind_target(Frame* self, int iblock);
void Frame__set_unwind_target(Frame* self, py_TValue* sp);

void Frame__gc_mark(Frame* self);