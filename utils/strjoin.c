#include <stdlib.h>

unsigned long szcounter9000(char const *s1, char const *s2)
{
	unsigned long	loca;
	unsigned long	loca2;

	loca = 0;
	loca2 = 0;
	while (s1[loca] != '\0')
		loca++;
	while (s2[loca2] != '\0')
		loca2++;
	return(loca + loca2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int				loca;
	int				loca2;
	unsigned long	sz;

	loca = 0;
	loca2 = 0;
	sz = szcounter9000(s1, s2);
	char *ans = (char*) malloc ((sz + 1) * sizeof(char));
	while (s1[loca] != '\0')
	{
		ans[loca2] = s1[loca];
		loca2++;
		loca++;
	}
	loca = 0;
	while (s2[loca] != '\0')
	{
		ans[loca2] = s2[loca];
		loca2++;
		loca++;
	}
	ans[loca2] = '\0';
	return(ans);
}