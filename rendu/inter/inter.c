/* inter — écris ton code ici.
 * Sujet : exercises_exam/inter
 */

#include <unistd.h>

static int	is_in(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	printed[512];
	int		count;
	int		i;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	printed[0] = '\0';
	count = 0;
	i = 0;
	while (argv[1][i])
	{
		if (is_in(argv[2], argv[1][i]) && !is_in(printed, argv[1][i]))
		{
			printed[count] = argv[1][i];
			count++;
			printed[count] = '\0';
			write(1, &argv[1][i], 1);
			write(1, "\n", 1);
		}
		i++;
	}
	return (0);
}