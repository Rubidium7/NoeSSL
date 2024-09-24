#include "vessl.h"

void	print_command_error(char *command)
{
	dprintf(STDERR_FILENO, "%s: Error: '%s' is an invalid command.\n\n", NAME, command);
	dprintf(STDERR_FILENO, "Commands:\n");
	for (int i = 0; i != COMMAND_AMOUNT; i++)
		dprintf(STDERR_FILENO, "%s\n", COMMANDS[i]);
	if (!FLAG_AMOUNT)
		return ;
	dprintf(STDERR_FILENO, "\nFlags:\n");
	for (int i = 0; i != FLAG_AMOUNT; i++)
		dprintf(STDERR_FILENO, "%s\n", FLAGS[i]);
}

int error(t_error code)
{
	if (code == NO_ARGS)
		dprintf(STDERR_FILENO, "usage: %s <command> [flags] [file/string]\n", NAME);
	return (code);
}