#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define MAX_CHARACTERS 26
// Map character to the array index.
#define INDEX(c) ((int)c - (int)'a')

// structure to store trie info.
typedef struct trie
{
	struct trie* arr[MAX_CHARACTERS];
	bool is_word_end;
}trie_t;

// create an object of trie.
trie_t* create()
{
	trie_t* temp = malloc(sizeof(trie_t));
	int i = 0;
	
	while(i < MAX_CHARACTERS)
		temp->arr[i++] = NULL;
	
	temp->is_word_end = false;
	
	return temp;
}

// add an element in the trie.
void add_element(trie_t* root, char* name)
{
	int length = strlen(name);
	int i = 0;
	
	for(;i < length; i++)
	{
		if(root->arr[INDEX(name[i])] == NULL)
		{
			root->arr[INDEX(name[i])] = create();
		}
		root = root->arr[INDEX(name[i])];
	}
	root->is_word_end = true;
}

// search a string in trie.
void search(trie_t* root, char* name)
{
	int length = strlen(name);
	int i = 0;
	
	for(; i < length; i++)
	{
		if(NULL == root->arr[INDEX(name[i])])
		{
			printf("Word not found.\n");
			return;
		}
		root = root->arr[INDEX(name[i])];
	}
	if(true == root->is_word_end)
		printf("Word found");
	else
		printf("Word not found.\n");
}

void main()
{
	trie_t* root = create();
	
	add_element(root, "kishan");
	add_element(root, "kiabcdef");
	add_element(root, "kish");
	search(root, "kisha");
}