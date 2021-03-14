/*
 *   Вариант #44
 *   Составить структуру для хранения информации о международных нормативных
 * документах: организации-эмитенте (ISO, IEEE, W3C и т.д.), виде документа
 * (стандарт, отчет и т.д.), названии на английском языке, дате принятия и дате
 * вступления в силу, наличии перевода на русский язык. Составить с ее
 * использованием программу вывода информации обо всех документах, наиболее
 * соответствующих запросу пользователя.
 */

/*
 *   Краткое описание решения:
 *   ./headers содержит заголовочные файлы, .c-файлы расположены в ./src .
 *      : custom_errors.h содержит в себе коды ошибок. В custom_errors.c
 *находится функция вывода на экран информации об ошибке по ее коду. : data.h
 *содержит в себе объявления структур, предназначенных для хранения информации,
 *а также заголовки функций, используемых ее при обработке. : io.h содержит в
 *себе заголовки функций, используемых для организации вводе-вывода. : list.h
 *содержит в себе объясление node_t, а также заголовки функций, используемых для
 *организации односвязного списка. Документы хранятся в односвязном списке из
 *node_t. Каждая новая запись добавляется в начало списка. За циклическое
 *взаимодействие с пользователем отвечает функция loop, представленная в этом
 *файле.
 */

#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "../headers/custom_errors.h"
#include "../headers/data.h"
#include "../headers/io.h"
#include "../headers/list.h"

enum states { leave = 0, add_entry = 1, find_entry = 2, print_list = 3 };

errco_t loop() {
  node_t* head = NULL;

  char cmdbuf[MAXLENGTH];
  int cmd;

  errco_t err = 0;

  do {
    entry_t new_entry;
    printf("%s\n", "Enter command:\n");
    if (fgets(cmdbuf, MAXLENGTH, stdin) != NULL) {
      cmd = strtol(cmdbuf, NULL, 10);
      switch (cmd) {
        case add_entry:
          err = entry_input(&new_entry, stdin, stdin, stdin, stdin, stdin, stdin);
          if (err != EXIT_SUCCESS) {
            errputs(err);
            return err;
          }
          err = list_add(&head, new_entry);
          break;

        case find_entry:
          err = entry_input(&new_entry, stdin, stdin, stdin, stdin, stdin, stdin);
          if (err != EXIT_SUCCESS) {
            errputs(err);
            return err;
          }

          err = list_find(&head, new_entry);
          if (err != EXIT_SUCCESS) {
            errputs(err);
            return err;
          }

          break;

        case print_list:

          err = list_printf(&head);
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

  err = list_delete(&head);
  if (err != EXIT_SUCCESS) {
    errputs(err);
    return err;
  }

  return EXIT_SUCCESS;
}

int main(int argc, char* argv[]) {
  errco_t err;
  err = loop();
  if (err != EXIT_SUCCESS) {
    errputs(err);
    return err;
  }

  return EXIT_SUCCESS;
}