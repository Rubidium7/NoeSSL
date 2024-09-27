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

char	*hash(const uint8_t	*str, size_t len)
{
	size_t	i = 0;
	uint32_t h0 = A;
	uint32_t h1 = B;
	uint32_t h2 = C;
	uint32_t h3 = D;
	
	while (i < ((len + 4)))
	{
		uint32_t	*words = (uint32_t *)(str + i);

		uint32_t a = h0;
		uint32_t b = h1;
		uint32_t c = h2;
		uint32_t d = h3;

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
		h0 += a;
		h1 += b;
		h2 += c;
		h3 += d;

		i += 64;
	}
	uint8_t *p;
 
    // display result
 
    p=(uint8_t *)&h0;
    printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
 
    p=(uint8_t *)&h1;
    printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
 
    p=(uint8_t *)&h2;
    printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
 
    p=(uint8_t *)&h3;
    printf("%2.2x%2.2x%2.2x%2.2x\n", p[0], p[1], p[2], p[3]);
	return (NULL);
}

void	md5(const char *str)
{
	size_t len = ((((strlen(str) + 8) / 64) + 1) * 64) - 8 + 4;

	uint8_t	*padded = add_padding(str, len);

	hash(padded, len);
	
	free(padded);
}