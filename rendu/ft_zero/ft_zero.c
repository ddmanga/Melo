/* ft_zero — écris ton code ici.
 * Sujet : exercises_exam/ft_zero
 */

void	ft_zero(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = '0';
		i++;
	}
}