/*
 * Вариант #44
 * 
 * Вы разрабатываете специализированную БД сотрудников для корпорации, в которой работает порядка 10к человек. По ряду причин все данные необходимо хранить в оперативной памяти. 
 * Предложите такую эффективную упаковку данных о сотруднике (его имени, фамилии, поле, возрасте, заработной плате, должности и стаже работы). 
 * С её помощью реализуйте наивный последовательный алгоритм, который позволит быстро осуществлять поиск по запросу: самые возрастные и молодые 
 * сотрудники в каждой должности с сортировкой по фамилии, а затем – распараллельте его на несколько потоков.
 */

/* 
 * Краткое описание реализации: создается хэш-таблица (по должностям). Найденные элементы записываются в список и выводятся списком.
 * 
 * Примерная сложность хэш-таблицы: в среднем о(1), о(1), о(1), в худшем о(n), о(n), о(n), по памяти - о(n) 
 * 
 */

#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "custom_errors.h"
#include "data.h"
#include "hash.h"
#include "io.h"

enum states { leave = 0, add_entry = 1, find_max_min = 2 };

#define MAX_HASHTABLE_SIZE 100000

errco_t main_io_loop() {
  hashtable_t table;
  list_node_t* list = NULL;

  char cmdbuf[MAXLENGTH];
  int cmd;

  errco_t err = 0;
  printf("Available commands:\n 0 - exit\n 1 - add entry\n 2 - find max/min\n");
  err = hashtable_create(&table, MAX_HASHTABLE_SIZE);
  if (err != EXIT_SUCCESS) {
    errputs(err);
    return err;
  }
  do {
    entry_value_t new_entry;
    printf("Enter command:\n");
    if (fgets(cmdbuf, MAXLENGTH, stdin) != NULL) {
      cmd = strtol(cmdbuf, NULL, 10);
      switch (cmd) {
        case add_entry:
          err = entry_value_input(&new_entry, stdin, true);
          if (err != EXIT_SUCCESS) {
            errputs(err);
            return err;
          }
          err = hashtable_insert(&table, &new_entry);
          break;

        case find_max_min:

          err = hashtable_find(&table, &list);
          if (err != EXIT_SUCCESS) {
            errputs(err);
            return err;
          }

          break;

        default:
          cmd = 0;
          break;
      }
    }
  } while (cmd != 0);

  err = hashtable_delete(&table);
  if (err != EXIT_SUCCESS) {
    errputs(err);
    return err;
  }
  err = list_delete(&list);
  if (err != EXIT_SUCCESS) {
    errputs(err);
    return err;
  }

  return EXIT_SUCCESS;
}

int main(int argc, char* argv[]) {
  errco_t err;

  err = main_io_loop();
  if (err != EXIT_SUCCESS) {
    errputs(err);
    return err;
  }

  return EXIT_SUCCESS;
}