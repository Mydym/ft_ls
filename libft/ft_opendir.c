#include <dirent.h>

DIR	*ft_opendir(const char *file)
{
	DIR *repo;

	repo = opendir(file);
	if (repo)
		return (repo);
	else
		return (repo);
}
