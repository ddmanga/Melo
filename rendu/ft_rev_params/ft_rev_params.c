/* ft_rev_params — écris ton code ici.
 * Sujet : exercises_exam/ft_rev_params
 */

#include <unistd.h>

static void	put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = argc - 1;
	while (i >= 1)
	{
		put_str(argv[i]);
		write(1, "\n", 1);
		i--;
	}
	return (0);
}