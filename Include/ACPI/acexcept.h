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

/* Environmental Exceptions */
#define _ERROR                           EXCEPT_ENV(0x0001)
#define _NO_ACPI_TABLES                  EXCEPT_ENV(0x0002)
#define _NO_NAMESPACE                    EXCEPT_ENV(0x0003)
#define _NO_MEMORY                       EXCEPT_ENV(0x0004)
#define _NOT_FOUND                       EXCEPT_ENV(0x0005)
#define _NOT_EXIST                       EXCEPT_ENV(0x0006)
#define _ALREADY_EXIST                   EXCEPT_ENV(0x0007)
#define _TYPE                            EXCEPT_ENV(0x0008)
#define _NULL_OBJ                        EXCEPT_ENV(0x0009)
#define _NULL_ENTRY                      EXCEPT_ENV(0x000A)
#define _BUFFER_OVERFLOW                 EXCEPT_ENV(0x000B)
#define _STACK_OVERFLOW                  EXCEPT_ENV(0x000C)
#define _STACK_UNDERFLOW                 EXCEPT_ENV(0x000D)
#define _NOT_IMPLEMENTED                 EXCEPT_ENV(0x000D)
#define _SUPPORT                         EXCEPT_ENV(0x000E)
#define _LIMIT                           EXCEPT_ENV(0x000F)
#define _TIME                            EXCEPT_ENV(0x0010)

#endif

