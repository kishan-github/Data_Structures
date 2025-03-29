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

// reverse k nodes.
node_t* reverse_k_nodes(node_t* head, int k)
{
	node_t* curr = head;
	node_t* next = NULL;
	node_t* prev = NULL;
	int count = k;
	
	// reverse k elements
	while(curr && count)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count--;
	}
	
	// if more elements then reverse then again.
	if(next)
		head->next = reverse_k_nodes(next, k);
	
	return prev;
}

// reverse alternate k nodes.
// reverse k nodes.
node_t* reverse_alternate_k_nodes(node_t* head, int k)
{
	node_t* curr = head;
	node_t* next = NULL;
	node_t* prev = NULL;
	int count = k;
	
	// reverse k elements.
	while(curr && count)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count--;
	}
	
	// last node of reversed list will point to
	// next node as we need ti skip next k nodes.
	head->next = next;
	count = k;
	while(next && count)
	{
	    curr = next;
		next = curr->next;
		count--;
	}
	
	// if more nodes remaining, reverse them also.
	if(next)
		curr->next = reverse_alternate_k_nodes(next, k);
	
	return prev;
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
	node_t* head = NULL, *temp = NULL;

    add_element_at_end(&head, 1);
	add_element_at_end(&head, 2);
	add_element_at_end(&head, 3);
	add_element_at_end(&head, 4);
	add_element_at_end(&head, 5);
	add_element_at_end(&head, 6);
    add_element_at_end(&head, 7);

    display(head);

    head = reverse_k_nodes(head,3);
    display(head);

    head = reverse_k_nodes(head,3);
    display(head);

    head = reverse_alternate_k_nodes(head,2);
    display(head);
}