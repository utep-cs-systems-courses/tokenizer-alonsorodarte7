#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int space_char(char c)
{
  if(c == ' ' || c == '\t' || c == '\n' || c == '\0')
    return 1;
  return 0;
}
int non_space_char(char c)
{
  if(c == ' ' || c == '\t' || c == '\n' || c == '\0')
    return 0;
  return 1;
}
char *word_start(char *str)
{
  int i = 0;
  while(space_char(*(str+i)) == 1)
    {
      i++;
    }
  return &*(str+i);
}
char *word_end(char *str)
{
  int i = 0;
  while(non_space_char(*(str+i)) == 1)
    {
      i++;
    }
}
int count_words(char *str)
{
  int i = 0;
  while(non_space_char(*str+i) == 1)
    {
      i++;
    }
  return *(str+i);
}








