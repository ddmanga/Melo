/* rotone — écris ton code ici.
 * Sujet : exercises_exam/rotone
 */

#include <unistd.h>

static char	rot_char(char c)
{
	if (c >= 'a' && c <= 'z')
		return ('a' + (c - 'a' + 1) % 26);
	if (c >= 'A' && c <= 'Z')
		return ('A' + (c - 'A' + 1) % 26);
	return (c);
}

int	main(int argc, char **argv)
{
	int		i;
	char	c;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		c = rot_char(argv[1][i]);
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}