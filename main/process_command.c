#include "vessl.h"


int	process_command(char **args)
{
	int i;

	for (i = 0; i != COMMAND_AMOUNT; i++)
		if (!strcmp(args[0], COMMANDS[i]))
			break ;
	if (i == COMMAND_AMOUNT)
	{
		print_command_error(args[0]);
		return (WRONG_COMMAND);
	}
	switch (i)
	{
		case 0:
			if (!args[1])
				break;
			char *hash = md5(args[1]);
			if (hash)
			{
				printf("%s\n", hash);
				free(hash);
			}
			else
				dprintf(STDERR_FILENO, "malloc failed\n");
			break;
	
	}
	return (SUCCESS);
}