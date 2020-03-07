/* LitchyxOS/Include/ACPI/acpi.h */
/**************************************************************************
 *
 * Name: acpi.h - Master public include file used to interface ACPICA
 *
 *************************************************************************/

#ifndef __ACPI_DRIVERS_H__
#define __ACPI_DRIVERS_H__

#define ACPI_MAX_STR                           80

#define ACPI_BUS_COMPONENT                     0x00010000
#define ACPI_AC_COMPONENT                      0x00020000
#define ACPI_BATTERY_COMPONENT                 0x00040000
#define ACPI_BUTTON_COMPONENT                  0x00080000
#define ACPI_SBS_COMPONENT                     0x00100000
#define ACPI_FAN_COMPONENT                     0x00200000
#define ACPI_FCI_COMPONENT                     0x00400000
#define ACPI_POWER_COMPONENT                   0x00800000
#define ACPI_CONTAINER_COMPONENT               0x01000000
#define ACPI_SYS_COMPONENT                     0x02000000
#define ACPI_THERMAL_COMPONENT                 0x04000000
#define ACPI_MEM_DEVICE_COMPONENT              0x08000000
#define ACPI_VID_COMPONENT                     0x10000000
#define ACPI_PROCESSOR_COMPONENT               0x20000000

#define ACPI_POWER_HID                         "litchyxPower"
#define ACPI_PROCESSOR_OBJECT_HID              "litchyxCPU"
#define ACPI_SYS_HID                           "litchyxSystem"
#define ACPI_BUTTON_POWER_OFF_HID              "litchyxPowerButton"
#define ACPI_BUTTON_SLEEP_HID                  "litchyxSleepButton"
#define ACPI_VID_HID                           "litchyxVideo"
#define ACPI_BAY_HID                           "litchyxIOBay"
#define ACPI_DOCK_HIB                          "litchyxDock"
#define ACPI_EC_HID                            "litchyxEC"
#define ACPI_SMBUS_IBM_HIB                     "smBusIBM"

// ACPI PCI interrupt link.

int acpiIrqPenaltyInit(void);
int acpiPciLinkAllocateIrq(acpiHandle handle, int index, int *triggering,
        int *polarity, chat **name);
int acpiPciLinkFreeIrq(acpiHandle handle);

struct pciBus;

#ifdef CONFIG_PCI
struct pciDev *acpiGetPciDev(acpiHandle);
#else
static inline struct pciDev *acpiGetPciDev(acpiHandle)
{
    return NULL;
}

#endif

struct pciBus *pciAcpiScanRoot(struct acpiPciRoot *root);

#ifdef CONFIG_X86
void pciAcpiCrsQuirks(void);
#else
static inline void pciAcpiCrsQuirks(void);

#endif

/* PROCESSOR */
#define ACPI_PROCESSOR_LIMIT_NONE              0x00
#define ACPI_PROCESSOR_LIMIT_INCREMENT         0x01
#define ACPI_PROCESSOR_LIMIT_DECREMENT         0x02

/* Dock Station*/
#ifdef CONFIG_ACPI_DOCK
extern int isDockDevice(struct acpiDevice *device);
#else
static inline int isDockDevice(struct acpiDevice *device)
{
    return 0;
}

#endif

#endif
