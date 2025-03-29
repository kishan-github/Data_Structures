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

void remove_loop(node_t* slow_ptr, node_t* head)
{
	node_t* prev = NULL;
	node_t* ptr1 = head;

    if(slow_ptr == head)
    {
        while (slow_ptr->next != ptr1)
        {
            slow_ptr = slow_ptr->next;
        }
        slow_ptr->next = NULL;
        return;
    }
    while (ptr1 != slow_ptr)
    {
        prev = slow_ptr;
        ptr1 = ptr1->next;
        slow_ptr = slow_ptr->next;
    }

    prev->next = NULL;
}

void detect_and_remove_loop(node_t* head)
{
	node_t* slow_ptr = head;
	node_t* fast_ptr = head;
	
    // Move slow and fast pointers.
	while(slow_ptr && fast_ptr && fast_ptr->next)
	{
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;

        // If loop exists, somewhere slow and fast pointers will meet.
		if(slow_ptr == fast_ptr)
        {
			remove_loop(slow_ptr, head);
            return;
        }
	}
	if(fast_ptr != slow_ptr)
		printf("No loop detected.\n");
}

void add_loop(node_t* head)
{
    node_t* curr = head, *temp = NULL;
    int i = 1;

    while(i <  5)
    {
        curr = curr->next;
        i++;
    }

    temp = curr;

    while(curr->next)
    {
        curr = curr->next;
    }

    curr->next = temp;
}

void main()
{
	node_t* head = NULL;

    add_element_at_end(&head, 1);
	add_element_at_end(&head, 2);
	add_element_at_end(&head, 3);
	add_element_at_end(&head, 4);
	add_element_at_end(&head, 5);
	add_element_at_end(&head, 6);
    add_element_at_end(&head, 7);

    display(head);

    detect_and_remove_loop(head);

    add_loop(head);

    detect_and_remove_loop(head);

    display(head);
}