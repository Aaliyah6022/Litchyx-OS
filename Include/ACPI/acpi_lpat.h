/* LitchyxOS/Include/ACPI/acpi.h */
/**************************************************************************
 *
 * Name: acpi_lpat.h - LPAT table process functions
 *
 *************************************************************************/

#ifndef __ACPI_LPAT_H__
#define __ACPI_LPAT_H__

struct acpiLpat {
    int temp;
    int raw;
};

struct acpiLpatConversionTable {
    struct acpiLpat *lpat;
    int lpatCount;
};

#ifdef CONFIG_ACPI

int acpiLpatRawToTemp(struct acpiLpatConversionTable *lpatTable, int raw);

int acpiLpatTempToRaw(struct acpiLpatConversionTable *lpatTable, int temp);

void acpiLpatConversionTable *acpiLpatGetConversionTable(acpiHandle handle);

#else
static int acpiLpatRawToTemp(struct acpiLpatConversionTable *lpatTable, int raw)
{
    return 0;
}

static int acpiLpatTempToRaw(struct acpiLpatConversionTable *lpatTable, int temp)
{
    return 0;
}

static struct acpiLpatConversionTable(struct acpiLpatConversionTable, *lpatTable)
{
    return NULL;
}

static void acpiLpatFreeConversionTable(struct acpiLpatConversionTable *lpatTable)
{
    
}

#endif

#endif

