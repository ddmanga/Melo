/* ft_print_alphabet — écris ton code ici.
 * Sujet : exercises_exam/ft_print_alphabet
 */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	c;

	c = 'a';
	while (c <= 'z')
	{
		write(1, &c, 1);
		c++;
	}
}