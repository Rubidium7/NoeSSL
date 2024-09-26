#include <stdint.h>
#include <stdio.h>
#include <string.h>


void	print_in_hex(const uint8_t *str, size_t len)
{
	for (size_t i = 0; i != len; i++)
	{
		printf("%x", str[i]);
		if (i + 1 != len)
			printf(" ");
	}
	
	printf("\n");
}