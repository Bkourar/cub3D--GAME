#include "Includs/parse.h"

void ft_error(char *str1, char *str2, char *str3)
{
	if (str1 != NULL)
		write(2, str1, ft_strlen(str1));
	if (str2 != NULL)
		write(2, str2, ft_strlen(str2));
	if (str3 != NULL)
		write(2, str3, ft_strlen(str3));
}