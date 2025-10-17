goto __skip_coroutine_jump;

__coroutine_jump:
switch (_co->i) {
#if _COROUTINE_COUNTER >= 0
case 0: goto __coroutine_yield_0;
#endif
#if _COROUTINE_COUNTER >= 1
case 1: goto __coroutine_yield_1;
#endif
#if _COROUTINE_COUNTER >= 2
case 2: goto __coroutine_yield_2;
#endif
#if _COROUTINE_COUNTER >= 3
case 3: goto __coroutine_yield_3;
#endif
#if _COROUTINE_COUNTER >= 4
case 4: goto __coroutine_yield_4;
#endif
#if _COROUTINE_COUNTER >= 5
case 5: goto __coroutine_yield_5;
#endif
#if _COROUTINE_COUNTER >= 6
case 6: goto __coroutine_yield_6;
#endif
#if _COROUTINE_COUNTER >= 7
case 7: goto __coroutine_yield_7;
#endif
#if _COROUTINE_COUNTER >= 8
case 8: goto __coroutine_yield_8;
#endif
#if _COROUTINE_COUNTER >= 9
case 9: goto __coroutine_yield_9;
#endif
#if _COROUTINE_COUNTER >= 10
case 10: goto __coroutine_yield_10;
#endif
#if _COROUTINE_COUNTER >= 11
case 11: goto __coroutine_yield_11;
#endif
#if _COROUTINE_COUNTER >= 12
case 12: goto __coroutine_yield_12;
#endif
#if _COROUTINE_COUNTER >= 13
case 13: goto __coroutine_yield_13;
#endif
#if _COROUTINE_COUNTER >= 14
case 14: goto __coroutine_yield_14;
#endif
#if _COROUTINE_COUNTER >= 15
case 15: goto __coroutine_yield_15;
#endif
#if _COROUTINE_COUNTER >= 16
case 16: goto __coroutine_yield_16;
#endif
#if _COROUTINE_COUNTER >= 17
case 17: goto __coroutine_yield_17;
#endif
#if _COROUTINE_COUNTER >= 18
case 18: goto __coroutine_yield_18;
#endif
#if _COROUTINE_COUNTER >= 19
case 19: goto __coroutine_yield_19;
#endif
#if _COROUTINE_COUNTER >= 20
case 20: goto __coroutine_yield_20;
#endif
#if _COROUTINE_COUNTER >= 21
case 21: goto __coroutine_yield_21;
#endif
#if _COROUTINE_COUNTER >= 22
case 22: goto __coroutine_yield_22;
#endif
#if _COROUTINE_COUNTER >= 23
case 23: goto __coroutine_yield_23;
#endif
#if _COROUTINE_COUNTER >= 24
case 24: goto __coroutine_yield_24;
#endif
#if _COROUTINE_COUNTER >= 25
case 25: goto __coroutine_yield_25;
#endif
#if _COROUTINE_COUNTER >= 26
case 26: goto __coroutine_yield_26;
#endif
#if _COROUTINE_COUNTER >= 27
case 27: goto __coroutine_yield_27;
#endif
#if _COROUTINE_COUNTER >= 28
case 28: goto __coroutine_yield_28;
#endif
#if _COROUTINE_COUNTER >= 29
case 29: goto __coroutine_yield_29;
#endif
#if _COROUTINE_COUNTER >= 30
case 30: goto __coroutine_yield_30;
#endif
#if _COROUTINE_COUNTER >= 31
#error "No more than 30 yield slots are enabled. To enable more, add more conditions to co/yield.h and co/end.h"
#endif
}

__skip_coroutine_jump:
_co->done = 1;
_co->i += 1;
}

#undef _COROUTINE_COUNTER
