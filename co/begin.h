#ifndef CO_NAME
#error "You must define a name for your coroutine"
#endif

#ifndef CO_CONTEXT
#define CO_CONTEXT
#endif

#ifndef CO_ARGS
#define CO_ARGS
#endif

typedef struct { CO_CONTEXT int _do_not_use; } CoroutineContext(CO_NAME);
typedef struct { CO_ARGS int _do_not_use; } CoroutineArgs(CO_NAME);
void CO_NAME(Coroutine *_co) {
    CoroutineContext(CO_NAME) *ctx;
    CoroutineArgs(CO_NAME) *args;

    if (_co->ctx) ctx = (CoroutineContext(CO_NAME) *) _co->ctx;
    if (_co->args) args = (CoroutineArgs(CO_NAME) *) _co->args;

#define _COROUTINE_COUNTER 0
    goto __coroutine_jump;
    __coroutine_yield_0:

#undef CO_NAME
#undef CO_CONTEXT
#undef CO_ARGS
