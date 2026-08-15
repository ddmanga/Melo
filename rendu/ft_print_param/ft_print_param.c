/* ft_print_param — écris ton code ici.
 * Sujet : exercises_exam/ft_print_param
 */

#include <unistd.h>

void	ft_print_param(char c)
{
	write(1, &c, 1);
}