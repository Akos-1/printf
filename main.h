#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

/* FLAGS */
#define F_MINUS (1 << 0)
#define F_PLUS (1 << 1)
#define F_ZERO (1 << 2)
#define F_HASH (1 << 3)
#define F_SPACE (1 << 4)

/* SIZES */
#define S_LONG (1 << 0)
#define S_SHORT (1 << 1)

/**
 * struct frt - Struct op
 * @frt: The format.
 * @fun: The function associated with the format.
 */
struct frt
{
	char frt;
	int (*fun)(va_list, char[], int, int, int, int);
}

/**
 * typedef struct frt frt_t - Struct op
 * @frt: The format.
 * @fr_t: The function associated.
 */
typedef (struct frt frt_t);

int _printf(const char *format, ...);
int handle_print(const char *frt, int *i,
		va_list argu, char buffer[], int flg, int wid, int pr, int size);}
/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int print_char(va_list typ, char buffer[],
		int flg, int wid, int pr, int size);
int print_str(va_list typ, char buffer[],
		int flg, int wid, int pr, int size);

int print_per(va_list typ, char buffer[],
		int flg, int wid, int pr, int size);


/* Functions to print numbers */
int print_int(va_list typ, char buffer[],
		int flg, int wid, int pr, int size);

int print_binary(va_list typ, char buffer[],
		int flg, int wid, int pr, int size);

int print_unsigned(va_list typ, char buffer[],
		int flg, int wid, int pr, int size);

int print_oct(va_list typ, char buffer[],
		int flg, int wid, int pr, int size);

int print_hexadec(va_list typ, char buffer[],
		int flg, int wid, int pr, int size);

int print_hexa_upp(va_list typ, char buffer[],
		int flg, int wid, int pr, int size);


int print_hexa(va_list typ, char map_to[],
		char buffer[], int flg, char flg_ch, int wid, int pr, int size);

/* Function to print non printable characters */
int print_non_printable(va_list typ, char buffer[],
		int flg, int wid, int pr, int size);

/* Function to print memory address */
int print_point(va_list typ, char buffer[],
		int flg, int wid, int pr, int size);

/* Functions to handle other specifiers */
int get_flg(const char *format, int *a);
int get_wid(const char *format, int *a, va_list argu);
int get_pr(const char *format, int *a, va_list argu);
int get_size(const char *format, int *a);

/*Function to print string in reverse*/
int print_rev(va_list typ, char buffer[],
		int flg, int wid, int pr, int size);

/*Function to print a string in rot 13*/
int print_rot13str(va_list typ, char buffer[],
		int flg, int wid, int pr, int size);

/* width handler */
int write_char(char c, char buffer[],
		int flg, int wid, int pr, int size);

int write_num(int is_neg, int ind, char buffer[],
		int flg, int wid, int pr, int size);

int write_numb(int ind, char bff[], int flg, int wid, int pre,
		int len, char padd, char extra_char);
int write_point(char buffer[], int ind, int len,
		int wid, int flg, char padd, char extra_char, int padd_start);

int write_unsgnd(int is_neg, int ind,
		char buffer[],
		int flg, int wid, int pr, int size);


/****************** UTILS ******************/
int is_print(char);
int append_hexa_code(char, char[], int);
int is_dig(char);

long int conv_size_num(long int num, int size);
long int conv_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
