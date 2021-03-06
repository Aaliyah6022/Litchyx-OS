/* LitchyxOS/Include/ACPI/acconfig.h */
/*******************************************************
 *
 * Name: acconfig.h - Global configuration constants.
 *
 *******************************************************/

#ifndef __ACCONFIG_H__
#define __ACCONFIG_H__

#define ACPI_OS_NAME                    "LitchyxOS"

/* Below are objects in the various object caches */

#define ACPI_MAX_STATE_CACHE_DEPTH        96
#define ACPI_MAX_PARSE_CACHE_DEPTH        96
#define ACPI_MAX_EXTPARSE_CACHE_DEPTH     96
#define ACPI_MAX_OBJECT_CACHE_DEPTH       96
#define ACPI_MAX_NAMESPACE_CACHE_DEPTH    96
#define ACPI_MAX_COMMENT_CACHE_DEPTH      96

/* Should the sub-system abort the loading of an ACPI table if the
 * table checksum is INCORRECT?
 */
#ifndef ACPI_CHECKSUM_ABORT
#define ACPI_CHECKSUM_ABORT               FALSE
#endif

/* Generation of a version of the ACPICA that only supports so-called
 * "reduced hardware" platforms (as defined in ACPI 5.0). Set to TRUE
 * to generate a specialized version of ACPICA that ONLY supports the
 * ACPI 5.0 "reduced hardware" model. In other words, no ACPI hardware
 * is going to be supported.
 *
 * If this value is set to TRUE, the followings are no longer supported:
 *     PM event and Control registers;
 *     SCI interrupt and handler;
 *     Foxed Events;
 *     GPEs;
 *     Global Lock;
 *     ACPI PM timer;
 *     FACS table*/
#ifndef ACPI_REDUCED_HARDWARE
#define ACPI_REDUCED_HARDWARE            FALSE
#endif

/* Sub-system constants */
#define ACPI_CA_SUPPORT_LEVEL            5
#define ACPI_MAX_SMEAPHORE_COUNT         256
#define ACPI_MAX_REFERENCE_COUNT         0x4000
#define ACPI_DEFAULT_PAGE_SIZE           4
#define ACPI_NUM_OWNERID_MASKS           128
#define ACPI_ROOT_TABLE_SIZE_INCREMENT   4
#define ACPI_MAX_SLEEP                   4000 // 400 milliseconds == 4 seconds
#define ACPI_ADDRESS_RANGE_MAX           2
#define ACPI_MAX_LOOP_TIMEOUT            30

/* ACPI specification constants */
#define ACPI_METHOD_NUM_LOCALS           8
#define ACPI_METHOD_MAX_LOCALS           7
#define ACPI_METHOD_NUM_ARGS             7
#define ACPI_METHOD_MAX_ARGS             6

#define ACPI_OBJ_NUM_OPERANDS            8
#define ACPI_OBJ_MAX_OPERANDS            7

#define ACPI_RESULTS_FRAME_OBJ_NUM       8

#define ACPI_EBDA_PTR_LOCATION           0x0000040E // This is an actual, physical address.
#define ACPI_EBDA_PTR_LENGTH             2
#define ACPI_EBDA_WINDOW_SIZE            1024
#define ACPI_HI_RSDP_WINDOW_BASE         0x000E0000 // This is an actual, physical address.
#define ACPI_HI_RSDP_WINDOW_SIZE         0x00020000
#define ACPI_RSDO_SCAN_STEP              16

#define ACPI_USER_REGION_BEGIN           0x80

#define ACPI_MAX_ADDRESS_SPACE           255
#define ACPI_NUM_DEFAULT_SPACES          4

#define ACPI_MAX_MATCH_OPCODE            5

#define ACPI_RSDP_CHECKSUM_LENGTH        20
#define ACPI_RSDP_XCHECKSUM_LENGTH       36

#define ACPI_SERIAL_HEADER_SIZE          2

#define ACPI_SMBUS_DATA_SIZE             32
#define ACPI_SMBUS_BUFFER_SIZE           ACPI_SERIAL_HEADER_SIZE + ACPI_SMBUS_DATA_SIZE

#define ACPI_NUM_SX_D_METHODS            4
#define ACPI_NUM_SX_W_METHODS            5

/* Miscellaneous constants */
#define UUID_BUFFER_LENGTH               16 // Length of UUID inside the memory
#define UUID_STRING_LENGTH               36 // Total length of a UUID string

#define UUID_HYPHEN1_OFFSET              8
#define UUID_HYPHEN2_OFFSET              13
#define UUID_HYPHEN3_OFFSET              18
#define UUID_HYPHEN4_OFFSET              23

/* ACPI AML Debugger */
#define ACPI_DEBUGGER_MAX_ARGS           ACPI_METHOD_NUM_ARGS + 4 // Maximum command line arguments
#define ACPI_DB_LINE_BUFFER_SIZE         512

#define ACPI_DEBUGGER_COMMAND_PROMPT     'cd'
#define ACPI_DEBUGGER_EXECUTE_PROMPT     '%'

#endif

