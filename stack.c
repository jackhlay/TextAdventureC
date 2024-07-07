#include "stack.h"


node* createNode(int data)
{
	node* newNode = (node*)malloc(sizeof(node));
	if(newNode == NULL){
	return NULL;
	}

	newNode -> data = data;
	newNode->next = NULL;
	return newNode;
}

int stackLength(node* head)
{
	int length = 0;
	node* curr = head;
	while(curr != NULL)
	{
		length++;
		curr = curr->next;
	}
	return length; 
}

int insertHead(node** head, int data)
{
	node* newNode = createNode(data);
	if(!newNode){
		return -1;
	}

	if(*head == NULL){
		*head = newNode;
		return 0;
	}

	newNode->next = *head;
	*head = newNode;
	return 0;
}

int decap(node** head)
{
	if(*head == NULL){
		return -1;
	}
	node* temp = *head;
	*head = (*head)->next;
	free(temp);
	return 0;
}


int isEmpty(node** stack)
{
	return *stack == NULL;
}

void push(node** stack, int data)
{
	if(insertHead(stack, data)){
		printf("STACK OVERFLOW SIR");
	}
}

int pop(node** stack)
{
	if(isEmpty(*stack)){
		printf("Stack underflow (it's empty)");
	}
	int val = (*stack) -> data;
	decap(stack);
	return val;
}

int getTop(node** stack)
{
	if(!isEmpty(*stack)){
		return (*stack)->data;
	}
	else{return -1;}
}


int stackPrint(node** stack)
{
	node* temp = *stack;
	while(temp != NULL){
		printf("%d -> ", temp->data);
		temp=temp->next;
	}
	printf("\n");
}
