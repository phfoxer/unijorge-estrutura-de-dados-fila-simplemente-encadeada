#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct NODE_TYPE
{
	int information;
	struct NODE_TYPE *next;
} LIST_TYPE;

LIST_TYPE *startPointer()
{
	return NULL;
}

int listEmpty(LIST_TYPE *pointer)
{
	if (pointer == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

LIST_TYPE *allocateMemory()
{
	LIST_TYPE *newNode;
	newNode = ((LIST_TYPE *)malloc(sizeof(LIST_TYPE)));
	return newNode;
}

/**
* If this method return zero: Not's possible alloc memory
*/
int insertIntoList(LIST_TYPE **listPointer, int value)
{
	LIST_TYPE *auxPointer = NULL, *newNode;
	newNode = allocateMemory();
	if (newNode == NULL)
	{
		return 0;
	}
	else
	{
		newNode->information = value;
		newNode->next = NULL;
		if (listEmpty(*listPointer) == 1)
		{
			*listPointer = newNode;
			return 1;
		}
		else
		{
			auxPointer = *listPointer;
			while (auxPointer->next != NULL)
			{
				auxPointer = auxPointer->next;
			}
			auxPointer->next = newNode;
			return 1;
		}
	}
}


void printStack(LIST_TYPE *listPointer)
{
	LIST_TYPE *auxPointer;
	auxPointer = listPointer;
	while (auxPointer != NULL)
	{
		printf("%d\n", auxPointer->information);
		auxPointer = auxPointer->next;
	}
}

/**
* If returns -1: Empty List
* If return 0: Value not found
*/
int removeElement(LIST_TYPE **listPointer, int value)
{
	if (listEmpty(*listPointer) == 1)
	{
		// Empty list
		return -1;
	}
	else
	{
		LIST_TYPE *auxPointer, *prevPointer;
		prevPointer = startPointer();
		auxPointer = *listPointer;
		while ((auxPointer != NULL) && (auxPointer->information != value))
		{
			prevPointer = auxPointer;
			auxPointer = auxPointer->next;
		}
		if (auxPointer == NULL)
		{
			//Not found
			return 0;
		}
		if (prevPointer == NULL)
		{
			*listPointer = auxPointer->next;
			free(auxPointer);
			auxPointer = NULL;
			return 1;
		}
		else
		{
			prevPointer->next = auxPointer->next;
			free(auxPointer);
			auxPointer = NULL;
			return 1;
		}
	}
}

int destroyList(LIST_TYPE **listPointer)
{
	if (listEmpty(*listPointer) == 1)
	{
		// empty
		return 0;
	}
	else
	{
		LIST_TYPE *auxPointer, *nextNode;
		auxPointer = *listPointer;
		while (auxPointer != NULL)
		{
			nextNode = auxPointer->next;
			free(auxPointer);
			auxPointer = nextNode;
		}
		*listPointer = NULL;
		return 1;
	}
}

int searchItem(LIST_TYPE *listPointer, int value)
{
	if (listEmpty(listPointer) == 1)
	{
		// empty
		return 0;
	}
	else
	{
		LIST_TYPE *auxPointer;
		auxPointer = listPointer;
		while ((auxPointer != NULL) && (auxPointer->information != value))
		{
			auxPointer = auxPointer->next;
		}
		if (auxPointer == NULL)
		{
			// not found
			return 0;
		}
		else
		{
			return 1;
		}
	}
}
