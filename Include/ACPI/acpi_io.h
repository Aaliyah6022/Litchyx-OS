/* LitchyxOS/Include/ACPI/acpi.h */
/**************************************************************************
 *
 * Name: acpi_io.h
 *
 *************************************************************************/

#ifndef __ACPI_IO_H__
#define __ACPI_IO_H__

#include <Litchyx/io.h>
#include <Assembly/acpi.h>

#ifndef acpiOSIORemap
static inline void __IOMemory *acpiOSRemap(acpiPhysicalAddress physicalAddress, acpiSize size)
{
    return IORemapCache(physicalAddress, size);
}

extern bool acpiPermanentMMap;

void __IOMemory __ref
*acpiOSMapIOMemory(acpiPhysicalAddress physicalAddress, acpiSize size);
void __ref acpiISUnmapIOMemory(void __IOMemory *virt, acpiSize size);
void __ioMemory *acpiOSGetOPMemory(acpiPhysicalAddress physicalAddress, unsigned int size);

int acpiOSMapGenericAddress(struct acpiGenericAddress *address);
void acpiOSUnmapGenericAddress(struct acpiGenericAddress *address);

#endif
