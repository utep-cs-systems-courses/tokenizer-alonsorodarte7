#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

int c = 0;
List *init_history()
{
  List *head = (List*)malloc(sizeof(List));
  head->root = NULL;
  return head;
}
void add_history(List *list, char *str)
{
  Item *temp = list->root;
  if(list->root == NULL)
    {
      list->root = (Item*)malloc(sizeof(Item));
      list->root->id = c++;
      list->root->str = copy_str(str,find_len(str));
      list->root->next = NULL;
    }
  else
    {
      while(temp->next != NULL)
	{
	  temp = temp->next;
	}
      temp->next = (Item*)malloc(sizeof(Item));
      temp->next->id = c++;
      temp->next->str = copy_str(str,find_len(str));
      temp->next->next = NULL;
    }
}
char *get_history(List *list, int id)
{
  Item *temp = list->root;
  while(temp != NULL)
    {
      if(temp->id == id)
	{
	  return temp->str;
	}
      temp = temp->next;
    }
}
void print_history(List *list)
{
  Item *temp = list->root;
  while(temp != NULL)
    {
      printf("%i. %s\n",temp->id,temp->str);
      temp = temp->next;
    }
  printf("\n");
}
void free_history(List *list)
{
  Item *temp = list->root;
  while(temp!=NULL)
    {
      free(temp->str);
      free(temp);
    }
}






