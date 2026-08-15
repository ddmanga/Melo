/* ft_putstr — écris ton code ici.
 * Sujet : exercises_exam/ft_putstr
 */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}