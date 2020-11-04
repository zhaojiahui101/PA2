#include "cpu/exec/template-start.h"

#ifdef DEBUG
#define PRINT_SETCC_ASM(INSTR) \
            print_asm(str(INSTR)" %s", op_src->str);
#else
#define PRINT_SETCC_ASM(INSTR) do { } while(0);
#endif

#define SETCC_DO_EXECUTE(INSTR, TYPE, COND) \
static inline void do_execute_with_instr_and_type(INSTR, TYPE)(){ \
    OPERAND_W(op_src, (COND)); \
    PRINT_SETCC_ASM(INSTR); \
}

#define SETCC_MAKE_INSTR_HELPER(INSTR) make_instr_helper_with_instr(rm, INSTR)

#define MAKE_SETCC(INSTR, COND) \
        SETCC_DO_EXECUTE(INSTR, rm, COND) \
        SETCC_MAKE_INSTR_HELPER(INSTR)

MAKE_SETCC(seto, cpu.OF == 1)
MAKE_SETCC(setno, cpu.OF == 0)
MAKE_SETCC(setb, cpu.CF == 1)
MAKE_SETCC(setae, cpu.CF == 0)
MAKE_SETCC(sete, cpu.ZF == 1)
MAKE_SETCC(setne, cpu.ZF == 0)
MAKE_SETCC(setbe, cpu.CF == 1 || cpu.ZF == 1)
MAKE_SETCC(seta, cpu.CF == 0 && cpu.ZF == 0)
MAKE_SETCC(sets, cpu.SF == 1)
MAKE_SETCC(setns, cpu.SF == 0)
MAKE_SETCC(setpe, cpu.PF == 1)
MAKE_SETCC(setpo, cpu.PF == 0)
MAKE_SETCC(setl, cpu.SF != cpu.OF)
MAKE_SETCC(setge, cpu.SF == cpu.OF)
MAKE_SETCC(setle, cpu.ZF == 1 || cpu.SF != cpu.OF)
MAKE_SETCC(setg, cpu.ZF == 0 && cpu.SF == cpu.OF)

#undef PRINT_SETCC_ASM
#undef SETCC_DO_EXECUTE
#undef SETCC_MAKE_INSTR_HELPER
#undef MAKE_SETCC

#include "cpu/exec/template-end.h"
