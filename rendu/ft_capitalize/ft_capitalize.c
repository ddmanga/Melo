/* ft_capitalize — écris ton code ici.
 * Sujet : exercises_exam/ft_capitalize
 */

static char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

static char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

void	ft_capitalize(char *str)
{
	int	i;

	if (!str[0])
		return;
	str[0] = to_upper(str[0]);
	i = 1;
	while (str[i])
	{
		str[i] = to_lower(str[i]);
		i++;
	}
}