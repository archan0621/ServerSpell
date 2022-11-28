#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* DeleteChar(char s[], char ch)
{
	char* str = (char*)malloc(sizeof(s));
	int i, k = 0;
	for (i = 0; i < strlen(s); i++)
		if (s[i] != ch) str[k++] = s[i];

	str[k] = '\0';
	return str;
}
