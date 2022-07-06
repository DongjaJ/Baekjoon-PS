#include <stdio.h>
#include <string.h>
#define stacksize 10000
int top = -1;
int size = 0;
int stack[stacksize];

int empty()
{
	if (top == -1) return 1; //비어있을때
	else return 0;
}

void push(int n)
{
	if (top == stacksize - 1)
	{
		printf("stack is full\n");
	}
	else
	{
		stack[++top] = n;
		size++;
	}
}

void pop()
{
	if (empty()) printf("%d\n",top);
	else
	{
		printf("%d\n",stack[top--]);
		size--;
	}

}

void SizePrint()
{
	printf("%d\n",size);
}



void topprint()
{
	if (empty()) printf("%d\n", top); //비었을때
	else printf("%d\n", stack[top]);

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
		else topprint();//top
	}
}