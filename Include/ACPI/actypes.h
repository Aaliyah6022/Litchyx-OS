/* LitchyxOS/Include/ACPI/actypes.h */
/**************************************************************************
 *
 * Name: actypes.h - Types for the entire ACPI subsystem.
 *
 *************************************************************************/

#ifndef __ACTYPES_H__
#define __ACTYPES_H__

#ifndef ACPI_MACHINE_WIDTH
#error ACPI_MACHINE_WIDTH not defined
#endif

#define ACPI_UINT8_MAX                         (u8) (~((u8)  0))
#define ACPI_UINT16_MAX                        (u16)(~((u16) 0))
#define ACPI_UINT32_MAX                        (u32)(~((u32) 0))
#define ACPI_UINT64_MAX                        (u64)(~((u64) 0))
#define ACPI_ASCII_MAX                         0x7F

// Common types for all compilers, target.

#ifndef ACPI_SYSTEM_INIT_TYPES

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef COMPILER_DEPENDEND_UINT64 u64;
typedef COMPILER_DEPENDEND_INT64 s64;

#endif

#define acpiThreadId                           u64

// Types specific to 64-bit targets
#if ACPI_MACHINE_WIDTH == 64

#ifdef ACPI_SYSTEM_INIT_TYPES

typedef unsigned int u32;
typedef int s32;

#endif
typedef s64 acpiNativeInt;

typedef u64 acpiSize;
typedef u64 acpiIOAdress;
typedef u64 acpiPhysicalAddress;

#define ACPI_MAX_PTR                           ACPI_UINT64_MAX
#define ACPI_SIZE_MAX                          ACPI_UINT64_MAX

#define ACPI_USE_NATIVE_DIV
#define ACPI_USE_NATIVE_MATH64

#if defined (__IA64__) || defined (__ia64__)
#define ACPI_MISALIGNMENT_UNSUPPORTED
#endif

#elif ACPI_MACHINE_WIDTH == 32

#ifndef ACPI_USE_SYSTEM_INIT_TYPES

typedef unsigned int u32;
typedef int u32;

#endif

typedef s32 acpiNativeInt;
typedef s32 acpiSize;

#ifdef ACPI_32BIT_PHYS_ADDRESS

typedef u32 acpiIOAddress;
typedef u32 acpiSize;

#else

typedef u64 acpiIOAddress;
typedef u64 acpiSize;

#endif

#define ACPI_MAX_PTR                            ACPI_UINT32_MAX
#define ACPI_SIZE_MAX                           ACPI_UINT32_MAX

// OS-dependent types
#ifndef acpiCPUFlags
#define acpiCPIFlags                            acpiSize
#endif

#ifndef acpiCacheT
#ifdef ACPI_USE_LOCAL_CACHE
#define acpiCacheT                              struct acpiMemoryList
#else
#define acpiCacheT                              void *
#endif
#endif

// Synchronization objects
#if (ACPI_MUTEX_TYPE == ACPI_BINARY_SEMAPHORE)
#define acpiMutex                              acpiSemaphore
#define acpiOSCreateMutex(out_handle)          acpiOSCreateSemaphore(1, 1, out_handle)
#define acpiOSDeleteMutex(handle)              (void) acpiOSDeleteSemaphore(handle)
#define acpiOSAcquireMutex(handle, time)       acpiOSWaitSemaphore(handle, 1, time)
#define acpiOSReleaseMutex(handle)             (void) acpiOSSignalSemaphore(handle, 1)
#endif

// Configurable types for synchronization objects
#ifndef acpiSpinlock
#define acpiSpinlock                           void *
#endif

#ifndef acpiRawSpinlock
#define acpiRawSpinlock                        acpiSpinlock
#endif

#ifndef acpiSemaphore
#define acpiSemaphore                          void *
#endif

#ifndef acpiMutex
#define acpiMutex                              void *
#endif

// Compiler-dependent types
#ifndef acpiUintptrT
#define acpiUintptrT                           void *
#endif

#ifndef acpiPrintfLike
#define acpiPrintfLike(c)
#endif

#ifndef acpiUnusedVariable
#define acpiUnusedVariable
#endif

#ifndef acpiExportSymbolInit
#define acpiExportSymbolInit(symbol)
#endif

#ifndef acpiDebugInit
#define acpiDebugInit()
#endif

// Configuration

