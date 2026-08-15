/* ft_swap — écris ton code ici.
 * Sujet : exercises_exam/ft_swap
 */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}