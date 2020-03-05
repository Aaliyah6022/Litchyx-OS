#ifndef LUNYX_KERNEL_MM_H
#define LUNYX_KERNEL_MM_H

#include <assert.h> // Standard Library: C preprocessor marco "assert()".
#include <string.h> // Standard Library: Working with strings in C.
#include <stdlib.h> // Standard Library: Variable types, several marco and various functions for performing general stuff.
#include <errno.h>  // Library         : System error numbers.
#include <limits.h> // Standard Library: Defines various properties of various variable types, as well as the limits of several variable types, like chat, int and long.
#include <stdio.h>  // Standard Library: Three types of variables, functions for performing input and outputs.

typedef unsigned long dma_addr_t;

#define unlikely

#define bug_on(x) assert(!(x))

#define warn_on(condition) ({                                           \
    int __ret_warn_on = !!(condition);                              \
    unlikely(__ret_warn_on);                                        \
})

#define warn_on_once(condition) ({                              \
    int __ret_warn_on = !!(condition);                      \
    if (unlikely(__ret_warn_on))                            \
        assert(0);                                      \
    unlikely(__ret_warn_on);                                \
})

#endif
