/* first_word — écris ton code ici.
 * Sujet : exercises_exam/first_word
 */

#include <unistd.h>

static int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (is_space(argv[1][i]))
		i++;
	while (argv[1][i] && !is_space(argv[1][i]))
	{
		write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}