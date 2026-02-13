#ifndef S21_GREP_H
#define S21_GREP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <getopt.h>
#include <regex.h>

// Структура для хранения флагов
typedef struct {
    bool n;          // Печать номера строки
    bool v;          // Инвертировать совпадения
    bool c;          // Подсчет совпадений
    bool l;          // Печать только имен файлов
    bool o;          // Печать только совпадений
    bool h;          // Печать имени файла
    bool s;          // Игнорировать ошибки
    bool f;          // Чтение паттернов из файла
    int regeg_flag;  // Флаги для регулярных выражений
} Flags;

// Функции
void GrepFile(FILE *f, Flags flags, regex_t *preg, char *filename, int count);
void GrepCount(FILE *f, regex_t *preg, int cou, char *filename, Flags flags);
void GrepPrintFile(FILE *f, regex_t *preg, char *filename);
void GrepNumper(FILE *f, regex_t *preg, int cou, char *filename, Flags flags, char **pattern);
Flags read_flags(int argc, char **argv);
char *read_patterns_from_file(const char *filename);
void Grep(int argc, char **argv, Flags flags);

#endif // S21_GREP_H
