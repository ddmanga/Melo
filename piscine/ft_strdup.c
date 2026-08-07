#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	dup = NULL;
	i = 0;
	while (src[i])
	{
		dup[i] = src[i]; // Écriture dans un pointeur NULL
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	main(void)
{
	char	*str;

	str = ft_strdup("Bonjour 42 !");
	printf("%s\n", str);
	free(str);
	return (0);
}