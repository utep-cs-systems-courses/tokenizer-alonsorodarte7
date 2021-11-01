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
  char *str = (char*)malloc((len+1)*sizeof(char));
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
  int word_len = count_words(str);
  //Reserves memory used for string
  char **tokens=(char**)malloc(sizeof(char*)*(word_len+1));

  //Initializes the start and end pointers
  char *start = str;
  char *end = word_terminator(str);
  
  
  for(int i = 0; i < word_len; i++)
    {
      //Initializes the pointers to the next start and end of current word
      if(i > 0)
	{
	  start = word_start(end);
	  end = word_terminator(start);
	}
      //Finds the length of the current word
      int word_size = end - start;

      //Reserves memory for current word in 2D array
      tokens[i] = malloc(word_len*sizeof(char));

      //Populates array with the current word
      for(int j = 0;j < word_size;j++)
	{
	  tokens[i][j] = start[j];
	}
    }
  //Last is 0
  tokens[word_len] = 0;
  return tokens;
}
//Prints all tokens
void print_tokens(char **tokens)
{
  for(int i = 0; tokens[i] != 0; i++)
    {
      printf("tokens[%i] = %s\n",i,tokens[i]);
    }
}
//Frees all tokens and the vector containing them
void free_tokens(char **tokens)
{
  for(int i = 0;tokens[i] != 0; i++)
    {
      //Frees each word of tokens
      free(tokens[i]);
    }
  //Frees the overall space of tokens
  free(tokens);
}
