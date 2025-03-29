#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Structure for linked list.
typedef struct node
{
	int data;
	struct node* next;
}node_t;

// create node.
node_t* create_node(int data)
{
	node_t* temp = malloc(sizeof(node_t));
	
	temp->data = data;
	temp->next = NULL;
	
	return temp;
}

// add node at the beginning.
void add_element_at_beginning(node_t** head, int data)
{
	node_t* temp = create_node(data);
	
	temp->next = *head;
	*head = temp;
}

// add node at the end.
void add_element_at_end(node_t** head, int data)
{
	node_t* new_node = create_node(data);
	node_t* temp = *head;
	
	if(NULL == temp)
	{
		*head = new_node;
		return;
	}
	
	while(temp->next)
		temp = temp->next;
	
	temp->next = new_node;
}

void display(node_t* head)
{
	while(head)
	{
		printf("%d\t", head->data);
		head = head->next;
	}
	printf("\n");
}

void main()
{
	node_t* head = NULL;
	
	add_element_at_beginning(&head, 1);
	add_element_at_end(&head, 2);
	add_element_at_end(&head, 3);
	add_element_at_end(&head, 4);
	add_element_at_end(&head, 5);
	add_element_at_end(&head, 6);
	display(head);
    add_element_at_end(&head, 7);
    display(head);
    add_element_at_beginning(&head, 8);
    display(head);
}