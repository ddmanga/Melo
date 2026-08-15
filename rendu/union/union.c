/* union — écris ton code ici.
 * Sujet : exercises_exam/union
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

static void	handle_char(char c, char *printed, int *count)
{
	if (!is_in(printed, c))
	{
		printed[*count] = c;
		(*count)++;
		printed[*count] = '\0';
		write(1, &c, 1);
		write(1, "\n", 1);
	}
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
		handle_char(argv[1][i], printed, &count);
		i++;
	}
	i = 0;
	while (argv[2][i])
	{
		handle_char(argv[2][i], printed, &count);
		i++;
	}
	return (0);
}