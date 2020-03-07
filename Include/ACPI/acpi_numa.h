/* LitchyxOS/Include/ACPI/acpi_numa.h */
/**************************************************************************
 *
 * Name: acpi_numa.h
 *
 *************************************************************************/

#ifndef __ACPI_NUMA_H__
#define __ACPI_NUMA_H__

#ifdef CONFIG_ACPI_NUMA
#include <Litchyx/kernel.h>
#include <Litchyx/numa.h>

// Proximity bitmap length
#if MAX_NUMA_NODES > 256
#define MAX_PXM_DOMAINS                        MAX_NUMA_NODES
#else
#define MAX_PXM_DOMAINS (256)
#endif

extern int pxmToNode(int);
extern int nodeToPxm(int);
extern int acpiMapPxmToNode(int);
extern unsigned char acpiSratRevision;
extern int acpiNuma __initData;

extern void badSrat(void);
extern int sratDisabled(void);

#endif

#endif

