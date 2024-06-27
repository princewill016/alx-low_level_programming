#include "main.h"

/**
 * print_alphabet_x10 - prints the alphabet 10 times
 *
 * Return: Nothing (void)
 */
void	print_alphabet_x10(void)
{
	char	start_char = 'a';
	int	loop_count = 0;

	while (loop_count < 10)
	{
		for (start_char = 'a'; start_char <= 'z'; start_char++)
		{
			_putchar(start_char);
		}
		_putchar('\n');
		loop_count++;
	}
}
