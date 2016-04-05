#include "libft.h"
#include <dirent.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	DIR		*doc;
	char	*file;
	char	**list;
	int		i;

	i = 0;
	if ((list = (char **)malloc(512 * sizeof(char *))) != NULL)
		if (argc == 2)
			if ((doc = ft_opendir(argv[1])) != NULL)
			{
				while ((file = ft_readdir(doc)) != NULL)
				{
					list[i] = file;
					i++;
				}
				closedir(doc);
			}
	list[i] = NULL;
	return (0);
}
