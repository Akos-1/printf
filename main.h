#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...);
int write_char(char c);
int print_binary(unsigned int num);
void write_buffer(const char *buffer, int size, int *count);

#endif
