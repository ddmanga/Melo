/* ft_putnbr — écris ton code ici.
 * Sujet : exercises_exam/ft_putnbr
 */

#include <unistd.h>

void ft_putnbr(int a)
{
    char c;
    if (a == -2147483648)
    {
        write(1, "-2147483648", 11);
        return;
    }
    if (a < 0)
    {
        write(1, "-", 1);
        a *= -1;
    }
    if (a > 9)
    {
        ft_putnbr(a / 10);
    }
    c = a % 10 + '0';
    write(1, &c, 1);
}