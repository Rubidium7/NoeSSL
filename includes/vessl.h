#ifndef VESSL_H
# define VESSL_H

# include "defines.h"
# include "structs.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

//process_command.c
int	process_command(char **args);

//md5.c
char	*md5(const char *str);

//error.c
void	print_command_error(char *command);
int		error(t_error code);


# endif