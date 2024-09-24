#include "vessl.h"

int main(int ac, char **av)
{
	if (ac < 2)
		return (error(NO_ARGS));

	if (process_command(av + 1))
		return (FAIL);

	return (SUCCESS);
}