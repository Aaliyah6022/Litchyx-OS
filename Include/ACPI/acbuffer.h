#ifndef __ACBUFFER_H__
#define __ACBUFFER_H__

/* _FDE return value */
struct acpi_fde_info
{
    u32 floppy0;
    u32 floppy1;
    u32 floppy2;
    u32 floppy3;
    u32 tape;
};

/*
 * __GRT return value
 * _SRT input value
 */
struct acpi_grt_info
{
    u16 year;
    u8 month;
    u8 day;
    u8 hour;
    u8 minute;
    u8 second;
    u8 valid;
    u16 milliseconds;
    u16 timezone;
    u8 daylight;
    u8 reserved[3];
};

/*
 * Formatted _PLD return value
 */
struct acpi_pld_info
{
    u8 revision;
    u8 ignoreColour;
    u8 red;
    u8 green;
    u8 blue;
    u16 width;
    u18 height;
    u8 userVisible;
    u8 dock;
    u8 lid;
    u8 panel;
    u8 verticalPosition;
    u8 horizontalPosition;
    u8 shape;
    u8 groupOrientation;
    u8 groupToken;
    u8 groupPosition;
    u8 bay;
    u8 eject_able;
    u8 ospmObjectRequired;
    u8 cabinetNumber;
    u8 cardCageNumber;
    u8 reference;
    u8 rotation;
    u8 order;
    u8 reserved;
    u8 verticalOffset;
    u8 horizontalOffset
};

/*
 * Macros to:
 *     1)  Conversion of a  _PLD buffer to an internal struct acpi_pld_info format -> ACPI_PLD_GET*
 *         (Used by acpi_decodePld_buffer)
 *     2)  Construction of a _PLD buffer -> ACPI_PLD_SET*
 *         (Intended for BIOS use only)
 */
#define ACPI_PLD_BUFFER_SIZE 20

/* First 32-bit dword, bits 0:32 */

#define ACPI_PLD_GET_REVISION(dword)                ACPI_GET_BITS (dword, 0, ACPI_7BIT_MASK)
#define ACPI_PLD_SET_REVISION(dword, value)         ACPI_SET_BITS (dword, 0, ACPI_7BIT_MASK, value)

#define ACPI_PLD_GET_IGNORE_COLOUR(dword)           ACPI_GET_BITS (dword, 7, ACPI_1BIT_MASK)
#define ACPI_PLD_SET_IGNORE_COLOUR(dword, value)    ACPI_SET_BITS (dword, 7, ACPI_1BIT_MASK, value)

#define ACPI_PLD_GET_RED(dword)                     ACPI_GET_BITS (dword, 8, ACPI_8BIT_MASK)
#define ACPI_PLD_SET_RED(dword, value)              ACPI_SET_BITS (dword, 8, ACPI_8BIT_MASK, value)

#define ACPI_PLD_GET_GREEN(dword)                   ACPI_GET_BITS (dword, 16, ACPI_8BIT_MASK)
#define ACPI_PLD_SET_GREEN(dword, value)            ACPI_SET_BITS (dword, 16, ACPI_8BIT_MASK, value)

#define ACPI_PLD_GET_BLUE(dword)                    ACPI_GET_BITS (dword, 24, ACPI_16BIT_MASK)
#define ACPI_PLD_SET_BLUE(dword, value)             ACPI_SET_BITS (dword, 24, ACPI_16BIT_MASK, value)

/* Second 32-bit, bits 33:63 */

#define ACPI_PLD_GET_WIDTH(dword)                   ACPI_GET_BITS (dword, 0, ACPI_16BIT_MASK)
#define ACPI_PLD_SET_WIDTH(dword, value)            ACPI_SET_BITS (dword, 0, ACPI_16BIT_MASK, value)

#define ACPI_PLD_GET_HEIGHT(dword)                  ACPI_GET_BITS (dword, 16, ACPI_16BIT_MASK)
#define ACPI_PLD_SET_HEIGHT(dword, value)           ACPI_SET_BITS (dword, 16, ACPI_16BIT_MASK, value)

/* Third 32-bit dword, bits 64:95 */

#define ACPI_PLD_GET_USER_VISIBLE(dword)            ACPI_GET_BITS(dword, 0, ACPI_1BIT_MASK)
#define ACPI_PLD_SET_USER_VISIBLE(dword, value)     ACPI_SET_BITS(dword, 0, ACPI_1BIT_MASK, value)

#define ACPI_PLD_GET_DOCK(dword)                    ACPI_GET_BITS(dword, 1, ACPI_1BIT_MASK)
#define ACPI_PLD_SET_DOCK(dword, value)             ACPI_SET_BITS(dword, 1, ACPI_1BIT_MASK, value)

#define ACPI_PLD_GET_LID(dword)                     ACPI_GET_BITS(dword, 2, ACPI_1BIT_MASK)
#define ACPI_PLD_SET_LID(dword, value)              ACPI_SET_BITS(dword, 2, ACPI_1BIT_MASK, value)

#define ACPI_PLD_GET_PANEL(dword)                   ACPI_GET_BITS(dword, 3, ACPI_3BIT_MASK)
#define ACPI_PLD_SET_PANEL(dword, value)            ACPI_SET_BITS(dword, 3, ACPI_3BIT_MASK, value)

#define ACPI_PLD_GET_VERTICAL(dword)                ACPI_GET_BITS(dword, 6, ACPI_2BIT_MASK)
#define ACPI_PLD_SET_VERTICAL(dword, value)         ACPI_SET_BITS(dword, 6, ACPI_2BIT_MASK, value)

#define ACPI_PLD_GET_HORIZONTAL(dword)              ACPI_GET_BITS(dword, 8, ACPI_2BIT_MASK)
#define ACPI_PLD_SET_HORIZONTAL(dword, value)       ACPI_SET_BITS(dword, 8, ACPI_2BIT_MASK, value)

#define ACPI_PLD_GET_SHAPE(dword)                    ACPI_GET_BITS(dword, 10, ACPI_4BIT_MASK)
#define ACPI_PLD_SET_SHAPE(dword, value)             ACPI_SET_BITS(dword, 10, ACPI_4BIT_MASK, value)

#define ACPI_PLD_GET_ORIENTATION(dword)              ACPI_GET_BITS(dword, 14, ACPI_1BIT_MASK)
#define ACPI_PLD_SET_ORIENTATION(dword, value)       ACPI_SET_BITS(dword, 14, ACPI_1BIT_MASK, value)

#define ACPI_PLD_GET_TOKEN(dword)                    ACPI_GET_BITS(dword, 15, ACPI_8BIT_MASK)
#define ACPI_PLD_SET_TOKEN(dword, value)             ACPI_SET_BITS(dword, 15, ACPI_8BIT_MASK, value)

#define ACPI_PLD_GET_POSITION(dword)                 ACPI_GET_BITS(dword, 23, ACPI_8BIT_MASK)
#define ACPI_PLD_SET_POSITION(dword, value)          ACPI_SET_BITS(dword, 23, ACPI_8BIT_MASK, value)

#define ACPI_PLD_GET_BAY(dword)                      ACPI_GET_BITS(dword, 31, ACPI_1BIT_MASK)
#define ACPI_PLD_SET_BAY(dword, value)               ACPI_SET_BITS(dword, 31, ACPI_1BIT_MASK, value)

#endif

