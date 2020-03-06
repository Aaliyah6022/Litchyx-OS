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
#define ACPI_ALL_DRIVERS        0xFFFF0000

// Raw debug output levels, do not use these in the ACPI_DEBUG_PRINT marcos.
#define ACPI_LV_INIT            0x00000001
#define ACPI_LV_DEBUG_OBJ       0x00000002
#define ACPI_LV_INFO            0x00000004
#define ACPI_LV_REPAIR          0x00000008
#define ACPI_LV_TRACE_POINT     0x00000010
#define ACPI_LV_ALL_EXCEPTS     0x0000001F

// Trace verbosity Level 1 [Standard Trace Level]
#define ACPI_LV_INIT_NAMES      0x00000020
#define ACPI_LV_PARSE           0x00000040
#define ACPI_LV_LOAD            0x00000080
#define ACPI_LV_DISPATCH        0x00000100
#define ACPI_LV_EXEC            0x00000200
#define ACPI_LV_NAMES           0x00000400
#define ACPI_LV_OP_REGION       0x00000800
#define ACPI_LV_BFIELD          0x00001000
#define ACPI_LV_TABLES          0x00002000
#define ACPI_LV_VALUES          0x00004000
#define ACPI_LV_OBJ             0x00008000
#define ACPI_LV_RES             0x00010000
#define ACPI_LV_USER_REQ        0x00020000
#define ACPI_LV_PACKAGE         0x00040000
#define ACPI_LV_EVALUATE        0x00080000
#define ACPI_LV_VERBOSITY1      0x000FFF40 | ACPI_LV_ALL_EXCEPTS

// Trace verbosity level 2 [Function tracing and memory allocation]
#define ACPI_LV_ALLOCATION      0x00100000
#define ACPI_LV_FUNC            0x00200000
#define ACPI_LV_OPTIMIZE        0x00400000
#define ACPI_LV_PARSETREE       0x00800000
#define ACPI_LV_VERBOSITY2      0x00F00000 | ACPI_LV_VERBOSITY1
#define ACPI_LV_ALL             ACPI_LV_VERBOSITY2

// Trace verbosity level 3 [Threading, IO and Interrupts]
#define ACPI_LV_MUTEX              0x01000000
#define ACPI_LV_THREADS         0x02000000
#define ACPI_LV_IO              0x04000000
#define ACPI_LV_INTERRUPT       0x08000000
#define ACPI_LV_VERBOSITY       0x0F000000 | ACPI_LV_VERBOSITY2

// Exceptionally verbose output -- also used in the global "DebugLevel"
#define ACPI_LV_AML_DISASSEMBLE 0x10000000
#define ACPI_LV_VERBOSE_INFO    0x20000000
#define ACPI_LV_FULL_TBL        0x40000000
#define ACPI_LV_EVENTS          0x80000000
#define ACPI_LV_VERBOSE         0xF0000000

// Debug level marcos that are used in the DEBUG_PRINT marcos
#define ACPI_DEBUG_LEVEL(dl)    (u32) dl, ACPI_DEBUG_PARAMETERS

// Exception Level
#define ACPI_DB_INIT            ACPI_DEBUG_LEVEL(ACPI_LV_INIT)
#define ACPI_DB_DEBUG_OBJ       ACPI_DEBUG_LEVEL(ACPI_LV_DEBUG_OBJ)
#define ACPI_DB_INFO            ACPI_DEBUG_LEVEL(ACPI_LV_INFO)
#define ACPI_DB_REPAIR          ACPI_DEBUG_LEVEL(ACPI_LV_REPAIR)
#define ACPI_DB_TRACEPOINT      ACPI_DEBUG_LEVEL(ACPI_LV_TRACE_POINT)
#define ACPI_DB_ALL_EXCEPTS     ACPI_DEBUG_LEVEL(ACPI_LV_ALL_EXCEPTS)

// Trace Level
#define ACPI_DB_INIT_NAMES      ACPI_DEBUG_LEVEL(ACPI_LV_INIT_NAMES)
#define ACPI_DB_THREADS         ACPI_DEBUG_LEVEL(ACPI_LV_THREADS)
#define ACPI_DB_PARSE           ACPI_DEBUG_LEVEL(ACPI_LV_PARSE)
#define ACPI_DB_DISPATCH        ACPI_DEBUG_LEVEL(ACPI_LV_DISPATCH)
#define ACPI_DB_LOAD            ACPI_DEBUG_LEVEL(ACPI_LV_LOAD)
#define ACPI_DB_EXEC            ACPI_DEBUG_LEVEL(ACPI_LV_EXEC)
#define ACPI_DB_NAMES           ACPI_DEBUG_LEVEL(ACPI_LV_NAMES)
#define ACPI_DB_OP_REGION       ACPI_DEBUG_LEVEL(ACPI_LV_OP_REGION)
#define ACPI_DB_BFIELD          ACPI_DEBUG_LEVEL(ACPI_LV_BFIELD)
#define ACPI_DB_TABLES          ACPI_DEBUG_LEVEL(ACPI_LV_TABLES)
#define ACPI_DB_FUNC            ACPI_DEBUG_LEVEL(ACPI_LV_FUNC)
#define ACPI_DB_OPTIMIZE        ACPI_DEBUG_LEVEL(ACPI_LV_OPTIMIZE)
#define ACPI_DB_PARSETREE       ACPI_DEBUG_LEVEL(ACPI_LV_PARSETREE)
#define ACPI_DB_VALUES          ACPI_DEBUG_LEVEL(ACPI_LV_VALUES)
#define ACPI_DB_OBJ             ACPI_DEBUG_LEVEL(ACPI_LV_OBJ)
#define ACPI_DB_ALLOCATION      ACPI_DEBUG_LEVEL(ACPI_LV_ALLOCATION)
#define ACPI_DB_RES             ACPI_DEBUG_LEVEL(ACPI_LV_RES)
#define ACPI_DB_IO              ACPI_DEBUG_LEVEL(ACPI_LV_IO)
#define ACPI_DB_INTERRUPT       ACPI_DEBUG_LEVEL(ACPI_LV_INTERRUPT)
#define ACPI_DB_USER_REQ        ACPI_DEBUG_LEVEL(ACPI_LV_USER_REQ)
#define ACPI_DB_PACKAGE         ACPI_DEBUG_LEVEL(ACPI_LV_PACKAGE)
#define ACPI_DB_EVALUATE        ACPI_DEBUG_LEVEL(ACPI_LV_EVALUATE)
#define ACPI_DB_MUTEX           ACPI_DEBUG_LEVEL(ACPI_LV_MUTEX)
#define ACPI_DB_EVENTS          ACPI_DEBUG_LEVEL(ACPI_LV_EVENTS)

#define ACPI_DB_ALL             ACPI_DEBUG_LEVEL(ACPI_LV_ALL)

// Defaults for debug_level, debug and normal

#ifndef ACPI_DEBUG_DEFAULT
#define ACPI_DEBUG_DEFAULT      (ACPI_LV_INIT | ACPI_LV_DEBUG_OBJ | ACPI_LV_EVALUATE | ACPI_LV_REPAIR)
#endif

#define ACPI_NORMAL_DEFAULT     (ACPI_LV_INIT | ACPI_LV_DEBUG_OBJ | ACPI_LV_REPAIR)
#define ACPI_DEBUG_ALL          (ACPI_LV_AML_DISASSEMBLE | ACPI_LV_ALL_EXCEPTS | ACPI_LV_ALL)

#endif

