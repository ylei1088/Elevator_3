#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

void append(struct Node **head, int new_data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node *last = *head;
	new_node->data = new_data;
	new_node->next = NULL;
	if(*head == NULL){
		*head = new_node;
		return;
	}

	while(last->next != NULL){
		last = last->next;
	}
	last->next = new_node;
}

void print_list(struct Node *n)
{
	while(n != NULL){
		printf("%d\n", n->data);
		n = n->next;
	}
}

void clear_list(struct Node** n)
{
	struct Node* current = *n;
	struct Node* next;
	while(current != NULL){
		next = current->next;
		free(current);
		current = next;
	}
	//Dangling Pointer cleanup
	*n = NULL;
}


int main()
{
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;

	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));

	head->data = 1;
	head->next = second;
	second->data = 2;
	second->next = third;
	third->data = 3;
	third->next = NULL;

	print_list(head);
    append(&head, 10);
    print_list(head);
	clear_list(&head);

}