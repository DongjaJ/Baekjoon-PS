#include <stdio.h>
#include <string.h>
#define queuesize 10000
int front = -1;
int rear=-1;
int size = 0;
int queue[queuesize];

int empty()
{
	if (front==-1||front>rear) return 1; //비어있을때
	else return 0;
}

void push(int n)
{
	if (rear == queuesize - 1)
	{
		printf("queue is full\n");
	}
	else
	{
		if (front == -1) front++;
		queue[++rear] = n;
		size++;
	}
}

void pop()
{
	if (empty()) printf("-1\n");
	else
	{
		printf("%d\n",queue[front++]);
		size--;
	}
}

void SizePrint()
{
	printf("%d\n",size);
}

void frontprint()
{
	if (empty()) printf("-1\n"); //비었을때
	else printf("%d\n", queue[front]);

}

void backprint()
{
	if (empty()) printf("-1\n"); //비었을때
	else printf("%d\n", queue[rear]);

}

int main()
{
	char command[10];
	int commandsize;
	scanf("%d ",&commandsize);
	for (int i=0;i<commandsize;i++)
	{
		scanf("%s",command);
		if (!strcmp(command,"push"))
		{
			int num;
			scanf("%d",&num);
			push(num);
		}
		else if (!strcmp(command, "pop"))
		{
			pop();
		}
		else if (!strcmp(command, "size"))
		{
			SizePrint();
		}
		else if (!strcmp(command, "empty"))
		{
			printf("%d\n",empty());
		}
		else if (!strcmp(command, "front"))
		{
			frontprint();
		}
		else backprint();//back
	}
}