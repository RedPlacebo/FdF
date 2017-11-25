#include <stdlib.h>

char	*ft_realloc(char *str, int size)
{
	char *temp;
	int i;
	
	temp = str;
	str = (char *)malloc(sizeof(char) * size);
	i = 0;
	while (temp[i])
	{
		str[i] = temp[i];
		i++;
	}
	free(temp);
	return (str);
}	
