#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf -  function that produces output according to a format
 * @*format: forst parameter thatrecords the number of argument
 * Return: the number of characters printed
*/

int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
		/* Handle the "%" conversion specifier */
			if (*format == '%')
			{
				putchar('%');
				printed_chars++;
			}
		/* Handle the "c" conversion specifier */
			else if (*format == 'c')
			{
				char c = va_arg(args, int);

				putchar(c);
				printed_chars++;
			}
			/* Handle the "s" conversion specifier */
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);

				fputs(s, stdout);

				printed_chars += strlen(s);
			}
		}
		else
		{
			putchar(*format);
			printed_chars++;
		}
		format++;
	}
	va_end(args);
	return (printed_chars);
}
