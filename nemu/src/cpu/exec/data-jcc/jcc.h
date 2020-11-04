#ifndef __JCC_H__
#define __JCC_H__

#define MAKE_JCC_HELPER(INSTR) \
        make_helper(concat(INSTR, _i_b)); \
        make_helper(concat(INSTR, _i_v)); \

MAKE_JCC_HELPER(jo)
MAKE_JCC_HELPER(jno)
MAKE_JCC_HELPER(jb)
MAKE_JCC_HELPER(jae)
MAKE_JCC_HELPER(je)
MAKE_JCC_HELPER(jne)
MAKE_JCC_HELPER(jbe)
MAKE_JCC_HELPER(ja)
MAKE_JCC_HELPER(js)
MAKE_JCC_HELPER(jns)
MAKE_JCC_HELPER(jpe)
MAKE_JCC_HELPER(jpo)
MAKE_JCC_HELPER(jl)
MAKE_JCC_HELPER(jge)
MAKE_JCC_HELPER(jle)
MAKE_JCC_HELPER(jg)

make_helper(jecxz_i_b);

#endif
