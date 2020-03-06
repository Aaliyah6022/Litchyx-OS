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

#endif

