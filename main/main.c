#include "vessl.h"

int main(int ac, const char **av)
{
	if (ac < 2)
		return (error(NO_ARGS));

	if (process_command(ac - 1, av + 1))
		return (FAIL);

	return (SUCCESS);
}