/* LitchyxOS/Include/ACPI/acexcept.h */
/**************************************************************************************
 *
 * Name: acexcept.h - Exception codes that can bhe returned by the ACPI sub-system.
 *
 **************************************************************************************/

#ifndef __ACEXCEPT_H__
#define __ACEXCEPT_H__

// This header file contains every single possible exception codes for ACPI_STATUS.

/* Exception code classes */
#define _CODE_ENVIRONMENTAL           0x0000 // General ACPICA environment
#define _CODE_PROGRAMMER              0x1000 // External ACPICA interface caller
#define _CODE_ACPI_TABLES             0x2000 // ACPI tables
#define _CODE_AML                     0x3000 // From execution of AML code
#define _CODE_CONTROL                 0x4000 // Internal control codes

#define _CODE_MAX                     0x4000
#define _CODE_MASK                    0xF000

/* Marcos to insert the exception code classes */
#define EXCEPT_ENV(code)              ((acpi_status) (code | _CODE_ENVIRONMENTAL))
#define EXCEPT_PGM(code)              ((acpi_status) (code | _CODE_PROGRAMMER))
#define EXCEPT_TBL(code)              ((acpi_status) (code | _CODE_ACPI_TABLES))
#define EXCEPT_AML(code)              ((acpi_status) (code | _CODE_AML))
#define EXCEPT_CTL(code)              ((acpi_status) (code | _CODE_CONTROL))

#endif

