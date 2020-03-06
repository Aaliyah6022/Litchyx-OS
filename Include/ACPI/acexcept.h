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
#define _NOT_IMPLEMENTED                 EXCEPT_ENV(0x000E)
#define _SUPPORT                         EXCEPT_ENV(0x000F)
#define _LIMIT                           EXCEPT_ENV(0x0010)
#define _TIME                            EXCEPT_ENV(0x0011)
#define _ACQUIRE_DEADLOCK                EXCEPT_ENV(0x0012)
#define _RELEASE_DEADLOCK                EXCEPT_ENV(0x0013)
#define _NOT_ACQUIRED                    EXCEPT_ENV(0x0014)
#define _ALREADY_ACQUIRED                EXCEPT_ENV(0x0015)
#define _HARDWARE_NO_RESPONSE            EXCEPT_ENV(0x0016)
#define _NO_GLOBAL_LOCK                  EXCEPT_ENV(0x0017)
#define _ABORT_METHOD                    EXCEPT_ENV(0x0018)
#define _SAME_HANDLER                    EXCEPT_ENV(0x0019)
#define _NO_HANDLER                      EXCEPT_ENV(0x001A)
#define _OWNER_ID_LIMIT                  EXCEPT_ENV(0x001B)
#define _NOT_CONFIGURED                  EXCEPT_ENV(0x001C)
#define _ACCESS                          EXCEPT_ENV(0x001D)
#define _IO_ERROR                        EXCEPT_ENV(0x001E)
#define _NUMERIC_OVERFLOW                EXCEPT_ENV(0x001F)
#define _HEX_OVERFLOW                    EXCEPT_ENV(0x0020)
#define _DECIMAL_OVERFLOW                EXCEPT_ENV(0x0021)
#define _OCTAL_OVERFLOW                  EXCEPT_ENV(0x0022)
#define _END_OF_TBL                      EXCEPT_ENV(0x0023)

#define _MAX_ENV_CODE                    0x0023

/* Programmer Exceptions */
#define _BAD_PARAM                       EXCEPT_PGM(0x0001)
#define _BAD_CHAR                        EXCEPT_PGM(0x0002)
#define _BAD_PATH_NAME                   EXCEPT_PGM(0x0003)
#define _BAD_DATA                        EXCEPT_PGM(0x0004)
#define _BAD_HEX_CONST                   EXCEPT_PGM(0x0005)
#define _BAD_DECIMAL_CONST               EXCEPT_PGM(0x0006)
#define _BAD_OCTAL_CONST                 EXCEPT_PGM(0x0007)
#define _MISSING_ARGS                    EXCEPT_PGM(0x0008)
#define _BAD_ADDRESS                     EXCEPT_PGM(0x0009)

#define _MAX_PGM_CODE                    0x0009

/* ACPI Table Exceptions */
#define _BAD_SIGNATURE                   EXCEPT_TBL(0x0001)
#define _BAD_HEADER                      EXCEPT_TBL(0x0002)
#define _BAD_CHECKSUM                    EXCEPT_TBL(0x0003)
#define _BAD_VALUE                       EXCEPT_TBL(0x0004)
#define _INVALID_TBL_LENGTH              EXCEPT_TBL(0x0005)
 
#endif

