/* ft_split — écris ton code ici.
 * Sujet : exercises_exam/ft_split
 */

#include <stdlib.h>

static int	count_words(char *str, char sep)
{
	int	count;
	int	in_word;
	int	i;

	count = 0;
	in_word = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != sep && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (str[i] == sep)
			in_word = 0;
		i++;
	}
	return (count);
}

static int	word_len(char *str, char sep)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != sep)
		len++;
	return (len);
}

static char	*extract_word(char *str, int len)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char sep)
{
	char	**result;
	int		nb_words;
	int		i;
	int		len;

	nb_words = count_words(str, sep);
	result = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < nb_words)
	{
		while (*str == sep)
			str++;
		len = word_len(str, sep);
		result[i] = extract_word(str, len);
		str += len;
		i++;
	}
	result[nb_words] = NULL;
	return (result);
}