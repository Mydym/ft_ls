#include "libft.h"
#include <stdlib.h>

char	**ft_strreaddir(const char *file)
{
	DIR		*doc;
	char	**list;
	int		i;

	i = 0;
	if ((list = (char **)malloc(512 * sizeof(char *))) != NULL)
		if ((doc = ft_opendir(file)) != NULL)
		{
			while ((list[i] = ft_strreadfile(doc)) != NULL)
				i++;
			closedir(doc);
		}
	return (list);
}
