#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/***********************************************************

	Structures to be used to store queue and linked list

***********************************************************/

// node of the linked list.
typedef struct node
{
	int data;
	struct node* next;
}node_t;

// structure to store front and rear of queue.
typedef struct queue
{
	node_t* front;
	node_t* rear;
}queue_t;

// Structure containing top, size and capacity of the stack.
typedef struct stack 
{
	queue_t* q1;
	queue_t* q2;
}stack_t;

/***********************************************************************

	Queue helper functions
	
***********************************************************************/

// Initialize the queue.
queue_t* create_queue()
{
	queue_t* temp = malloc(sizeof(queue_t));
	
	temp->front = temp->rear = NULL;
	
	return temp;
}

// check if queue is empty.
bool is_queue_empty(queue_t* queue_ptr)
{
	return (queue_ptr->front == NULL);
}

// enqueue an element to the queue.
void enqueue(queue_t* queue_ptr, int data)
{
	node_t* temp = malloc(sizeof(node_t));
	temp->data = data;
	temp->next = NULL;

	if(queue_ptr->rear == NULL)
		queue_ptr->rear = queue_ptr->front = temp;
	else
	{
		(queue_ptr->rear)->next = temp;
		queue_ptr->rear = temp;
	}
}

// dequeue an element from the queue.
int dequeue(queue_t* queue_ptr)
{
	if(is_queue_empty(queue_ptr))
	{
		printf("Queue is empty. Can't delete element.");
		return INT_MAX;
	}
	
	node_t* temp = queue_ptr->front;
	int dequeue_element = temp->data;
	queue_ptr->front = temp->next;
	
	if(queue_ptr->front == NULL)
		queue_ptr->rear = NULL;
	
	free(temp);
	
	return dequeue_element;
}

// Create a stack of specified capacity.
stack_t* create_stack()
{
	stack_t* temp = malloc(sizeof(stack_t));
	
	temp->q1 = create_queue();
	temp->q2 = create_queue();
	
	return temp;
}

/*****************************************************************

	Stack functionality using queue

*****************************************************************/

// push element to the stack.
void push(stack_t* stack_ptr, int data)
{
	// enqueue to queue q1.
	enqueue(stack_ptr->q1, data);
}

// pop element from the stack.
void pop(stack_t* stack_ptr)
{
	// Check if queue q1 is empty or not.
	if(is_queue_empty(stack_ptr->q1))
	{
		printf("Stack is empty. Can't delete elements");
		return;
	}

	int data;
	queue_t* temp;

	// dequeue all elements from q1 to q2 
	// except last element.
	while(stack_ptr->q1->front != stack_ptr->q1->rear)
	{
		data = dequeue(stack_ptr->q1);
		enqueue(stack_ptr->q2, data);
	}
	
	// dequeue the last element which is ultimately 
	// top element of the stack.
	dequeue(stack_ptr->q1);
	
	// swap the q1 and q2 pointers.
	temp = stack_ptr->q1;
	stack_ptr->q1 = stack_ptr->q2;
	stack_ptr->q2 = temp;
}

// display elements available in the stack.
void display(stack_t* stack_ptr)
{
	node_t* temp = stack_ptr->q1->front;
	
	while(temp)
	{
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	
	printf("\n");
}

int main()
{
    stack_t* stack_ptr = create_stack();

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