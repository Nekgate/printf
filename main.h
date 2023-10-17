#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
* struct fmt - Struct op
* @fmt: The format.
* @fn: The function associated.
*/

struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
* typedef struct fmt fmt_t - Struct op
* @fmt: The format.
* @fm_t: The function associated.
*/

typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int nnhandle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
int nnprint_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int nnprint_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int nnprint_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int nnprint_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int nnprint_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int nnprint_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int nnprint_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int nnprint_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int nnprint_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int nnprint_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);
int nnprint_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int nnprint_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int nnget_flags(const char *format, int *i);
int nnget_width(const char *format, int *i, va_list list);
int nnget_precision(const char *format, int *i, va_list list);
int nnget_size(const char *format, int *i);
int nnprint_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int nnprint_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int nnhandle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int nnwrite_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int nnwrite_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int nnwrite_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int nnwrite_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);
int nnis_printable(char);
int nnappend_hexa_code(char, char[], int);
int nnis_digit(char);

long nnint convert_size_number(long int num, int size);
long nnint convert_size_unsgnd(unsigned long int num, int size);

#endif

