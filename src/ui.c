#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define LIMIT 100

void main()
{
  char s[LIMIT];
  char **tokenized,*ptr;
  int i, c, id;

  List *history = init_history();
  while(s[0] != '@')
    {
      s[0]=' ';
      i = 0;
      printf("Type @ to quit, $# to find print history item, and ! to show history");

      printf("> ");
      char input = 0;
      int i = 0;
      while(i < LIMIT)
	{
	  input = getchar();
	  if(input == '\n')
	    {
	      break;
	    }
	  s[i] = input;
	  i++;
	}
      s[i] = '\0';
      if(s[0] != '!' && s[0] != '$' && s[0] != '@')
	{
	  ptr = s;
	  tokenized = tokenize(ptr);
	  print_tokens(tokenized);
	  add_history(history,ptr);
	}
      else if(s[0] == '!')
	{
	  print_history(history);
	}
      else if(s[0] == '$')
	{
	  if(s[1] != '\0')
	    {
	      printf("%s \n",get_history(history,s[1] - '0'));
	    }
	}
    }
}
