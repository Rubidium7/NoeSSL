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

void	print_array(const char **array)
{
	for (int i = 0; array[i]; i++)
		printf("[%d] %s\n", i, array[i]);
}

void	print_hash(uint32_t *hash, size_t len)
{
	uint8_t *p;
 
	for (size_t i = 0; i != len; i++)
	{
    	p = (uint8_t *)&hash[i];
    	printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
	}
	printf("\n");
}