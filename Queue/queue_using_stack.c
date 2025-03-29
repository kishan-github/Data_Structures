#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Structure containing top, size and capacity of the stack.
typedef struct stack 
{
	int top;					// current top element index.
	unsigned int capacity;		// no of elements that can be stored in stack.
	int *stack_arr;				// array storing stack elements;
}stack_t;

// Queue structure to store both the stacks.
typedef struct queue
{
	stack_t* s1;
	stack_t* s2;
}queue_t;

/***********************************************************************************

	Methods specific to stack implementation.

***********************************************************************************/

// Create a stack of specified capacity.
stack_t* create_stack(unsigned int capacity)
{
	stack_t* temp = malloc(sizeof(stack_t));
	
	temp->top = -1;										// initially no elements in the stack.
	temp->capacity = capacity;						
	temp->stack_arr = malloc(sizeof(int) * capacity);
	
	return temp;
}

// is the stack capacity full.
bool is_stack_full(stack_t* stack_ptr)
{
	return ((stack_ptr->top + 1) == stack_ptr->capacity);
}

// is the stack empty.
bool is_stack_empty(stack_t* stack_ptr)
{
	return (stack_ptr->top == -1);
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
}

// pop element from the stack.
int pop(stack_t* stack_ptr)
{
	if(is_stack_empty(stack_ptr))
	{
		printf("Stack is empty. Can't delete elements");
		return INT_MAX;
	}
	
	int temp = stack_ptr->stack_arr[(stack_ptr->top)--];
	return temp;
}

/********************************************************************

	Methods for implementing queue using stack.

********************************************************************/

// Create a queue.
queue_t* create_queue(int capacity)
{
	queue_t* queue_temp = malloc(sizeof(queue_t));
	
	queue_temp->s1 = create_stack(capacity);
	queue_temp->s2 = NULL;
}

// enqueue.
void enqueue(queue_t* queue_ptr, int data)
{
	// just push the data to stack s1.
	push(queue_ptr->s1, data);
}

// dequeue
int dequeue(queue_t* queue_ptr)
{
	int temp;
	
	// if stack s2 have elements, just pop.
	if(queue_ptr->s2)
	{
		temp = pop(queue_ptr->s2);
		// if no elements remaining in the stack s2,
		// free the memory occupeid by stack array 
		// stack itself and set it to NULL.
		if(queue_ptr->s2->top == -1)
		{
			free(queue_ptr->s2->stack_arr);
			free(queue_ptr->s2);
			queue_ptr->s2 = NULL;
		}
	}
	// if only one element in the queue,
	// just pop that element.
	else if((queue_ptr->s1->top + 1) == 1)
	{
		temp = pop(queue_ptr->s1);
	}
	else
	{
		// create stack s2 of capacity one less than 
		// stack s1 because we will not copy the element
		// to be removed.
		queue_ptr->s2 = create_stack(queue_ptr->s1->top);
		
		// iterate while only one element left in stack s1.
		while(queue_ptr->s1->top)
		{
			// pop from s1 and push to s2.
			push(queue_ptr->s2, pop(queue_ptr->s1));
		}
		// pop the element from stack s1.
		temp = pop(queue_ptr->s1);
	}
	return temp;
}

void display(queue_t* queue_ptr)
{
	int i;
	
	if(queue_ptr->s2)
	{
		for(i = queue_ptr->s2->top; i >= 0; i--)
			printf("%d\t", queue_ptr->s2->stack_arr[i]);
	}
	
	for(i = 0; i < (queue_ptr->s1->top + 1); i++)
		printf("%d\t", queue_ptr->s1->stack_arr[i]);
	
	printf("\n");
}

void main()
{
	queue_t* queue_ptr = create_queue(10);
	
	enqueue(queue_ptr, 10);
	enqueue(queue_ptr, 20);
	enqueue(queue_ptr, 30);
	enqueue(queue_ptr, 40);
	display(queue_ptr);
	dequeue(queue_ptr);
	display(queue_ptr);
	enqueue(queue_ptr, 50);
	display(queue_ptr);
}