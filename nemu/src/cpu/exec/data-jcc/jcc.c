#include "cpu/exec/helper.h"

#define DATA_BYTE 1
#include "jcc-template.h"
#undef DATA_BYTE

#define DATA_BYTE 2
#include "jcc-template.h"
#undef DATA_BYTE

#define DATA_BYTE 4
#include "jcc-template.h"
#undef DATA_BYTE

#define MAKE_JCC_HELPER_V(INSTR) make_helper_v(concat(INSTR, _i))

MAKE_JCC_HELPER_V(jo)
MAKE_JCC_HELPER_V(jno)
MAKE_JCC_HELPER_V(jb)
MAKE_JCC_HELPER_V(jae)
MAKE_JCC_HELPER_V(je)
MAKE_JCC_HELPER_V(jne)
MAKE_JCC_HELPER_V(jbe)
MAKE_JCC_HELPER_V(ja)
MAKE_JCC_HELPER_V(js)
MAKE_JCC_HELPER_V(jns)
MAKE_JCC_HELPER_V(jpe)
MAKE_JCC_HELPER_V(jpo)
MAKE_JCC_HELPER_V(jl)
MAKE_JCC_HELPER_V(jge)
MAKE_JCC_HELPER_V(jle)
MAKE_JCC_HELPER_V(jg)
