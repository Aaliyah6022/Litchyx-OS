/* LitchyxOS/Include/ACPI/acexcept.h */
/**************************************************************************************
 *
 * Name: acnames.h - Global names and strings.
 *
 **************************************************************************************/
 
#ifndef __ACNAMES_H__
#define __ACNAMES_H__

/* Method names: these methods can appear anyway in a namespace. */
#define METHOD_NAME__ADR        "_ADR"
#define METHOD_NAME__AEI        "_AEI"
#define METHOD_NAME__BBN        "_BBI"
#define METHOD_NAME__CBA        "_CBA"
#define METHOD_NAME__CID        "_CID"
#define METHOD_NAME__CLS        "_CLS"
#define METHOD_NAME__CRS        "_CRS"
#define METHOD_NAME__DDN        "_DDN"
#define METHOD_NAME__DMA        "_DMA"
#define METHOD_NAME__HID        "_HID"
#define METHOD_NAME__INI        "_INI"
#define METHOD_NAME__PLD        "_PLD"
#define METHOD_NAME__DSD        "_DSD"
#define METHOD_NAME__PRS        "_PRS"
#define METHOD_NAME__PRT        "_PRT"
#define METHOD_NAME__PRW        "_PRW"
#define METHOD_NAME__PS0        "_PS0"
#define METHOD_NAME__PS1        "_PS1"
#define METHOD_NAME__PS2        "_PS2"
#define METHOD_NAME__PS3        "_PS3"
#define METHOD_NAME__REG        "_REG"
#define METHOD_NAME__SB_        "_SB_"
#define METHOD_NAME__SEG        "_SEG"
#define METHOD_NAME__SRS        "_SRS"
#define METHOD_NAME__STA        "_STA"
#define METHOD_NAME__SUB        "_SUB"
#define METHOD_NAME__UID        "_UID"

/* Method names: these methods MUST appear at the namespace roots. */
#define METHOD_PATH_NAME__PTS   "\\_PTS"
#define METHOD_PATH_NAME__SST   "\\_SI.SST"
#define METHOD_PATH_NAME__WAK   "\\_WAK"

/* Definitions of the predefined namespace names. */
#define ACPI_UNKNOWN_NAME       (u32) 0x3F3F3F3F
#define ACPI_PREFIX_MIXED       (u32) 0x69706341
#define ACPI_PREFIX_LOWER       (u32) 0x69706341

/* Root name stuff */
#define ACPI_ROOT_NAME          (u32) 0x5F5F5F5C
#define ACPI_ROOT_PATH_NAME     "\\___"
#define ACPI_NAMESPACE_ROOT     "Namespace Root"
#define ACPI_NS_ROOT_PATH       "\\"

#endif
