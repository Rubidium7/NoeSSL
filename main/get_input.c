#include "vessl.h"

char	*read_from_fd(int fd)
{
	char	*out;
	char	buffer[BUFFER_SIZE];
	int 	ret;

	out = calloc(1, 1);
	if (!out)
		return NULL;
	bzero(buffer, BUFFER_SIZE);
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		char *tmp = out;
		out = ft_strjoin(out, buffer);
		free(tmp);
		bzero(buffer, BUFFER_SIZE);
		if (!out)
			return NULL;
	}
	if (ret < 0)
		return (NULL);
	return (out);
}

char	*get_input(int arg_amount, const char **array)
{
	int		fd = NO_FD;
	char	*out = NULL;

	// printf("arg count = %d\n", arg_amount);
	// print_array(array);
	
	switch (arg_amount)
	{
		case 1:
			fd = STDIN_FILENO;
			break;
		case 2:
			fd = open(array[1], O_RDONLY);
			break;
		case 3:
			if (strcmp(array[1], "-s"))
				print_flag_error(array[1]);
			else
				out = strdup(array[2]);
			break ;
	}
	if (fd != NO_FD && fd != ERROR_FD)
		out = read_from_fd(fd);
	if (fd == ERROR_FD)
		error(FILE_NOT_OPEN);
	else if (!out)
		error(MALLOC_FAIL);
	return (out);
}