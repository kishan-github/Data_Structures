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

// reverse list.
node_t* reverse(node_t* head)
{
	node_t* curr = head;
	node_t* next = NULL;
	node_t* prev = NULL;
	
	while(curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	
	return prev;
}

// reverse list recursively.
node_t* reverse_recursive(node_t** head, node_t* curr)
{
	if(curr->next == NULL)
	{
		*head = curr;
		return curr;
	}
	
	// node returned is the next of curr node.
	node_t* temp = reverse_recursive(head, curr->next);
	temp->next = curr;
	return curr;
}


void main()
{
	node_t* head = NULL, *temp = NULL;

    add_element_at_end(&head, 1);
	add_element_at_end(&head, 2);
	add_element_at_end(&head, 3);
	add_element_at_end(&head, 4);
	add_element_at_end(&head, 5);
	add_element_at_end(&head, 6);
    add_element_at_end(&head, 7);

    display(head);

    head = reverse(head);
    display(head);

    temp = reverse_recursive(&head, head);
    temp->next = NULL;
    display(head);
}