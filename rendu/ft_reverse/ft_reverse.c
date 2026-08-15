/* ft_reverse — écris ton code ici.
 * Sujet : exercises_exam/ft_reverse
 */

static void	swap_char(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_reverse(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
		i++;
	j = i - 1;
	i = 0;
	while (i < j)
	{
		swap_char(&str[i], &str[j]);
		i++;
		j--;
	}
}