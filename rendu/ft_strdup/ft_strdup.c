/* ft_strdup — écris ton code ici.
 * Sujet : exercises_exam/ft_strdup
 */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dup;

	if (!src)
		return (NULL);
	i = 0;
	while (src[i])
		i++;
	dup = (char *)malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}