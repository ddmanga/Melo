/* fizzbuzz — écris ton code ici.
 * Sujet : exercises_exam/fizzbuzz
 */

 #include <unistd.h>

static void	print_nbr(int n)
{
	char	c;

	if (n > 9)
		print_nbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	ft_fizzbuzz(void)
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if (i % 15 == 0)
			write(1, "FizzBuzz", 8);
		else if (i % 3 == 0)
			write(1, "Fizz", 4);
		else if (i % 5 == 0)
			write(1, "Buzz", 4);
		else
			print_nbr(i);
		write(1, "\n", 1);
		i++;
	}
}
