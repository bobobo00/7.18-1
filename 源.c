#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct Stack{
	int data[MAX];
	int size;
}stack,*stack_s;


void Init_Stack(stack_s s){
	s->size = -1;
}

void Push_s1(stack_s s1, int node){
	if (s1->size == MAX - 1){
		printf("队已满");
		return;
	}
	s1->data[++s1->size] = node;
}
int Pop_s1(stack_s s1){
	if (s1->size == -1){
		printf("队空");
		return;
	}
	return s1->data[s1->size--];
}

void Push_s2(stack_s s2, int node){
	if (s2->size == MAX - 1){
		printf("队已满");
		return;
	}
	s2->data[++s2->size] = node;
}
int Pop_s2(stack_s s2){
	if (s2->size == -1){
		printf("队空");
		return;
	}
	return s2->data[s2->size--];
}
void push(stack_s s1, stack_s s2,int node){
	int i = 0;
	if (s1->size == MAX - 1 && s2->size == MAX - 1){
		printf("队已满");
	}
	if (s1->size == MAX - 1){
		for (i = MAX-1; i>=0; i--){
			Push_s2(s2, s1->data[i]);
			s1->size--;
		}
	}
	Push_s1(s1, node);
}
int pop(stack_s s1, stack_s s2){
	int i = 0;
	if (s2->size == -1 && s2->size == -1){
		printf("队空");
		return;
	}
	if (s2->size == -1){
		for (i = s1->size; i >= 0; i--){
			Push_s2(s2, s1->data[i]);
		}
	}
	return Pop_s2(s2);
}
int main(){
	stack s1;
	stack s2;
	Init_Stack(&s1);
	Init_Stack(&s2);
	push(&s1, &s2, 1);
	push(&s1, &s2, 2);
	push(&s1, &s2, 3);
	push(&s1, &s2, 4);
	push(&s1, &s2, 5);
	push(&s1, &s2, 6);
	push(&s1, &s2, 6);
	push(&s1, &s2, 6);
	push(&s1, &s2, 6);
	push(&s1, &s2, 6); 
	push(&s1, &s2, 6);
	printf("%d",pop(&s1, &s2));

	system("pause");
	return 0;
}