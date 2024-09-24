#include "vessl.h"

char	*md5(const char *str)
{
	char *out;
	
	(void)str;
	out = malloc(sizeof(char) * (MD5_SIZE + 1));
	if (!out)
		return (NULL);
	for (int i = 0; i != MD5_SIZE; i++)
		out[i] = i + '0';
	out[MD5_SIZE] = '\0';
	return (out);
}