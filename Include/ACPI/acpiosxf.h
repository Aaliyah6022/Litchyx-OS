/* LitchyxOS/Include/ACPI/acpiosxf.h */
/**************************************************************************
 *
 * Name: acpiosxf.h
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

#ifndef ACPI_USE_ALTERNARE_PROTOTYPE_acpiOSInit
acpiStatus acpiOSInit(void);

#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpiOSTermin
acpiStatus acpiOSTermin(void);

#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpiOSGetRootPtr
acpiPhysAddress acpiOSGetRootPtr(void);

#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpiOSPredefiendOverride
acpiStatus acpiOSPredefinedOverride(const struct acpiPredefinedName *init_val, acpiString *new_val);

#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpiOSTableOverride
acpiStatus acpiOSTableOverride(struct acpiTableHeader *existingTable, struct acpiTableHeader **newTable);

#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpiOSPhysTableOverride
acpiStatus acpiOSPhysTableOverride(struct acpiTableHeader *existingTable, acpiPhysAddress *newAddress, u32 *newTableLength);

#endif

/*
 * Spinlock primitives
 */

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpiOSCreateLock
acpiStatus acpiOSCreateLock(acpiSpinlock * out_handle);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpiOSDeleteLock
void acpiOSDeleteLock(acpiSpinlock handle);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpiOSAcquireLock
acpiCPUFlags acpiOSAcquireLock(acpiSpinLock handle);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpiOSReleaseLock
void acpiOSReleaseLock(acpiSpinlock handle, acpiCPUFlags flags);
#endif

/*
 * RAW spinlock primitives. If the OS does not provide them, fallback to
 * spinlock primitives
 */
#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_create_raw_lock
# define acpi_os_create_raw_lock(out_handle)	acpi_os_create_lock(out_handle)
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_delete_raw_lock
# define acpi_os_delete_raw_lock(handle)	acpi_os_delete_lock(handle)
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_acquire_raw_lock
# define acpi_os_acquire_raw_lock(handle)	acpi_os_acquire_lock(handle)
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_release_raw_lock
# define acpi_os_release_raw_lock(handle, flags)	\
	acpi_os_release_lock(handle, flags)
#endif

/*
 * Semaphore primitives
 */
#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_create_semaphore
acpi_status
acpi_os_create_semaphore(u32 max_units,
                         u32 initial_units, acpi_semaphore * out_handle);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_delete_semaphore
acpiStatus acpi_os_delete_semaphore(acpi_semaphore handle);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_wait_semaphore
acpiStatus
acpi_os_wait_semaphore(acpi_semaphore handle, u32 units, u16 timeout);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_signal_semaphore
acpiStatus acpi_os_signal_semaphore(acpi_semaphore handle, u32 units);
#endif

/*
 * Mutex primitives. May be configured to use semaphores instead via
 * ACPI_MUTEX_TYPE (see platform/acenv.h)
 */
#if (ACPI_MUTEX_TYPE != ACPI_BINARY_SEMAPHORE)

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_create_mutex
acpiStatus acpi_os_create_mutex(acpi_mutex * out_handle);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_delete_mutex
void acpi_os_delete_mutex(acpi_mutex handle);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_acquire_mutex
acpiStatus acpi_os_acquire_mutex(acpi_mutex handle, u16 timeout);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_release_mutex
void acpi_os_release_mutex(acpi_mutex handle);
#endif

#endif

/*
 * Memory allocation and mapping
 */
#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_allocate
void *acpi_os_allocate(acpi_size size);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_allocate_zeroed
void *acpi_os_allocate_zeroed(acpi_size size);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_free
void acpi_os_free(void *memory);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_map_memory
void *acpi_os_map_memory(acpi_physical_address where, acpi_size length);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_unmap_memory
void acpi_os_unmap_memory(void *logical_address, acpi_size size);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_get_physical_address
acpiStatus
acpi_os_get_physical_address(void *logical_address,
                             acpi_physical_address *physical_address);
#endif

/*
 * Memory/Object Cache
 */
#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_create_cache
acpiStatus
acpi_os_create_cache(char *cache_name,
                     u16 object_size,
                     u16 max_depth, acpi_cache_t ** return_cache);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_delete_cache
acpiStatus acpi_os_delete_cache(acpi_cache_t * cache);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_purge_cache
acpiStatus acpi_os_purge_cache(acpi_cache_t * cache);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_acquire_object
void *acpi_os_acquire_object(acpi_cache_t * cache);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_release_object
acpiStatus acpi_os_release_object(acpi_cache_t * cache, void *object);
#endif

/*
 * Interrupt handlers
 */
#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_install_interrupt_handler
acpiStatus
acpi_os_install_interrupt_handler(u32 interrupt_number,
                                  acpi_osd_handler service_routine,
                                  void *context);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_remove_interrupt_handler
acpiStatus
acpi_os_remove_interrupt_handler(u32 interrupt_number,
                                 acpi_osd_handler service_routine);
#endif

/*
 * Threads and Scheduling
 */
#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_get_thread_id
acpi_thread_id acpi_os_get_thread_id(void);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_execute
acpi_status
acpi_os_execute(acpi_execute_type type,
                acpi_osd_exec_callback function, void *context);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_wait_events_complete
void acpi_os_wait_events_complete(void);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_sleep
void acpi_os_sleep(u64 milliseconds);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_stall
void acpi_os_stall(u32 microseconds);
#endif

/*
 * Platform and hardware-independent I/O interfaces
 */
#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_read_port
acpiStatus acpi_os_read_port(acpi_io_address address, u32 *value, u32 width);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_write_port
acpiStatus acpi_os_write_port(acpi_io_address address, u32 value, u32 width);
#endif

/*
 * Platform and hardware-independent physical memory interfaces
 */
int acpi_os_read_iomem(void __iomem *virt_addr, u64 *value, u32 width);

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_read_memory
acpiStatus
acpi_os_read_memory(acpi_physical_address address, u64 *value, u32 width);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_write_memory
acpiStatus
acpi_os_write_memory(acpi_physical_address address, u64 value, u32 width);
#endif

/*
 * Platform and hardware-independent PCI configuration space access
 * Note: Can't use "Register" as a parameter, changed to "Reg" --
 * certain compilers complain.
 */
#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_read_pci_configuration
acpiStatus
acpi_os_read_pci_configuration(struct acpi_pci_id *pci_id,
                               u32 reg, u64 *value, u32 width);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_write_pci_configuration
acpiStatus
acpi_os_write_pci_configuration(struct acpi_pci_id *pci_id,
                                u32 reg, u64 value, u32 width);
#endif

/*
 * Miscellaneous
 */
#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_readable
u8 acpi_os_readable(void *pointer, acpi_size length);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_writable
u8 acpi_os_writable(void *pointer, acpi_size length);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_get_timer
u64 acpi_os_get_timer(void);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_signal
acpiStatus acpi_os_signal(u32 function, void *info);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_enter_sleep
acpiStatus acpi_os_enter_sleep(u8 sleep_state, u32 rega_value, u32 regb_value);
#endif

/*
 * Debug print routines
 */
#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_printf
ACPI_PRINTF_LIKE(1)
void ACPI_INTERNAL_VAR_XFACE acpi_os_printf(const char *format, ...);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_vprintf
void acpi_os_vprintf(const char *format, va_list args);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_redirect_output
void acpi_os_redirect_output(void *destination);
#endif

/*
 * Debug IO
 */
#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_get_line
acpiStatus acpi_os_get_line(char *buffer, u32 buffer_length, u32 *bytes_read);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_initialize_debugger
acpiStatus acpi_os_initialize_debugger(void);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_terminate_debugger
void acpi_os_terminate_debugger(void);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_wait_command_ready
acpiStatus acpi_os_wait_command_ready(void);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_notify_command_complete
acpiStatus acpi_os_notify_command_complete(void);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_trace_point
void acpi_os_trace_point(acpi_trace_event_type type,
                    u8 begin, u8 *aml, char *pathname);
#endif

/*
 * Obtain ACPI table(s)
 */
#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_get_table_by_name
acpiStatus
acpi_os_get_table_by_name(char *signature,
                          u32 instance,
                          struct acpi_table_header **table,
                          acpi_physical_address *address);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_get_table_by_index
acpiStatus
acpi_os_get_table_by_index(u32 index,
                           struct acpi_table_header **table,
                           u32 *instance, acpi_physical_address *address);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_get_table_by_address
acpiStatus acpi_os_get_table_by_address(acpi_physical_address address, struct acpi_table_header **table);
#endif

/*
 * Directory manipulation
 */
#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_open_directory
void *acpi_os_open_directory(char *pathname,
                             char *wildcard_spec, char requested_file_type);
#endif

/* request_file_type values */

#define REQUEST_FILE_ONLY                   0
#define REQUEST_DIR_ONLY                    1

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_get_next_filename
char *acpi_os_get_next_filename(void *dir_handle);
#endif

#ifndef ACPI_USE_ALTERNATE_PROTOTYPE_acpi_os_close_directory
void acpi_os_close_directory(void *dir_handle);
#endif

#endif

