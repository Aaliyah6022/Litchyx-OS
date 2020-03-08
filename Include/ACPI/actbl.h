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

struct acpiRSDPExtension {
    u32 length;
    u64 xsdtPhysAddress;
    u8 extendedChecksum;
    u8 reversed[3];
};

struct acpiTblRsdt {
    struct acpiTableHeader header;
    u32 tableOffsetEntry[1];
};

struct acpiTblXsdt {
    struct acpiTableHeader header;
};

#define ACPI_RSDT_ENTRYSIZE                    (sizeof (u32))
#define ACPI_XSDT_ENTRYSIZE                    (sizeof (u64))

struct acpi_table_facs {
    char signature[4];
    u32 length;
    u32 hardware_signature;
    u32 firmware_waking_vector;
    u32 global_lock;
    u32 flags;
    u64 xfirmware_waking_vector;
    u8 version;
    u8 reserved[3];
    u32 ospm_flags;
    u8 reserved1[24];
};

/* Masks for global_lock flag field above */

#define ACPI_GLOCK_PENDING          (1)	/* 00: Pending global lock ownership */
#define ACPI_GLOCK_OWNED            (1<<1)	/* 01: Global lock is owned */

/* Masks for Flags field above  */

#define ACPI_FACS_S4_BIOS_PRESENT   (1)	/* 00: S4BIOS support is present */
#define ACPI_FACS_64BIT_WAKE        (1<<1)	/* 01: 64-bit wake vector supported (ACPI 4.0) */

/* Masks for ospm_flags field above */

#define ACPI_FACS_64BIT_ENVIRONMENT (1)	/* 00: 64-bit wake environment is required (ACPI 4.0) */

struct acpi_table_fadt {
    struct acpi_table_header header;	/* Common ACPI table header */
    u32 facs;		/* 32-bit physical address of FACS */
    u32 dsdt;		/* 32-bit physical address of DSDT */
    u8 model;		/* System Interrupt Model (ACPI 1.0) - not used in ACPI 2.0+ */
    u8 preferred_profile;	/* Conveys preferred power management profile to OSPM. */
    u16 sci_interrupt;	/* System vector of SCI interrupt */
    u32 smi_command;	/* 32-bit Port address of SMI command port */
    u8 acpi_enable;		/* Value to write to SMI_CMD to enable ACPI */
    u8 acpi_disable;	/* Value to write to SMI_CMD to disable ACPI */
    u8 s4_bios_request;	/* Value to write to SMI_CMD to enter S4BIOS state */
    u8 pstate_control;	/* Processor performance state control */
    u32 pm1a_event_block;	/* 32-bit port address of Power Mgt 1a Event Reg Blk */
    u32 pm1b_event_block;	/* 32-bit port address of Power Mgt 1b Event Reg Blk */
    u32 pm1a_control_block;	/* 32-bit port address of Power Mgt 1a Control Reg Blk */
    u32 pm1b_control_block;	/* 32-bit port address of Power Mgt 1b Control Reg Blk */
    u32 pm2_control_block;	/* 32-bit port address of Power Mgt 2 Control Reg Blk */
    u32 pm_timer_block;	/* 32-bit port address of Power Mgt Timer Ctrl Reg Blk */
    u32 gpe0_block;		/* 32-bit port address of General Purpose Event 0 Reg Blk */
    u32 gpe1_block;		/* 32-bit port address of General Purpose Event 1 Reg Blk */
    u8 pm1_event_length;	/* Byte Length of ports at pm1x_event_block */
    u8 pm1_control_length;	/* Byte Length of ports at pm1x_control_block */
    u8 pm2_control_length;	/* Byte Length of ports at pm2_control_block */
    u8 pm_timer_length;	/* Byte Length of ports at pm_timer_block */
    u8 gpe0_block_length;	/* Byte Length of ports at gpe0_block */
    u8 gpe1_block_length;	/* Byte Length of ports at gpe1_block */
    u8 gpe1_base;		/* Offset in GPE number space where GPE1 events start */
    u8 cst_control;		/* Support for the _CST object and C-States change notification */
    u16 c2_latency;		/* Worst case HW latency to enter/exit C2 state */
    u16 c3_latency;		/* Worst case HW latency to enter/exit C3 state */
    u16 flush_size;		/* Processor memory cache line width, in bytes */
    u16 flush_stride;	/* Number of flush strides that need to be read */
    u8 duty_offset;		/* Processor duty cycle index in processor P_CNT reg */
    u8 duty_width;		/* Processor duty cycle value bit width in P_CNT register */
    u8 day_alarm;		/* Index to day-of-month alarm in RTC CMOS RAM */
    u8 month_alarm;		/* Index to month-of-year alarm in RTC CMOS RAM */
    u8 century;		/* Index to century in RTC CMOS RAM */
    u16 boot_flags;		/* IA-PC Boot Architecture Flags (see below for individual flags) */
    u8 reserved;		/* Reserved, must be zero */
    u32 flags;		/* Miscellaneous flag bits (see below for individual flags) */
    struct acpi_generic_address reset_register;	/* 64-bit address of the Reset register */
    u8 reset_value;		/* Value to write to the reset_register port to reset the system */
    u16 arm_boot_flags;	/* ARM-Specific Boot Flags (see below for individual flags) (ACPI 5.1) */
    u8 minor_revision;	/* FADT Minor Revision (ACPI 5.1) */
    u64 Xfacs;		/* 64-bit physical address of FACS */
    u64 Xdsdt;		/* 64-bit physical address of DSDT */
    struct acpi_generic_address xpm1a_event_block;	/* 64-bit Extended Power Mgt 1a Event Reg Blk address */
    struct acpi_generic_address xpm1b_event_block;	/* 64-bit Extended Power Mgt 1b Event Reg Blk address */
    struct acpi_generic_address xpm1a_control_block;	/* 64-bit Extended Power Mgt 1a Control Reg Blk address */
    struct acpi_generic_address xpm1b_control_block;	/* 64-bit Extended Power Mgt 1b Control Reg Blk address */
    struct acpi_generic_address xpm2_control_block;	/* 64-bit Extended Power Mgt 2 Control Reg Blk address */
    struct acpi_generic_address xpm_timer_block;	/* 64-bit Extended Power Mgt Timer Ctrl Reg Blk address */
    struct acpi_generic_address xgpe0_block;	/* 64-bit Extended General Purpose Event 0 Reg Blk address */
    struct acpi_generic_address xgpe1_block;	/* 64-bit Extended General Purpose Event 1 Reg Blk address */
    struct acpi_generic_address sleep_control;	/* 64-bit Sleep Control register (ACPI 5.0) */
    struct acpi_generic_address sleep_status;	/* 64-bit Sleep Status register (ACPI 5.0) */
    u64 hypervisor_id;	/* Hypervisor Vendor ID (ACPI 6.0) */
};

/* Masks for FADT IA-PC Boot Architecture Flags (boot_flags) [Vx]=Introduced in this FADT revision */

#define ACPI_FADT_LEGACY_DEVICES    (1)  	/* 00: [V2] System has LPC or ISA bus devices */
#define ACPI_FADT_8042              (1<<1)	/* 01: [V3] System has an 8042 controller on port 60/64 */
#define ACPI_FADT_NO_VGA            (1<<2)	/* 02: [V4] It is not safe to probe for VGA hardware */
#define ACPI_FADT_NO_MSI            (1<<3)	/* 03: [V4] Message Signaled Interrupts (MSI) must not be enabled */
#define ACPI_FADT_NO_ASPM           (1<<4)	/* 04: [V4] PCIe ASPM control must not be enabled */
#define ACPI_FADT_NO_CMOS_RTC       (1<<5)	/* 05: [V5] No CMOS real-time clock present */

#define FADT2_REVISION_ID               3

/* Masks for FADT ARM Boot Architecture Flags (arm_boot_flags) ACPI 5.1 */

#define ACPI_FADT_PSCI_COMPLIANT    (1)	/* 00: [V5+] PSCI 0.2+ is implemented */
#define ACPI_FADT_PSCI_USE_HVC      (1<<1)	/* 01: [V5+] HVC must be used instead of SMC as the PSCI conduit */

/* Masks for FADT flags */

#define ACPI_FADT_WBINVD            (1)	/* 00: [V1] The WBINVD instruction works properly */
#define ACPI_FADT_WBINVD_FLUSH      (1<<1)	/* 01: [V1] WBINVD flushes but does not invalidate caches */
#define ACPI_FADT_C1_SUPPORTED      (1<<2)	/* 02: [V1] All processors support C1 state */
#define ACPI_FADT_C2_MP_SUPPORTED   (1<<3)	/* 03: [V1] C2 state works on MP system */
#define ACPI_FADT_POWER_BUTTON      (1<<4)	/* 04: [V1] Power button is handled as a control method device */
#define ACPI_FADT_SLEEP_BUTTON      (1<<5)	/* 05: [V1] Sleep button is handled as a control method device */
#define ACPI_FADT_FIXED_RTC         (1<<6)	/* 06: [V1] RTC wakeup status is not in fixed register space */
#define ACPI_FADT_S4_RTC_WAKE       (1<<7)	/* 07: [V1] RTC alarm can wake system from S4 */
#define ACPI_FADT_32BIT_TIMER       (1<<8)	/* 08: [V1] ACPI timer width is 32-bit (0=24-bit) */
#define ACPI_FADT_DOCKING_SUPPORTED (1<<9)	/* 09: [V1] Docking supported */
#define ACPI_FADT_RESET_REGISTER    (1<<10)	/* 10: [V2] System reset via the FADT RESET_REG supported */
#define ACPI_FADT_SEALED_CASE       (1<<11)	/* 11: [V3] No internal expansion capabilities and case is sealed */
#define ACPI_FADT_HEADLESS          (1<<12)	/* 12: [V3] No local video capabilities or local input devices */
#define ACPI_FADT_SLEEP_TYPE        (1<<13)	/* 13: [V3] Must execute native instruction after writing  SLP_TYPx register */
#define ACPI_FADT_PCI_EXPRESS_WAKE  (1<<14)	/* 14: [V4] System supports PCIEXP_WAKE (STS/EN) bits (ACPI 3.0) */
#define ACPI_FADT_PLATFORM_CLOCK    (1<<15)	/* 15: [V4] OSPM should use platform-provided timer (ACPI 3.0) */
#define ACPI_FADT_S4_RTC_VALID      (1<<16)	/* 16: [V4] Contents of RTC_STS valid after S4 wake (ACPI 3.0) */
#define ACPI_FADT_REMOTE_POWER_ON   (1<<17)	/* 17: [V4] System is compatible with remote power on (ACPI 3.0) */
#define ACPI_FADT_APIC_CLUSTER      (1<<18)	/* 18: [V4] All local APICs must use cluster model (ACPI 3.0) */
#define ACPI_FADT_APIC_PHYSICAL     (1<<19)	/* 19: [V4] All local xAPICs must use physical dest mode (ACPI 3.0) */
#define ACPI_FADT_HW_REDUCED        (1<<20)	/* 20: [V5] ACPI hardware is not implemented (ACPI 5.0) */
#define ACPI_FADT_LOW_POWER_S0      (1<<21)	/* 21: [V5] S0 power savings are equal or better than S3 (ACPI 5.0) */

/* Values for preferred_profile (Preferred Power Management Profiles) */

enum acpi_preferred_pm_profiles {
    PM_UNSPECIFIED = 0,
    PM_DESKTOP = 1,
    PM_MOBILE = 2,
    PM_WORKSTATION = 3,
    PM_ENTERPRISE_SERVER = 4,
    PM_SOHO_SERVER = 5,
    PM_APPLIANCE_PC = 6,
    PM_PERFORMANCE_SERVER = 7,
    PM_TABLET = 8
};

/* Values for sleep_status and sleep_control registers (V5+ FADT) */

#define ACPI_X_WAKE_STATUS          0x80
#define ACPI_X_SLEEP_TYPE_MASK      0x1C
#define ACPI_X_SLEEP_TYPE_POSITION  0x02
#define ACPI_X_SLEEP_ENABLE         0x20

/* Reset to default packing */

#pragma pack()

/*
 * Internal table-related structures
 */
union acpi_name_union {
    u32 integer;
    char ascii[4];
};

/* Internal ACPI Table Descriptor. One per ACPI table. */

struct acpi_table_desc {
    acpi_physical_address address;
    struct acpi_table_header *pointer;
    u32 length;		/* Length fixed at 32 bits (fixed in table header) */
    union acpi_name_union signature;
    acpi_owner_id owner_id;
    u8 flags;
    u16 validation_count;
};

#define ACPI_MAX_TABLE_VALIDATIONS          ACPI_UINT16_MAX


#define ACPI_TABLE_ORIGIN_EXTERNAL_VIRTUAL  (0)	/* Virtual address, external maintained */
#define ACPI_TABLE_ORIGIN_INTERNAL_PHYSICAL (1)	/* Physical address, internally mapped */
#define ACPI_TABLE_ORIGIN_INTERNAL_VIRTUAL  (2)	/* Virtual address, internallly allocated */
#define ACPI_TABLE_ORIGIN_MASK              (3)
#define ACPI_TABLE_IS_VERIFIED              (4)
#define ACPI_TABLE_IS_LOADED                (8)

/*
 * Get the remaining ACPI tables
 */
#include <acpi/actbl1.h>
#include <acpi/actbl2.h>
#include <acpi/actbl3.h>

#define ACPI_FADT_OFFSET(f)             (u16) ACPI_OFFSET (struct acpi_table_fadt, f)

#define ACPI_FADT_V1_SIZE       (u32) (ACPI_FADT_OFFSET (flags) + 4)
#define ACPI_FADT_V2_SIZE       (u32) (ACPI_FADT_OFFSET (minor_revision) + 1)
#define ACPI_FADT_V3_SIZE       (u32) (ACPI_FADT_OFFSET (sleep_control))
#define ACPI_FADT_V5_SIZE       (u32) (ACPI_FADT_OFFSET (hypervisor_id))
#define ACPI_FADT_V6_SIZE       (u32) (sizeof (struct acpi_table_fadt))

#define ACPI_FADT_CONFORMANCE   "ACPI 6.1 (FADT version 6)"

#endif

