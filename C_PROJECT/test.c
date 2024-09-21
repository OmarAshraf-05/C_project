#include <stdio.h>
#include <stdlib.h>

#define NULL_POINTER ((void*)0)

typedef struct node_t node;
struct node_t
{
	char name[50];
	int id;
	node* tail;
};

node* creat_node(int arg_data, char *arg_name);
void add_node(node** head,int arg_data, char *arg_name);
void delete_node(node** head);
void print_list(node* head);
void edit_node(node* head, int arg_oldID, int arg_newID, char* arg_name);

int main(void)
{
	node* head=NULL_POINTER;
	int choice =-1;
	int id, new_id;
	char name[50];
	while(1)
	{
		printf("\n\nto add new employee  data enter no:1\n");
		printf("to delete  employee  data enter no:2\n");
		printf("to print   employees data enter no:3\n");
		printf("to edit    employee  data enter no:4\n");
		printf("to exsit program:0\n");
		printf("enter you choice: ");
		scanf("%d",&choice);
		fflush(stdin);fflush(stdout);
		
		if(choice==0)
		{
			break;
		}
		else if(choice==1)
		{
			printf("\nenter employee name: ");
			scanf("%[^\n]%*c",&name);
			fflush(stdin);fflush(stdout);
			printf("\nenter employee id: ");
			scanf("%d",&id);
			fflush(stdin);fflush(stdout);
			add_node(&head, id, name);
		}
		else if(choice==2)
		{
			delete_node(&head);
		}
		else if(choice==3)
		{
			print_list(head);
		}
		else if(choice==4)
		{
			printf("\nenter the id of the employee: ");
			scanf("%d",&id);
			fflush(stdin);fflush(stdout);
			printf("\nenter the new id of the employee: ");
			scanf("%d",&new_id);
			fflush(stdin);fflush(stdout);
			printf("\nenter employee new name: ");
			scanf("%[^\n]%*c",&name);
			fflush(stdin);fflush(stdout);
			edit_node(head, id, new_id, name);
		}
		else
		{
			printf("\n\nnot correct choice\n\n");
			
		}
	}
	return 0;
}


node* creat_node(int arg_data, char *arg_name)
{
	int i=0;
	node* newnode = (node*)malloc(sizeof(node));
	while(arg_name[i] != '\0')
	{
		newnode -> name[i] = *(arg_name+i);
		i++;
	}
	newnode -> id 	= arg_data;
	newnode -> tail = NULL_POINTER;
	return newnode;
}


void add_node(node** head,int arg_data, char *arg_name)
{
	 node* newnode = creat_node(arg_data, arg_name);
	if(NULL_POINTER==*head)
	{
		*head = newnode;
	}
	else
	{
		node* ptr = *head;
		while(ptr -> tail != NULL_POINTER)
		{
			ptr = ptr -> tail; 
		}
	    ptr -> tail = newnode;
	}
	printf("\n\nemployee data added successfully\n\n\n");
}


void delete_node(node** head)
{
	if(NULL_POINTER == *head)
	{
		printf("\n\ncannot delete . list is empty\n\n\n");
	}
	else if(NULL_POINTER == (*head) -> tail)
	{
		free(*head);
		*head = NULL_POINTER;
		printf("\n\ndata deletded successfully. now list is empty\n\n\n");
	}
	else
	{
		node* ptr = *head;
		while(ptr -> tail -> tail != NULL_POINTER)
		{
			ptr = ptr -> tail;
		}
		free(ptr -> tail);
		ptr -> tail = NULL_POINTER;
		printf("\n\ndata deleted successfully\n\n\n");
	}
}


void print_list(node* head)
{
	if(NULL_POINTER == head)
	{
		printf("\n\ncannot print. list is empty\n\n\n");
	}
	else
	{
		int i = 1;
		while(head != NULL_POINTER)
		{
			printf("\nemployee number %d is: %s\n", i, head -> name);
			printf("his id: %d\n", head -> id);
			head = head -> tail;
			i++;
		}
		printf("\n\n");
	}
}

void edit_node(node* head, int arg_oldID, int arg_newID, char* arg_name)
{
	int i=0;
	node* ptr = head;
	if(arg_oldID == head -> id)
	{
		head -> id =0;
		head -> id = arg_newID;
		
		while(arg_name[i] != '\0')
		{
			head -> name[i] = *(arg_name+i);
			i++;
		}
	}
	else
	{
		while(arg_oldID != ptr -> tail -> id)
		{
			ptr = ptr -> tail;
		}
		ptr -> tail -> id = 0;
		ptr -> tail -> id = arg_newID;
		
		while(arg_name[i] != '\0')
		{
			ptr -> tail -> name[i] = *(arg_name+i);
			i++;
		}
	}		
}
