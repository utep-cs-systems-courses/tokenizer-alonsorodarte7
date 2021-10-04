#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  if(c == ' ' || c == '\t')
    return 1;
  return 0;
}
int non_space_char(char c)
{
  if(c == ' ' || c == '\t')
    return 0;
  return 1;
}
char *word_start(char *str)
{
  int i = 0;
  while(space_char(*(str+i)) && *(str+i) != '\0')
    {
      i++;
    }
  return (str+i);
}
char *word_terminator(char *str)
{
  int i = 0;
  while(non_space_char(*(str+i)) && *(str+i) != '\0')
    {
      i++;
    }
  return (str+i);
}
int count_words(char *str)
{
  int i = 0;
  while(*(str) != '\0')
    {
      str = word_start(str);
      str = word_terminator(str);
      i++;
    }
  return i;
}
short find_len(char *str)
{
  short i = 0;
  while(str[i] != '\0')
    {
      i++;
    }
  return i;
}
char *copy_str(char *inStr, short len)
{
  int i = 0;
  char *str = malloc(len+1);
  while(i < len || *(inStr+i) != '\0')
    {
      str[i] = inStr[i];
      i++;
    }
  str[len] = '\0';
  return str;
}
char **tokenize(char *str)
{
  
}





