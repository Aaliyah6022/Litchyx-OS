#ifndef LITCHYX_KERNEL_MM_H
#define LITCHYX_KERNEL_MM_H

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

#define pageSize    (4096)
#define pageShift   (12)
#define pageMask    (~(pageSize - 1))

#define _alignKernel(x, a)        _alignKernelMask(x, (typeof(x))(a) - 1)
#define _alignKernelMask(x, mask)    (((x) + (mask)) & ~(mask))
#define align(x, a)        _alignKernel((x), (a))

#define pageAlign(addr) align(addr, pageSize)

#define pageOffset(p)    ((unsigned long)(p) & ~pageMask)

#define virtToPage(x) ((void *)x)
#define pageAddress(x) ((void *)x)

static inline unsigned long pageToPhys(struct page *page)
{
    assert(0);
    return 0;
}

#define pageToPfn(page) ((unsigned long)(page) / pageSize)
#define pfnToPage(pfn) (void *)((pfn) * pageSize)
#define nthPage(page, n) pfnToPage(pageToPfn((page)) + (n))

#define __min(t1, t2, min1, min2, x, y) ({              \
    t1 min1 = (x);                                  \
    t2 min2 = (y);                                  \
    (void) (&min1 == &min2);                        \
    min1 < min2 ? min1 : min2;
})

#define __paste(a, b) a##b
#define __paste(a, b) ___paste(a, b)

#define __uniqueID(prefix) __paste(__paste(__uniqueID_, prefix), __COUNTER__)

#endif
