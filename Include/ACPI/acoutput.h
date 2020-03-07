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
#define ACPI_LV_TRACEPOINT      0x00000010
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

// Global trace flags
#define ACPI_TRACE_ENABLED      ((u32) 4)
#define ACPI_TRACE_1SHOT        ((u32) 2)
#define ACPI_TRACE_OP_CODE      ((u32) 1)

// Default values for trace debugging level/layer
#define ACPI_TRACE_LVL_ALL      ACPI_LV_ALL
#define ACPI_TRACE_LAYER_ALL    0x000001FF
#define ACPI_TRACE_LVL_DEFAULT  ACPI_LV_TRACEPOINT
#define ACPI_TRACE_LAYER_ALL    ACPI_EXECUTOR

#if defined (ACPI_DEBUG_OUTPUT) || !defined (ACPI_NO_ERR_MSG)

#define ACPI_MODULE_NAME(name)  static const char ACPI_UNUSED_VAR _acpi_module_name[] = name;
#else

#define ACPI_MODULE_NAME(name)
#define _acpi_module_name ""
#endif

// ASCII error messages can be configured out.

#ifndef ACPI_NO_ERR_MSG
#define _INFO                   _acpi_module_name, __LINE__

// An error occurred. Below are the error reports.
#define ACPI_INFO(plist)        acpi_info(plist)
#define ACPI_WARNING(plist)     acpi_warning(plist)
#define ACPI_EXCEPT(plist)      acpi_exception(plist)
#define ACPI_ERROR(plist)       acpi_error(plist)
#define ACPI_BIOS_WARN(plist)   acpi_bios_warning(plist)
#define ACPI_BIOS_EXCEPT(plist) acpi_bios_exception(plist)
#define ACPI_BIOS_ERR(plist)    acpi_bios_error(plist)
#define ACPI_DBG_OBJ(obj, l, i) acpi_debug_object(obj, l, i)

#else // No errors ocurred.
#define ACPI_INFO(plist)
#define ACPI_WARNING(plist)
#define ACPI_EXCEPT(plist)
#define ACPI_ERROR(plist)
#define ACPI_BIOS_WARN(plist)
#define ACPI_BIOS_EXCEPT(plist)
#define ACPI_BIOS_ERR(plist)
#define ACPI_DBG_OBJ(obj, l, i)

// debug marcos that are conditionally compiled
#ifdef ACPI_DEBUG_OUTPUT

#ifndef ACPI_GET_FUNCTION_NAME
#define ACPI_GET_FUNCTIONL_NAME _acpi_function_name

#define ACPI_FUNCTION_NAME(name) static const char _acpi_function_name[] = #name;

#else

#define ACPI_FUNCTION_NAME(name)
#endif

#define ACPI_DEBUG_PARAMS \
        __LINE__, ACPI_GET_FUNCTION_NAME, _acpi_module_name, _COMPONENT

#define ACPI_IS_DBG_ENABLED(level, component) \
        ((level & acpi_debug_level) && (component & acpi_debug_layer))

#ifdef ACPI_USE_DOWHILE0
#define ACPI_DOWHILE0(a)
#else
#define ACPI_DOWHILE0(a)         a
#endif

#ifndef COMPILER_VA_MACRO
#define ACPI_DBG_PRINT(plist)    acpi_debug_print(plist)
#define ACPI_DBG_PRINTRAW(plist) acpi_debug_printraw(plist)

#else

#define ACPI_DO_DBG_PRINT(func, lvl, line, filename, modulename, component, ...) \
        ACPI_DOWHILE0 ({ \
            if (ACPI_IS_DBG_ENABLED (lvl, component)) \
            { \
                function (lvl, line, filename, modulename, component, __VA_ARGS__); \
            } \
        })

#define ACPI_ACTUAL_DBG (lvl, line, filename, modulename, component, ...) \
        ACPI_DO_DBG_PRINT (acpi_debug_print, lvl, line,  \
                filename, modulename, component, __VA_ARGS__)

#define ACPI_ACTUAL_DBG_RAW (lvl, line, filename, modulename, component, ...) \
        ACPI_DO_DBG_PRINTRAW (acpi_debug_printraw, lvl, line \
                filename, modulename, component, __VA_ARGS__)

#define ACPI_DBG_PRINT(plist)    ACPI_ACTUAL_DBG plist
#define APCI_DBG_PRINTRAW(plist) ACPI_ACTUAL_DBG_RAW plist

#endif

#define ACPI_TRACE_ENTRY(name, function, type, param) \
        ACPI_FUNCTION_NAME(name) \
        function (ACPI_DBG_PARAMS, (type) param)

// Actual entry trace macros
#define ACPI_FUNC_TRACE(name) \
        ACPI_FUNCTION_NAME(name) \
        acpi_ut_trace (ACPI_DEBUG_PARAMS)

#define ACPI_FUNC_TRACE_PTR (name, pointer) \
        ACPI_TRACE_ENTRY (name, acpi_ut_trace_ptr, void *, pointer)

#define ACPI_FUNC_TRACE_U32 (name, value) \
        ACPI_TRACE_ENTRY (name, acpi_ut_trace_u32, value) \

#define ACPI_FUNC_TRACE_STR (name, string) \
        ACPI_TRACE_ENTRY (name, acpi_ut_trace_str, const char *, string)

#define ACPI_FUNC_ENTRY() \
        acpi_ut_track_ptr()

// Function exit tracing
#ifndef ACPI_SIMPLE_RETURN_MACROS

#define ACPI_TRACE_EXIT(function, type, param) \
        ACPI_DOWHILE0 ({ \
            register type _param = (type) (param); \
            function (ACPI_DEBUG_PARAMS, _param); \
            return (_param); \
        })
#else

#define ACPI_TRACE_EXIT(function, type, param) \
        ACPI_DOWHILE0 ({ \
            register type _param = (type) (param); \
            function (ACPI_DEBUG_PARAMS, _param); \
            return (_param); \
        })
#endif

// Exit macros

#define RETURN_VOID \
        ACPI_DOWHILE0 ({ \
            acpi_ut_exit (ACPI_DEBUG_PARAMS); \
            return; \
        })

#define RETURN_ACPI_STATUS(status) \
        ACPI_TRACE_EXIT(acpi_ut_status_exit, acpi_status, status)

#define RETURN_PTR(pointer) \
        ACPI_TRACE_EXIT(acpi_ut_ptr_exit, void *, pointer)

#define RETURN_STR(string) \
        ACPI_TRACE_EXIT(acpi_ut_str_exit, const char *, string)

#define RETURN_VALUE(value) \
        ACPI_TRACE_EXIT(acpi_ut_value_exit, u64, value)

#define RETURN_UINT32(value) \
        ACPI_TRACE_EXIT(acpi_ut_value_exit, u32, value)

#define RETURN_UINT8(value) \
        ACPI_TRACE_EXIT(acpi_ut_value_exit, u8, value)

// Conditional executions

#endif

