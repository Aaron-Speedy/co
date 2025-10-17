# Co

Co is a tiny coroutine library for C89.

Unlike other coroutine libraries, Co does not use assembly;
everything is done with simple preprocessor code. This
makes Co stackless (read: no stack frame), meaning that
all local variables must be put in a context struct, and
coroutines can't be yielded from subfunctions. In the
former case, we provide syntax sugar to hopefully make
things less painful. This is useful

Unlike other stackless coroutine libraries, Co does not
use any tricks with switch statements. This means that Co
functions can contain switch statements.

Co is exactly 250 lines of code, and is very simple,
so feel free to explore!

## Usage

The following code is in C99 to make things clearer and
simpler, but note that Co can be used from C89. This file
is exactly reproduced in example.c.

```c
#include <stdlib.h>
#include <stdio.h>

#define CO_IMPL
#include "co/co.h"

#define CO_NAME hello_world
#include "co/begin.h"
    printf("Hello, ");

    #include "co/yield.h"

    printf(" world!\n");
#include "co/end.h"

#define CO_NAME merry_christmas
#define CO_CONTEXT int i;
#define CO_ARGS int n; char *name;
#include "co/begin.h"
    for (ctx->i = 0; ctx->i < args->n; ctx->i++) {
        printf("\"Merry Christmas, %s!\"", args->name);
        #include "co/yield.h"
    }
#include "co/end.h"

int main() {
    /* This library does no memory management, and it has no constructors.
       Of course, if you want, you can write wrappers to do those things. */

    CoroutineContext(hello_world) hello_ctx = {0};
    Coroutine hello = {
        .ctx = &hello_ctx,
        .fn = hello_world,
    };

    CoroutineContext(merry_christmas) merry_ctx = {0};
    CoroutineArgs(merry_christmas) merry_args = { .n = 50, .name = "Bruce", };
    Coroutine merry = {
        .ctx = &merry_ctx,
        .args = &merry_args,
        .fn = merry_christmas,
    };

    while (1) {
        int done = 1;

        if (!hello.done) { done = 0; co_resume(&hello); }
        else {
            merry_args.name = "Batman"; /* hmmmmmmmmmmmm */
            printf("\n");
        }
        if (!merry.done) { done = 0; co_resume(&merry); }

        if (done) break;
    }
}
```
