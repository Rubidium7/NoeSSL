#include "vessl.h"

void	print_command_error(const char *command)
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

void	print_flag_error(const char *flag)
{
	dprintf(STDERR_FILENO, "%s: Error: '%s' is an invalid flag.\n\n", NAME, flag);

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
	else if (code == FILE_NOT_OPEN)
		dprintf(STDERR_FILENO, "%s: Error: couldn't open input file\n", NAME);
	else if (code == MALLOC_FAIL)
		dprintf(STDERR_FILENO, "%s: Error: malloc failed\n", NAME);

	return (code);
}