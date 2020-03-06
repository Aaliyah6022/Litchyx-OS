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

#define _MAX_TBL_CODE                    0x0005

/* AML Exceptions */
#define _AML_BAD_OPCODE                  EXCEPT_AML(0x0001)
#define _AML_NO_OPERAND                  EXCEPT_AML(0x0002)
#define _AML_OPERAND_TYPE                EXCEPT_AML(0x0003)
#define _AML_OPERAND_VALUE               EXCEPT_AML(0x0004)
#define _AML_UNINIT_LOCAL                EXCEPT_AML(0x0005)
#define _AML_UNINIT_ARG                  EXCEPT_AML(0x0006)
#define _AML_UNINIT_ELEMENT              EXCEPT_AML(0x0007)
#define _AML_NUMERIC_OVERFLOW            EXCEPT_AML(0x0008)
#define _AML_REGION_LIMIT                EXCEPT_AML(0x0009)
#define _AML_BUFFER_LIMIT                EXCEPT_AML(0x000A)
#define _AML_PACKAGE_LIMIT               EXCEPT_AML(0x000B)
#define _AML_ZERO_DIVISION               EXCEPT_AML(0x000C)
#define _AML_BAD_NAME                    EXCEPT_AML(0x000D)
#define _AML_NAME_NOT_FOUND              EXCEPT_AML(0x000E)
#define _AML_INTERNAL                    EXCEPT_AML(0x000F)
#define _AML_INVALID_SPACE_ID            EXCEPT_AML(0x0010)
#define _AML_STRING_LIMIT                EXCEPT_AML(0x0011)
#define _AML_NO_RETURN_VALUE             EXCEPT_AML(0x0012)
#define _AML_METHOD_LIMIT                EXCEPT_AML(0x0013)
#define _AML_NOT_OWNER                   EXCEPT_AML(0x0014)
#define _AML_MUTEX_ORDER                 EXCEPT_AML(0x0015)
#define _AML_MUTEX_NOT_ACQUIRED          EXCEPT_AML(0X0016)
#define _AML_INVALID_RESOURCE_TYPE       EXCEPT_AML(0x0017)
#define _AML_INVALID_INDEX               EXCEPT_AML(0x0018)
#define _AML_REGISTER_LIMIT              EXCEPT_AML(0x0019)
#define _AML_NO_WHILE                    EXCEPT_AML(0x001A)
#define _AML_ALIGNMENT                   EXCEPT_AML(0x001B)
#define _AML_NO_RESOURCE_END_TAG         EXCEPT_AML(0x001C)
#define _AML_BAD_RESOURCE_VALUE          EXCEPT_AML(0x001D)
#define _AML_CIRCULAR_REFERENCE          EXCEPT_AML(0x001E)
#define _AML_BAD_RESOURCE_LENGTH         EXCEPT_AML(0x001F)
#define _AML_ILLEGAL_ADDRESS             EXCEPT_AML(0x0020)
#define _AML_LOOP_TIMEOUT                EXCEPT_AML(0x0021)
#define _AML_UNINIT_NODE                 EXCEPT_AML(0x0022)
#define _AML_TARGET_TYPE                 EXCEPT_AML(0x0023)
#define _AML_PROTOCOL                    EXCEPT_AML(0x0024)
#define _AML_BUFFER_LENGTH               EXCEPT_AML(0x0025)

#define _MAX_AML_CODE                    0x0025

/* Internal Exceptions */
#define _CTRL_RETURN_VALUE               EXCEPT_CTL(0x0001)
#define _CTRL_PENDING                    EXCEPT_CTL(0x0002)
#define _CTRL_TERMINATE                  EXCEPT_CTL(0x0003)
#define _CTRL_TRUE                       EXCEPT_CTL(0x0004)
#define _CTRL_FALSE                      EXCEPT_CTL(0x0005)
#define _CTRL_DEPTH                      EXCEPT_CTL(0x0006)
#define _CTRL_END                        EXCEPT_CTL(0x0007)
#define _CTRL_TRANSFER                   EXCEPT_CTL(0x0008)
#define _CTRL_BREAK                      EXCEPT_CTL(0x0009)
#define _CTRL_CONTINUE                   EXCEPT_CTL(0x000A)
#define _CTRL_PARSE_CONTINUE             EXCEPT_CTL(0x000B)
#define _CTRL_PARSE_PENDING              EXCEPT_CTL(0x000C)

#define _MAX_CTRL_CODE                   0x000C

#ifdef ACPI_DEFINE_EXCEPT_TABLE

static const struct acpi_exception_info ACPI_GBL_EXCEPTION_NAMES_ENV[] = {
        EXCEPT_TXT("_OK", "No errors."),
        EXCEPT_TXT("_ERROR", "Unspecified error."),
        EXCEPT_TXT("_NO_ACPI_TABLES", "ACPI tables could not be found."),
        EXCEPT_TXT("_NO_NAMESPACE", "A namespace has not been loaded."),
        EXCEPT_TXT("_NO_MEMORY", "Insufficient dynamuc memory."),
        EXCEPT_TXT("_NOT_FOUND", "A requested entity is not found."),
        EXCEPT_TXT("_NOT_EXIST", "A required entity does not exist."),
        EXCEPT_TXT("_ALREADY_EXIST", "An entity already exists."),
        EXCEPT_TXT("_TYPE", "The object type is incorrect."),
        EXCEPT_TXT("_NULL_OBJ", "A required object is missing."),
        EXCEPT_TXT("_NULL_ENTRY", "The requested object does not exist."),
        EXCEPT_TXT("_BUFFER_OVERFLOW", "The buffer provided is too small."),
        EXCEPT_TXT("_STACK_OVERFLOW", "An internal stack overflowed."),
        EXCEPT_TXT("_STACK_UNDERFLOW", "An internal stack underflowed."),
        EXCEPT_TXT("_NOT_IMPLEMENTED", "The feature is not implemented."),
        EXCEPT_TXT("_SUPPORT", "The feature is unsupported."),
        EXCEPT_TXT("_LIMIT", "A predefined limit was exceeded."),
        EXCEPT_TXT("_TIME", " A time limit or timeout expired."),
        EXCEPT_TXT("_ACQUIRE_DEADLOCK", "Internal error: an attempt was made to acquire a mutex in the improper order."),
        EXCEPT_TXT("_RELEASE_DEADLOCK", "Internal error: an attempt was made to release a mutex in the improper order."),
        EXCEPT_TXT("_NOT_ACQUIRED", "An attempt to release a mutex or Global Lock without a previos acquire."),
        EXCEPT_TXT("_ALREADY_ACQUIRED", "Internal error: an attempt was made to acquire a mutex twice."),
        EXCEPT_TXT("_HARDWARE_NO_RESPONSE", "The hardware did not response after an I/O operation."),
        EXCEPT_TXT("_NO_GLOBAL_LOCK", "There is no FACS Global Lock."),
        EXCEPT_TXT("_ABORT_METHOD", "A control method was aborted."),
        EXCEPT_TXT("_SAME_HANDLER", "Attempt made to install a handler that is already installed."),
        EEXCEPT_TXT("_NO_HANDLER", "A handler for the operation is not installed/missing."),
        EXCEPT_TXT("_OWNER_ID_LIMIT", "There are no more Owner IDs available for ACPI tables or control methods."),
        EXCEPT_TXT("_NOT_CONFIGURED", "The interface is not part of the current subsystem configuration."),
        EXCEPT_TXT("_ACCESS", "Permission is denied for the requested operation."),
        EXCEPT_TXT("_IO_ERROR", "An I/O error occured."),
        EXCEPT_TXT("_NUMERIC_OVERFLOW", "An overflow occured during string-to-integer conversion."),
        EXCEPT_TXT("_HEX_OVERFLOW", "An ovrrflow occured during an ASCII hex-to-binary converstion."),
        EXCEPT_TXT("_DECIMAL_OVERFLOW", "An overflow occured during an ASCII decimal-to-binary coversion."),
        EXCEPT_TXT("_OCTAL_OVERFLOW", "An overflow occured during ASCII octal-to-binary conversion."),
        EXCEPT_TXT("_END_OF_TBL", "The end of the table has been reached.")
};

static const struct acpi_exception_info ACPI_GBL_EXCEPTION_NAMES_PGM[] = {
        EXCEPT_TXT(NULL, NULL),
        EXCEPT_TXT("_BAD_PARAM", "The parameter given is out of range or invalid."),
        EXCEPT_TXT("_BAD_CHAR", "An invalid character is found in a name."),
        EXCEPT_TXT("_BAD_PATH_NAME", "An invalid character is found in a path name."),
        EXCEPT_TXT("_BAD_DATA", "A package or buffer contains incorrect data."),
        EXCEPT_TXT("_BAD_HEX_CONST", "An invalid character is found in a hexadecimal constant."),
        EXCEPT_TXT("_BAD_DECIMAL_CONST", "An invalid character is found in a decimal constant."),
        EXCEPT_TXT("_BAD_OCTAL_CONST", "An invalid character is found in a octal constant."),
        EXCEPT_TXT("_MISSING_ARGS", "Too few arguments are passed to a control method."),
        EXCEPT_TXT("_BAD_ADDRESS", "An illegal null I/O address is found."),
};

static const struct acpi_exception_info ACPI_GBL_EXCEPTION_NAMES_TBL[] = {
        EXCEPT_TXT("_BAD_SIGNATURE", "An ACPI table has an invalid signature."),
        EXCEPT_TXT("_BAD_HEADER", "Invalid field in an ACPI table header."),
        EXCEPT_TXT("_BAD_CHECKSUM", "The checksum of an ACPI table is incorrect."),
        EXCEPT_TXT("_BAD_VALUE", "An invalid value is found in an ACPI table."),
        EXCEPT_TXT("_INVALID_TBL_LENGTH", "The FADT or FACS table has an improper length.")
};

static const struct acpi_exception_info ACPI_GBL_EXCEPTION_NAMES_AML[] = {
        EXCEPT_TXT(NULL, NULL),
        EXCEPT_TXT("_AML_BAD_OPCODE", "An invalid AML operation code is enconutered."),
        EXCEPT_TXT("_AML_NO_OPERAND", "A required operand is missing."),
        EXCEPT_TXT("_AML_OPERAND_TYPE", "An operand of the incorrect type is encountered."),
        EXCEPT_TXT("_AML_OPERAND_VALUE", "An operand has an inappropriate or invalid value."),
        EXCEPT_TXT("_AML_UNINIT_LOCAL", "A method tried to use an uninitialized local value."),
        EXCEPT_TXT("_AML_UNINIT_ARG", "A method tried to use an uninitialized local variable or argument."),
        EXCEPT_TXT("_AML_UNINIT_ELEMENT", "A method tried to use an empty package element."),
        EXCEPT_TXT("_AML_NUMERIC_OVERFLOW", "An overflow occured during a BCD conversion or other."),
        EXCEPT_TXT("_AML_REGION_LIMIT", "A trial to access beyond the end of an operation region."),
        EXCEPT_TXT("_AML_BUFFER_LIMIT", "A trial to access beyond the end of a buffer."),
        EXCEPT_TXT("_AML_PACKAGE_LIMIT", "A trial to access beyond the end of a package."),
        EXCEPT_TXT("_AML_ZERO_DIVISION", "During execution of AML division operator."),
        EXCEPT_TXT("_AML_BAD_NAME", "An ACPI name contains invalid character(s)."),
        EXCEPT_TXT("_AML_NAME_NOT_FOUND", "Could not resolve a named reference."),
        EXCEPT_TXT("_AML_INTERNAL", "An internal error occured in the interpreter."),
        EXCEPT_TXT("_AML_INVALID_SPACE_ID", "The operation Space ID is invalid."),
        EXCEPT_TXT("_AML_STRING_LIMIT", "A given string is longer than 200 characters."),
        EXCEPT_TXT("_AML_NO_RETURN_VALUE", "A method did not return a required value."),
        EXCEPT_TXT("_AML_METHOD_LIMIT", "A control method reached the maximum reentrancy of 255."),
        EXCEPT_TXT("_AML_NOT_OWNER", "A thread tried to release a mutex that it does not own."),
        EXCEPT_TXT("_AML_MUTEX_ORDER", "The Mutex Sync Order release is mismatched."),
        EXCEPT_TXT("_AML_MUTEX_NOT_ACQUIRED", "An attemp to release a mutex that was not previously acquired."),
        EXCEPT_TXT("_AML_INVALID_RESOURCE_TYPE", "An invalid resource type os found in the resource list."),
        EXCEPT_TXT("_AML_INVALID_INDEX", "An invalid arg(x) or local (x) is found, which x is too large."),
        EXCEPT_TXT("_AML_NO_WHILE", "Break or Continue without a while is encountered."),
        EXCEPT_TXT("_AML_ALIGNMENT", "A non-aligned memory transfer on platform that doesn't support this is encountered."),
        EXCEPT_TXT("_AML_NO_RESOURCE_END_TAG", "The end tag is not found in a resource list."),
        EXCEPT_TXT("_AML_BAD_RESOURCE_VALUE", "A invalid value of a resource element is found."),
        EXCEPT_TXT("_AML_CIRCULAR_REFERENCE", "Two references refer to each other."),
        EXCEPT_TXT("_AML_BAD_RESOURCE_LENGTH", "The length of a Resource Description in the AML is incorrect."),
        EXCEPT_TXT("_AML_ILLEGAL_ADDRESS", "A memory, I/O or PCI configuration address is invalid."),
        EXCEPT_TXT("_AML_LOOP_TIMEOUT", "An AML while loop exceeded the maximum execution time."),
        EXCEPT_TXT("_AML_UNINIT_NODE", "A namespace mpde os uninitialized or unresolved."),
        EXCEPT_TXT("_AML_TARGET_TYPE", "The target operand of an incorrect type is encountered."),
        EXCEPT_TXT("_AML_PROTOCOL", "Violation of a fixed ACPI protocol is detected."),
        EXCEPT_TXT("_AML_BUFFER_LENGTH", "The length of the buffer is invalid or incorrect.")
};

#endif

