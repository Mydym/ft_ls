#include "libft.h"
#include <dirent.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	char	**list;
	int		i;

	i = 0;
	if (argc == 2)
	{
		list = ft_readdir(argv[1]);
		while (list[i] != NULL)
		{
			ft_putendl(list[i]);
			i++;
		}
	}
	return (0);
}
