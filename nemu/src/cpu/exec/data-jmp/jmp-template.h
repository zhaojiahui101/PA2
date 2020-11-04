#include "cpu/exec/template-start.h"

#define instr jmp

static void do_execute() {
    DATA_TYPE_S displacement = op_src->val;
    if(op_src->type == OP_TYPE_IMM)
    {
        cpu.eip += displacement;
    }
    else
    {
        int len = concat(decode_rm_, SUFFIX)(cpu.eip + 1);
        cpu.eip = displacement - len - 1;
    }
    print_asm_template1();
}

make_instr_helper(i)
make_instr_helper(rm)

#include "cpu/exec/template-end.h"
