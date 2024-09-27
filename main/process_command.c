#include "vessl.h"


int	process_command(int arg_amount, const char **args)
{
	int i;

	for (i = 0; i != COMMAND_AMOUNT; i++)
		if (!strcmp(args[0], COMMANDS[i]))
			break ;
	if (i == COMMAND_AMOUNT)
	{
		print_command_error(args[0]);
		return (FAIL);
	}
	char *input = get_input(arg_amount, args);
	if (!input)
		return (FAIL);
	switch (i)
	{
		case 0:
			md5(input);
			break;
	
	}
	free(input);
	return (SUCCESS);
}