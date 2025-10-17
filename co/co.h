#ifndef CO_H
#define CO_H

typedef struct Coroutine Coroutine;
struct Coroutine {
    int i;
    int done;
    void *ctx, *args, (*fn)(Coroutine *);
};

void co_resume(Coroutine *c);

#define CoroutineContext_1(name) _CoroutineContextOf_ ## name
#define CoroutineContext(name) CoroutineContext_1(name)

#define CoroutineArgs_1(name) _CoroutineArgsOf_ ## name
#define CoroutineArgs(name) CoroutineArgs_1(name)

#endif

#ifdef CO_IMPL
#ifndef CO_IMPL_GUARD
#define CO_IMPL_GUARD

void co_resume(Coroutine *c) {
    c->fn(c);
}

#endif
#endif
