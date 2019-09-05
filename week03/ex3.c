#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node * next;
};

typedef struct node * linked_list;

void print_list(linked_list);
void insert_node(linked_list *, int);
void delete_node(linked_list *, int);

int main(){
	linked_list arr = (linked_list)malloc(sizeof(struct node));
	arr->data = 5;
	arr->next = NULL;
	print_list(arr);
	insert_node(&arr, 4);
	insert_node(&arr, 30);
	insert_node(&arr, 56);
	delete_node(&arr, 30);
	print_list(arr);
	return 0;
}

void print_list(linked_list list){
	linked_list cur = list;
	printf("The elements of linked list: ");
	while( cur != NULL){
		printf("%d ", cur->data);
        cur = cur->next;
	}
	printf("\n");
}

void insert_node(linked_list * list, int d){
	linked_list new_head = (linked_list) malloc(sizeof(struct node));
	new_head->data = d;
	new_head->next = *list;
	*list = new_head;
}

void delete_node(linked_list *list, int d){
	linked_list cur = *list;
	linked_list prev = (linked_list) malloc(sizeof(struct node));
	
	while(cur != NULL){
		if(cur -> data == d){
			break;
		}
		prev = cur;
		cur = cur->next;
	}

	if(cur == *list){
		(*list) = (*list)->next;
	}else if(cur != NULL){
		prev->next = cur->next;
	}else{
		return;
	}
}
