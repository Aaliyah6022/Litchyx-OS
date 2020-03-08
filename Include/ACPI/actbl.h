/* LitchyxOS/Include/ACPI/actbl.h */
/**************************************************************************
 *
 * Name: actbl.h
 *
 *************************************************************************/

#ifndef __ACTBL_H__
#deifne __ACTBL_H__

#define ACPI_SIG_DSDT                          "DSDT"
#define ACPI_SIG_FADT                          "FADT"
#define ACPI_SIG_FACS                          "FACS"
#define ACPI_SIG_OSDT                          "OSDT"
#define ACPI_SIG_PSDT                          "PSDT"
#define ACPI_SIG_DSDT                          "DSDT"
#define ACPI_SIG_RSDP                          "RSDP PTR"
#define ACPI_SIG_XSDP                          "XSDP"
#define ACPI_SIG_SSDT                          "SSDT"
#define ACPI_RSDP_NAME                         "RSDP"
#define ACPI_OEM_NAME                          "OEM"

#pragma pack(1)

struct acpiTableHeader {
    char signature[ACPI_NAMESEG_SIZE];
    u32 length;
    u8 revision;
    u8 checksum;
    char oem_id[ACPI_OEM_ID_SZE];
    char oem_table_id[ACPI_OEM_TBL_ID_SIZE];
    u32 oem_revision;
    char asl_compiler_id[CPI_NAMESEG_SIZE];
    u32 asl_compiler_revision;
};

struct acpiGenericAddress {
    u8 spaceID;
    u8 bitWidth;
    u8 bitOffset;
    u8 accessWidth;
    u64 address;
};

struct acpiTblRsdp {
    char signature[8];
    u8 checksum;
    char oem_id[ACPI_OEM_ID_SZE];
    u8 revision;
    u32 rsdtPhysAddress;
    u32 length;
    u64 xsdtPhysAddress;
};

