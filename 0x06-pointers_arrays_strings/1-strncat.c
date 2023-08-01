#include "main.h"

/**
 *_strcat - concatenates  the string pointed to by @src to
 * the end of the string pointed to by @dest
 *@dest: String that will be appended
 *@src: String to be concatenated upon
 *
 * Return: returns poiner to @dest
 */

char *_strcat(char *dest, char *src)
{

	int index = 0, dest_len = 0;

	while (dest[index++])
	{
		dest_len++;
	}

	dest_len = 0;
	while (src[j] != '\0')
	{
		dest[index] = src[dest_len];
		index++;
		dest_len++;
	}

	dest[index] = '\0';
	return (dest);
}
