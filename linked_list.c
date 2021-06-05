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

void remove_loop(node_t* slow_ptr, node_t* head)
{
	int count = 0;
	node_t* prev = NULL;
	node_t* ptr1 = NULL;
	node_t* ptr2 = NULL;
	
	ptr1 = slow_ptr->next;
	
	while(ptr1 != slow_ptr)
	{
		count++;
		ptr1 = ptr1->next;
	}
	
	ptr1 = head;
	ptr2 = head;
	while(count)
	{
		ptr2 = ptr2->next;
		count--;
	}
	
	while(ptr1 != ptr2)
	{
		prev = ptr2;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	
	prev->next = NULL;
}

void detect_and_remove_loop(node_t* head)
{
	node_t* slow_ptr = head;
	node_t* fast_ptr = head;
	
	while(slow_ptr && fast_ptr && fast_ptr->next)
	{
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
		if(slow_ptr == fast_ptr)
			remove_loop(slow_ptr, head);
	}
	if(fast_ptr != slow_ptr)
		printf("No loop detected.\n");
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
	add_element_at_end(&head, 7);
	add_element_at_end(&head, 8);
	add_element_at_end(&head, 9);
	add_element_at_end(&head, 10);
	add_element_at_end(&head, 11);
	display(head);
	
	head = reverse(head);
	display(head);
	
	node_t* temp = reverse_recursive(&head, head);
	temp->next = NULL;
	display(head);
	
	head = reverse_alternate_k_nodes(head, 2);
	display(head);
	
	detect_and_remove_loop(head);
}