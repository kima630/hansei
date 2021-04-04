#include <stdio.h>

#include <stdlib.h>

#include <stdbool.h>

#define MAX 10

 

struct NODE{

	int data;

	struct NODE *link;

};

struct NODE *top = NULL;

int sp = 0;

int PUSH(int value){

	if(sp >= MAX){

		printf("오버플로\n"); 

		return true;

	}

	struct NODE*NewNode=malloc(sizeof(struct NODE));

	

	NewNode -> data = value;

	NewNode -> link = top;

	top = NewNode;

	sp++;

	printf("PUSH(%d)\n", top -> data);

	return false;

}

 

bool POP(){

	struct NODE *DelNode = top;

	if(sp == 0){

		printf("언더플로\n");

		return true;

	}

	printf("POP() => %d\n", top -> data);

	top = top -> link;

	free(DelNode);

	sp--;

	return false;

}

 

int main(){

	int i;

	for(i = 1; i < 5; i++)

		PUSH(i*10);

	for(i = 1; i < 5; i++)

		POP();

	return 0;

}
