#include "pocketpy/pocketpy.h"

#include "pocketpy/common/utils.h"
#include "pocketpy/objects/object.h"
#include "pocketpy/interpreter/vm.h"

py_Ref py_getreg(int i) { return pk_current_vm->reg + i; }

void py_setreg(int i, py_Ref val) { pk_current_vm->reg[i] = *val; }

py_Ref py_getdict(py_Ref self, py_Name name) {
    assert(self && self->is_ptr);
    if(!py_ismagicname(name) || self->type != tp_type) {
        return NameDict__try_get(PyObject__dict(self->_obj), name);
    } else {
        py_Type* ud = py_touserdata(self);
        py_Ref slot = py_tpgetmagic(*ud, name);
        return py_isnil(slot) ? NULL : slot;
    }
}

void py_setdict(py_Ref self, py_Name name, py_Ref val) {
    assert(self && self->is_ptr);
    if(!py_ismagicname(name) || self->type != tp_type) {
        NameDict__set(PyObject__dict(self->_obj), name, *val);
    } else {
        py_Type* ud = py_touserdata(self);
        *py_tpgetmagic(*ud, name) = *val;
    }
}

py_TmpRef py_emplacedict(py_Ref self, py_Name name){
    py_setdict(self, name, py_NIL);
    return py_getdict(self, name);
}

bool py_deldict(py_Ref self, py_Name name) {
    assert(self && self->is_ptr);
    if(!py_ismagicname(name) || self->type != tp_type) {
        return NameDict__del(PyObject__dict(self->_obj), name);

    } else {
        py_Type* ud = py_touserdata(self);
        py_newnil(py_tpgetmagic(*ud, name));
        return true;
    }
}

py_Ref py_getslot(py_Ref self, int i) {
    assert(self && self->is_ptr);
    assert(i >= 0 && i < self->_obj->slots);
    return PyObject__slots(self->_obj) + i;
}

void py_setslot(py_Ref self, int i, py_Ref val) {
    assert(self && self->is_ptr);
    assert(i >= 0 && i < self->_obj->slots);
    PyObject__slots(self->_obj)[i] = *val;
}

py_StackRef py_inspect_currentfunction(){
    Frame* frame = pk_current_vm->top_frame;
    if(!frame || !frame->has_function) return NULL;
    return frame->p0;
}

void py_assign(py_Ref dst, py_Ref src) { *dst = *src; }

/* Stack References */
py_Ref py_peek(int i) {
    assert(i <= 0);
    return pk_current_vm->stack.sp + i;
}

void py_pop() {
    VM* vm = pk_current_vm;
    vm->stack.sp--;
}

void py_shrink(int n) {
    VM* vm = pk_current_vm;
    vm->stack.sp -= n;
}

void py_push(py_Ref src) {
    VM* vm = pk_current_vm;
    *vm->stack.sp++ = *src;
}

void py_pushnil() {
    VM* vm = pk_current_vm;
    py_newnil(vm->stack.sp++);
}

void py_pushnone() {
    VM* vm = pk_current_vm;
    py_newnone(vm->stack.sp++);
}

py_Ref py_pushtmp() {
    VM* vm = pk_current_vm;
    py_newnil(vm->stack.sp++);
    return py_peek(-1);
}