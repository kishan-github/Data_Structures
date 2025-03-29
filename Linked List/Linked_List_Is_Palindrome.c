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

bool compare_lists(node_t* head1, node_t* head2)
{
    while (head1 && head2)
    {
        if(head1->data != head2->data)
            return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    
    return true;
}

bool isPalindrome(node_t* head)
{
    node_t* slow_ptr = head, *fast_ptr = head, *temp = NULL, *prev = NULL;
    bool isSame = false;

    while (slow_ptr && fast_ptr && fast_ptr->next)
    {
        prev = slow_ptr;
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    temp = reverse(slow_ptr);

    isSame = compare_lists(head, temp);

    prev->next = reverse(temp);
    
    return isSame;
}


void main()
{
	node_t* head = NULL, *temp = NULL;

    add_element_at_end(&head, 1);
	add_element_at_end(&head, 2);
	add_element_at_end(&head, 3);
	add_element_at_end(&head, 4);
    add_element_at_end(&head, 4);
	add_element_at_end(&head, 3);
	add_element_at_end(&head, 2);
    add_element_at_end(&head, 1);

    display(head);

    if(isPalindrome(head))
    {
        printf("List is palindrome.\n");
    }
    else
    {
        printf("List is not palindrome.\n");
    }

    display(head);
}