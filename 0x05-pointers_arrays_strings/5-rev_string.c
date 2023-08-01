#include "main.h"
/**
*rev_string - Reverse a string
*@s: String to reverse
*Return: Nothing
*/
void rev_string(char *s)
{
int i = 0, length;
length = _strlen(s) - 1;
while (length > i)
{
swap_char(s + length, s + i);
i++;
length--;
}
}
