/* ft_strlen — écris ton code ici.
 * Sujet : exercises_exam/ft_strlen
 */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}