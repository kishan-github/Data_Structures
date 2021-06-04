#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure containing top, size and capacity of the stack.
typedef struct stack 
{
	int top;					// current top element index.
	unsigned int size;			// no of elements in stack.
	unsigned int capacity;		// no of elements that can be stored in stack.
	int *stack_arr;				// array storing stack elements;
}stack_t;

// Create a stack of specified capacity.
stack_t* create_stack(unsigned int capacity)
{
	stack_t* temp = malloc(sizeof(stack_t));
	
	temp->top = -1;										// initially no elements in the stack.
	temp->size = 0;										// initially no elements in the stack.
	temp->capacity = capacity;						
	temp->stack_arr = malloc(sizeof(int) * capacity);
	
	return temp;
}

// is the stack capacity full.
bool is_stack_full(stack_t* stack_ptr)
{
	return (stack_ptr->size == stack_ptr->capacity);
}

// is the stack empty.
bool is_stack_empty(stack_t* stack_ptr)
{
	return (stack_ptr->size == 0);
}

// push element to the stack.
void push(stack_t* stack_ptr, int data)
{
	if(is_stack_full(stack_ptr))
	{
		printf("Stack is full. Can't add elements");
		return;
	}
	
	stack_ptr->stack_arr[++(stack_ptr->top)] = data;
	(stack_ptr->size)++;
}

// pop element from the stack.
void pop(stack_t* stack_ptr)
{
	if(is_stack_empty(stack_ptr))
	{
		printf("Stack is empty. Can't delete elements");
		return;
	}
	
	(stack_ptr->top)--;
	(stack_ptr->size)--;
}

// display elements available in the stack.
void display(stack_t* stack_ptr)
{
	int i = 0;
	
	for(; i < stack_ptr->size; i++)
		printf("%d\t", (stack_ptr->stack_arr)[i]);
	
	printf("\n");
}

int main()
{
    stack_t* stack_ptr = create_stack(100);
	
	push(stack_ptr, 10);
	push(stack_ptr, 1);
	push(stack_ptr, 20);
	push(stack_ptr, 25);
	push(stack_ptr, 9);
	
	display(stack_ptr);
	
	pop(stack_ptr);
	display(stack_ptr);
	
	pop(stack_ptr);
	display(stack_ptr);
	
	push(stack_ptr, 35);
	display(stack_ptr);

    return 0;
}
