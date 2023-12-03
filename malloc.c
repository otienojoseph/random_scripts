#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
  * _strdup - Return pointer to new string with a duplicate
  * of the string str
  * @str: string to be duplicated
  * Return: Pointer to duplicated string
  */

char *_strdup(char *str)
{
  int str_len, i;
  char *ptr_str;

  ptr_str = (char *) malloc(str_len * sizeof(char));

  if (str_len == 0)
  {
    return (NULL);
  }

  if (ptr_str != NULL)
  {
    for (i = 0; str[i]; i++)
        ptr_str[i] = str[i];
    ptr_str[i] = '\0';

    return (ptr_str);
  }
  else
  {
    return (NULL);
  }
}
