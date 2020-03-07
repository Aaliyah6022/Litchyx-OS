/* LitchyxOS/Include/ACPI/acpiosxf.h */
/**************************************************************************
 *
 * Name: acpi_acpiosxf.h
 *
 *************************************************************************/

#ifndef __ACPIOSXF_H__
#define __ACPIOSXF_H__

#include <acpi/platform/acev.h>
#include <actypes.h>

typedef enum {
    OSL_GLOBAL_LOCK_HANDLER,
    OSL_NOTIFICATION_HANDLER,
    OSL_GPE_HANDLER,
    OSL_DBG_MAIN_THREAD,
    OSL_DBG_EXEC_THREAD,
    OSL_EC_POLL_HANDLER,
    OSL_EC_BURST_HANDLER
} acpiExecType;

#define ACPI_NO_UNITLIMIT                      ((u32) - 1)
#define ACPI_MUTEX_SEM                         1

#define ACPI_SIGNAL_FATAL                      0
#define ACPI_SIGNAL_BREAKPOINT                 1

struct acpiSignalFatalInfo {
    u32 type;
    u32 code;
    u32 argument;
};

