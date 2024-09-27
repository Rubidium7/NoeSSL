#include "vessl.h"

uint8_t	*add_padding(const char *str, size_t len)
{
	uint8_t		*out = NULL;
	uint64_t	og_len_in_bits = (strlen(str) * 8) % (size_t)(pow(2, 64));

	out = calloc(len, 1);
	if (!out)
		return (NULL);

	memcpy(out, str, strlen(str));
	out[strlen(str)] = 128; //in binary = 10000000
	// printf("%ld\n", (len + 4) * 8);
	memcpy(out + len - 4, &og_len_in_bits, 4);

	// uint8_t *p;
	// p=(uint8_t *)&og_len_in_bits;
	// printf("%2.2x%2.2x%2.2x%2.2x\n", p[0], p[1], p[2], p[3]);

	// printf("%s\n", out);
	// print_in_hex(out, len);
	return (out);
}

// AND &
// OR |
// NOT ~
// XOR ^

//input broken into 512-bit blocks (16 * 32-bit words)

uint32_t	*hash_loop(const uint8_t *str, size_t len, uint32_t *hash)
{
	size_t	i = 0;
	
	while (i < ((len + 4)))
	{
		uint32_t	*words = (uint32_t *)(str + i);

		uint32_t a = hash[0];
		uint32_t b = hash[1];
		uint32_t c = hash[2];
		uint32_t d = hash[3];

		for (size_t j = 0; j != 64; j++)
		{
			uint32_t e;
			uint32_t k;

			switch (j / 16)
			{
				case 0:
					e = F(b, c, d);
					k = j;
					break ;
				case 1:
					e = G(b, c, d);
					k = (j * 5 + 1) % 16;
					break ;
				case 2:
					e = H(b, c , d);
					k = (j * 3 + 5) % 16;
					break ;
				case 3:
					e = I(b, c, d);
					k = (j * 7) % 16;
					break ;
			}

			uint32_t temp = b + ROT_LEFT((a + e + K[j] + words[k]), S[j]);
			a = d;
			d = c;
			c = b;
			b = temp;
		}
		hash[0] += a;
		hash[1] += b;
		hash[2] += c;
		hash[3] += d;

		i += 64;
	}
	return (hash);
}

void	md5(const char *str)
{
	uint32_t hash[4] = {A, B, C, D};
	size_t len = ((((strlen(str) + 8) / 64) + 1) * 64) - 8 + 4;

	uint8_t	*padded = add_padding(str, len);
	if (!padded)
	{
		error(MALLOC_FAIL);
		return ;
	}
	hash_loop(padded, len, hash);
	print_hash(hash, 4);
	free(padded);
}