#include <dirent.h>
#include <string.h>

char	*ft_strreadfile(DIR *dirp)
{
	char			*filename;
	struct dirent	*file;

	filename = NULL;
	if ((file = readdir(dirp)))
		filename = file->d_name;
	return (filename);
}
