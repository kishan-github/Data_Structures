// Implemented queue using linked list.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
void dequeue(queue_t* queue_ptr)
{
	if(is_queue_empty(queue_ptr))
	{
		printf("Queue is empty. Can't delete element.");
		return;
	}
	
	node_t* temp = queue_ptr->front;
	queue_ptr->front = temp->next;
	
	if(queue_ptr->front == NULL)
		queue_ptr->rear = NULL;
	
	free(temp);
}

void display(queue_t* queue_ptr)
{
	node_t* temp = queue_ptr->front;
	
	while(temp)
	{
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void main()
{
	queue_t* queue_ptr = create_queue();
	
	enqueue(queue_ptr, 10);
	display(queue_ptr);
	
	enqueue(queue_ptr, 20);
	display(queue_ptr);
	
	enqueue(queue_ptr, 30);
	display(queue_ptr);
	
	enqueue(queue_ptr, 40);
	display(queue_ptr);
	
	enqueue(queue_ptr, 50);
	display(queue_ptr);
	
	dequeue(queue_ptr);
	display(queue_ptr);

	dequeue(queue_ptr);
	display(queue_ptr);

	enqueue(queue_ptr, 10);
	display(queue_ptr);
}
