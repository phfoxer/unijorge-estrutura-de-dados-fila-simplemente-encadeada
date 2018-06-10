#ifndef pilha_h
#define pilha_h
#define MAX 100
#include <stdio.h>
typedef int stack_data_type;

typedef struct{
	stack_data_type item[MAX];
	int top;
}stack_type;

void initStack(stack_type *p){
	
	p->top = -1;
}

 int fullStack(stack_type *p){

	if(p->top == MAX - 1)
	{
		return 1; 
	} 	
	else
	{
		return 0;
	}
}

int emptyStack(stack_type *p){
	
	if(p->top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int push(stack_type *p,stack_data_type e){
	
	if(fullStack(p))
	{
		return 0;
	}
	else
	{
		p->top++;
		p->item[p->top] = e;
		return 1;	
	}
}
	
int pop(stack_type *p, stack_data_type *e){
	
	if(emptyStack(p))
	{
		return 0;
	}
	else
	{
		*e = p->item[p->top];
		p->top--;
		return 1;
	} 	
}	

int stackTop(stack_type *p, stack_data_type *e){
	
	if(emptyStack(p))
	{
		return 0;
	}
	else
	{
		*e = p->item[p->top];		
		return 1;
	} 	
}

int altura_pilha(stack_type *p){
	return p->top + 1;
}

void showStack(stack_type p){ //Essa função eu imprimo todos os valores que estão dentro da pilha.
	stack_data_type e;
	
	while(!emptyStack(&p)){
		pop(&p, &e);
		printf("%d \n",e);
	}
}

#endif
