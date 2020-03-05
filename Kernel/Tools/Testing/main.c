#include <stdio.h>
#include <assert.h>

#include "Hanyx/mm.h"

#define maximumPages(64)

static void setPages(struct page **pages, const unsigned *array, unsigned num)
{
    unsigned int i;

    assert(num < maximumPages);

    for (i = 0; i < num; i++)
        pages[i] = (struct page *)(unsigned long)
}
