#include "data.h"

date_t to_date_t(const int dd, const int mm, const int yy) {
  date_t new_date = {dd, mm, yy};

  return new_date;
}

bool date_t_cmp(const date_t date1, const date_t date2) {
  if ((date1.dd == 0 || date1.dd == date2.dd || date2.dd == 0) &&
      (date1.mm == 0 || date1.mm == date2.mm || date2.mm == 0) &&
      (date1.yy == 0 || date1.yy == date2.yy || date2.yy == 0)) {
    return 1;
  }
  return 0;
}

