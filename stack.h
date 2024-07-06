#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int data;
	struct node* next;
}node;

node* createNode(int data);
int insertHead(node** head, int data);
int decap(node** head);
int isEmpty(node** stack);
void push(node** stack, int data);
int pop(node** stack);
int getTop(node** stack);
int stackPrint(node** stack);

#endif
