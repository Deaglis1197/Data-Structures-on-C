#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#define QUEUESIZE 5

typedef struct{
	char bookdata[QUEUESIZE][100];
	int front;
	int rear;
	int cnt;
}queue;
void initialize(queue *q) {
	q->cnt = 0;
	q->front= 0;
    q->rear = -1;
}
int isEmpty(queue *q) {
	if (q->cnt == 0) {
		return 1;
	}
	else
	{
		return 0;
	}
}
int isFull(queue *q) {
	if (q->cnt == QUEUESIZE)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void enqueue(queue *q) {
	if (isFull(q)) {
		printf("List is full!");
	}
	else
	{
		
		char x[100];
		char key[30];
		q->rear++;
		if (q->rear == QUEUESIZE) {
			q->rear = 0;
		}
		printf("Enter book IBSN:");
		gets(x);
		strcat(x, "-");
		printf("Book Name:");
		gets(key);
		strcat(x, key);
		strcat(x, "-");
		printf("Enter book author:");
		gets(key);
		strcat(x, key);
		strcat(x, "-");
		printf("Enter book edition year:");
		gets(key);
		strcat(x, key);
		for (int i=0; i<100; i++)
		{
			q->bookdata[q->rear][i] = x[i];
		}
		q->cnt++;
	}

	
}

int Dequeue(queue *q){
	if (isEmpty(q)) {
		printf("List is empty!");
	}
	else
	{
		printf("Book ISBN:");
		for (int i = 0; q->bookdata[q->front][i] != '-'; i++) {
			printf("%c", q->bookdata[q->front][i]);
		}
		printf("\n");
		printf("Book Name:");
		for (int i = 0; q->bookdata[q->front][i] != '-'; i++) {
			printf("%c", q->bookdata[q->front][i]);
		}
		printf("\n");
		printf("Book Author:");
		for (int i = 0; q->bookdata[q->front][i] != '-'; i++) {
			printf("%c", q->bookdata[q->front][i]);
		}
		printf("\n");
		printf("Book Edition Year:");
		for (int i = 0; q->bookdata[q->front][i] != '-'; i++) {
			printf("%c", q->bookdata[q->front][i]);
		}
		printf("\n");
		
		q->front++;
		if (q->front == QUEUESIZE)
		{
			q->front=0;
		}
		q->cnt--;

	}


}
void printfull(queue *q) {
	if (isEmpty(q))
	{
		return;
	}
	for (int i = q->front; i != q->rear+1; i++)
	{
		printf("%d - Book:\n",i+1);
		if (i == QUEUESIZE)
		{
			i = 0;
		}

		printf("Book ISBN:");
		for (int j = 0; q->bookdata[i][j] != '-'; j++) {
			printf("%c", q->bookdata[i][j]);
		}
		printf("\n");
		printf("Book Name:");
		for (int j = 0; q->bookdata[i][j] != '-'; j++) {
			printf("%c", q->bookdata[i][j]);
		}
		printf("\n");
		printf("Book Author:");
		for (int j = 0; q->bookdata[i][j] != '-'; j++) {
			printf("%c", q->bookdata[i][j]);
		}
		printf("\n");
		printf("Book Edition Year:");
		for (int j = 0; q->bookdata[i][j] != '-'; j++) {
			printf("%c", q->bookdata[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	char empty[10];
	queue q;
	initialize(&q);
	int case1, case2 = 1;
	while (case2 != 0)
	{
		printf("\n***************MENU**************\n");
		printf("1)Add new book in Queue              \n");
		printf("2)Delete and read first book         \n");
		printf("3)Print all list                     \n");
		printf("4)Exit\n");
		scanf("%d", &case1);
	switch(case1){
		case 1:
			gets(empty);
			system("CLS");
			enqueue(&q);
			getch();
			system("CLS");
			break;
		case 2:
			gets(empty);
			system("CLS");
			Dequeue(&q);
			
			printf("\nPress enter to menu.");
			getch();
	
			system("CLS");
			break;
		case 4:
			case2 = 0;
			break;
		case 3:
			system("CLS");
		    printfull(&q);
		    getch();
		    gets(empty);
			system("CLS");
		break;
		default:
			system("CLS");
			case1 = 0;
			printf("Wrong key!\nPress Enter.");
			getch();
			system("CLS");
			break;
	}
    }
	

}
