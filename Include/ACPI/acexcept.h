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
#define _CODE_ENVIRONMENTAL               0x0000 // General ACPICA environment
#define _CODE_PROGRAMMER                  0x1000 // External ACPICA interface caller
#define _CODE_ACPI_TABLES                 0x2000 // ACPI tables
#define _CODE_AML                         0x3000 // From execution of AML code
#define _CODE_CONTROL                     0x4000 // Internal control codes

#define _CODE_MAX                         0x4000
#define _CODE_MASK                        0xF000

/* Marcos to insert the exception code classes */
#define EXCEPT_ENV(code)                  ((acpi_status) (code | _CODE_ENVIRONMENTAL))
#define EXCEPT_PGM(code)                  ((acpi_status) (code | _CODE_PROGRAMMER))
#define EXCEPT_TBL(code)                  ((acpi_status) (code | _CODE_ACPI_TABLES))
#define EXCEPT_AML(code)                  ((acpi_status) (code | _CODE_AML))
#define EXCEPT_CTL(code)                  ((acpi_status) (code | _CODE_CONTROL))

/* Exception info table. The description field is used only by the
 * ACPICA application (acpihelp)*/
struct acpi_exception_info
{
    char *name;

#ifdef ACDI_HELP_APP
    char *description
#endif
};

#ifdef ACPI_HELP_APP
#define EXCEPT_TXT(name, description)    {name, description}
#else
#define EXCEPT_TXT(name, description)    {name}
#endif

/* Success is ALWAYS 0, failure is non-zero. */
#define ACPI_SUCCESS(a)                  (!(a))
#define ACPI_FAILURE(a)                  (a)

#define _OK                              (acpi_status) 0x0000

#define ACPI_ENV_EXCEPT(status)          (status & _CODE_ENVIRONMENTAL)
#define ACPI_PROG_EXCEPT(status)         (status & _CODE_PROGRAMMER)
#define ACPI_TBL_EXCEPT(status)          (status & _CODE_ACPI_TABLES)
#define ACPI_AML_EXCEPT(status)          (sattus & _CODE_AML)
#define ACPI_CTRL_EXCEPT(status)         (status & _CODE_CONTROL)

#endif

