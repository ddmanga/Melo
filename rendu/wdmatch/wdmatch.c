/* wdmatch — écris ton code ici.
 * Sujet : exercises_exam/wdmatch
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

static int	is_subsequence(char *word, char *sentence)
{
	int	wi;
	int	si;

	wi = 0;
	si = 0;
	while (word[wi] && sentence[si])
	{
		if (word[wi] == sentence[si])
			wi++;
		si++;
	}
	return (word[wi] == '\0');
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (is_subsequence(argv[1], argv[2]))
	{
		put_str(argv[1]);
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}