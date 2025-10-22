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
#define CO_CNTX var(int, i)
#define CO_ARGS var(int, n) var(char *, name)
#include "co/begin.h"
    for (i = 0; i < n; i++) {
        printf("\"Merry Christmas, %s!\"", name);
        #include "co/yield.h"
    }
#include "co/end.h"

int main(void) {
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
            // merry_args.name = "Batman"; /* hmmmmmmmmmmmm */
            printf("\n");
        }
        if (!merry.done) { done = 0; co_resume(&merry); }

        if (done) break;
    }
}
