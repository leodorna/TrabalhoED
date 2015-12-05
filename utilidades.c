#include <stdio.h>
#include "utilidades.h"

void lowerString(char *palavra)
{
	int i = 0;
	
	while(palavra[i] != '\0')
	{
		printf("a");
		palavra[i] = tolower(palavra[i]);
		i++;	
	}
	
}
