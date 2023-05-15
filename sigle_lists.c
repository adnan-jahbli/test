#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;

typedef struct node {
	char *data;
	struct node *next;
} node;


char *_getenv(const char *name);
void add_end(node **head, char *str);
void freeLinkedList(node *head);

int main()
{
	node *head, *temp;
	char *p, *word;

	head = NULL;

	p = _getenv("PATH");
	word = strtok(p, ":");
	while (word)
	{
		add_end(&head, word);
		word = strtok(NULL, ":");
	}
	
	temp = head;
	while (temp->next)
	{
		printf("%s\n", temp->data);
		temp = temp->next;
	}

	freeLinkedList(head);

	return(0);
}

char *_getenv(const char *name)
{
	char **p, *word, dest[5024];
 	int len = strlen(name);	
	
	p = environ;

	word = NULL;
	while (*p)
	{
		if (strncmp(*p, name, len) == 0) 
		{	
			strcpy(dest, *p);
			word = strtok(dest, "=");
			word = strtok(NULL, "=");
		}
		p++;
	}
	return word;
}

void add_end(node **head, char *str)
{
	node *temp;
	node *p;

	p = malloc(sizeof(node));
	if (!p)
	{
		printf("Error: malloca failed\n");
		exit(98);
	}
	p->data = str;
	p->next = NULL;


	if (!*head)
		*head = p;
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = p;
	}
}
void freeLinkedList(node *head)
{
	node *temp;
	node *current = head;
    
	while (current != NULL) 
	{
        	temp = current->next;
        	free(current);
        	current = temp;
	}
}
