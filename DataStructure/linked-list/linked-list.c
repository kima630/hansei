#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
	int data;
	struct NODE *link;
}NODE;
NODE *p = NULL;
NODE *phead = NULL;

void Insert(NODE *pphead, NODE *pp, int data){
	NODE * InsNode = NULL;
	InsNode = (NODE*)malloc(sizeof(NODE));
	InsNode -> data = data;
	if(pphead == NULL){
		InsNode -> link = NULL;
		phead = InsNode;
	}
	else if(pp == NULL){
		InsNode -> link = phead;
		phead = InsNode;
	}
	else{
		InsNode -> link = p -> link;
		p -> link = InsNode;
	}
}

void Delete(NODE *phead, NODE*p, NODE*removed){
	if(p == NULL){
		phead = phead -> link;
	}
	else
		p -> link = removed -> link;
		free(removed);
}

void Print(NODE *pointer){
	printf("%d ", pointer -> data);
	if(pointer -> link != NULL)
		Print(pointer -> link);
}

NODE* Search(NODE* pointer, int value){
	while(pointer -> link != NULL){
		if(pointer -> data != value){
			pointer = pointer -> link;
		}
		else
			return pointer;
	}
	printf("No search data!!\n");
	return NULL;
}

int main(){
	Insert(phead, p, 10);
	Insert(phead, p, 20);
	Insert(phead, p, 30);
	Insert(phead, p, 40);
	
	p = Search(phead, 20);
	
	Insert(phead, p, 50);
	
	printf("List Start\n");
	Print(phead);
	
	return 0;
}
