/* LitchyxOS/Include/ACPI/acexcept.h */
/**************************************************************************************
 *
 * Name: acoutput.h - Debug output.
 *
 **************************************************************************************/

#ifndef __ACOUTPUT_H__
#define __ACOUTPUT_H__

// Component IDs are used in the global "DebugLayer".
#define ACPI_UTILS              0x00000001
#define ACPI_HARDWARE           0x00000002
#define ACPI_EVENTS             0x00000004
#define ACPI_TABLES             0x00000008
#define ACPI_NAMESPACES         0x00000010
#define ACPI_PARSER             0x00000020
#define ACPI_DISPATCHER         0x00000040
#define ACPI_EXECUTOR           0x00000080
#define ACPI_RESOURCES          0x00000100
#define ACPI_CA_DEBUGGER        0x00000200
#define ACPI_OS_SERVICE         0x00000400
#define ACPI_CA_DISASSEMBLER    0x00000800

// Component IDs for ACPI tools and utilities.
#define ACPI_COMPILER           0x00001000
#define ACPI_TOOLS              0x00002000
#define ACPI_EXAMPLES           0x00004000
#define ACPI_DRIVER             0x00008000
#define DT_COMPILER             0x00010000
#define ASL_PREPROCESSOR        0x00020000

#define ACPI_ALL_COMPONENTS     0x0001FFFF
#define ACPI_COMPONENT_DEFAULT  (ACPI_ALL_COMPONENTS)

// Component IDs reserved for ACPI drivers.
#define ACPI_LV_INIT            0x00000001
#define ACPI_LV_DEBUG_OBJ       0x00000002
#define ACPI_LV_INFO            0x00000004
#define ACPI_LV_REPAIR          0x00000008
#define ACPI_LV_TRACE_POINT     0x00000010
#define ACPI_LV_ALL_EXCEPTS     0x0000001F

#endif

