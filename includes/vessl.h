#ifndef VESSL_H
# define VESSL_H

# include "defines.h"
# include "structs.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <math.h>

//process_command.c
int	process_command(char **args);

//md5.c
char	*md5(const char *str);

//printing_utils.c
void	print_in_hex(const uint8_t *str, size_t len);

//error.c
void	print_command_error(char *command);
int		error(t_error code);


# endif