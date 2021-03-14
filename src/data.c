#include "../headers/data.h"

entry_t to_entry_t(char * const organization, char * const type_of_document, char * const document_name, date_t const accepted, date_t const active_since, const tbool_t is_translated)
{
    entry_t new_entry;

    new_entry.organization = organization;
    new_entry.type_of_document = type_of_document;
    new_entry.document_name = document_name;
    new_entry.accepted = accepted;
    new_entry.active_since = active_since;
    new_entry.is_translated = is_translated;

    return new_entry;
}

date_t to_date_t(const int dd, const int mm, const int yy)
{
    date_t new_date;

    new_date.dd = dd;
    new_date.mm = mm;
    new_date.yy = yy;

    return new_date;
}

bool date_t_cmp (const date_t date1, const date_t date2)
{
    if( (date1.dd == 0 || date1.dd == date2.dd || date2.dd == 0) && 
        (date1.mm == 0 || date1.mm == date2.mm || date2.mm == 0) &&
        (date1.yy == 0 || date1.yy == date2.yy || date2.yy == 0))
        {
            return 1;
        }
    return 0;
}