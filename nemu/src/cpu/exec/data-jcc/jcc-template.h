#include "cpu/exec/template-start.h"

#ifdef DEBUG
#define PRINT_JCC_ASM(INSTR) \
        print_asm(str(INSTR) " offset:0x%x", op_src->val);
#else
#define PRINT_JCC_ASM(INSTR) do { } while(0);
#endif

#define JCC_DO_EXECUTE(INSTR, TYPE, COND) \
static inline void do_execute_with_instr_and_type(INSTR, TYPE)() { \
        if(COND) { \
            if(DATA_BYTE == 1 || DATA_BYTE == 4) \
                cpu.eip += (uint32_t)((int32_t)((DATA_TYPE_S) op_src->val)); \
            else { \
                assert(0); \
            } \
        } \
        PRINT_JCC_ASM(INSTR) \
}

#define JCC_MAKE_INSTR_HELPER(INSTR) make_instr_helper_with_instr(i, INSTR)

#define MAKE_JCC(INSTR, COND) \
JCC_DO_EXECUTE(INSTR, i , COND) \
JCC_MAKE_INSTR_HELPER(INSTR)

MAKE_JCC(jo, cpu.OF == 1)
MAKE_JCC(jno, cpu.OF == 0)
MAKE_JCC(jb, cpu.CF == 1)
MAKE_JCC(jae, cpu.CF == 0)
MAKE_JCC(je, cpu.ZF == 1)
MAKE_JCC(jne, cpu.ZF == 0)
MAKE_JCC(jbe, cpu.CF == 1 ||  cpu.ZF == 1)
MAKE_JCC(ja, cpu.CF == 0 && cpu.ZF == 0)
MAKE_JCC(js, cpu.SF == 1)
MAKE_JCC(jns, cpu.SF == 0)
MAKE_JCC(jpe, cpu.PF == 1)
MAKE_JCC(jpo, cpu.PF == 0)
MAKE_JCC(jl, cpu.SF != cpu.OF)
MAKE_JCC(jge, cpu.SF == cpu.OF)
MAKE_JCC(jle, cpu.ZF == 1 || cpu.SF != cpu.OF)
MAKE_JCC(jg, cpu.ZF == 0 && cpu.SF == cpu.OF)

#if DATA_BYTE == 1
MAKE_JCC(jecxz, (ops_decoded.is_operand_size_16 ? R_CX : R_ECX) == 0)
#endif

#undef PRINT_JCC_ASM
#undef JCC_DO_EXECUTE
#undef JCC_MAKE_INSTR_HELPER
#undef MAKE_JCC

#include "cpu/exec/template-end.h"