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
# include <fcntl.h>

//process_command.c
int	process_command(int arg_amount, const char **args);

//get_input.c
char	*get_input(int arg_amount, const char **array);

//md5.c
void	md5(const char *input);

//printing_utils.c
void	print_in_hex(const uint8_t *str, size_t len);
void	print_array(const char **array);

//strjoin.c
char	*ft_strjoin(char const *s1, char const *s2);


//error.c
void	print_command_error(const char *command);
void	print_flag_error(const char *flag);
int		error(t_error code);


# endif