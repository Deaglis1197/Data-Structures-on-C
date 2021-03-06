#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

struct node {
	int data;
	struct node *next;
};

int listcounter(struct node *head)
{
	struct node *temp=head;
	int i;
	for (i = 1; temp->next!= head; i++)
		temp = temp->next;
	return i;

}
struct node *deletegivenvalue(struct node *head, int key)
{
	if (head == NULL)
	{
		printf("List is empty!\n");
		return NULL;
	}
	if (head->data == key)
	{
		struct node *temp = head;
		while (temp->next != head)
			temp = temp->next;
		temp->next = head->next;
		temp=head;
		head = head->next;
		free(temp);
		return head;
	}
	struct node *headTemp = (struct node *)malloc(sizeof(struct node));
	headTemp = head;
	while (head->next != headTemp)
	{
		if (head->next->data == key)
		{
			struct node *temp = (struct node *)malloc(sizeof(struct node));
			temp = head->next;
			head->next = temp->next;
			free(temp);
			return headTemp;
		}
		head = head->next;
	}

	if (head->next == headTemp)
	{
		printf("Search not found!\n");
		return headTemp;

	}

}
void insertfrontsearch(struct node *head, int key)
{
	int key2;
	if (head == NULL)
	{
		printf("List is empty!\n");
		return;
	}
	struct node *thead = head;
	if (head->data == key)
	{
		printf("Search found, Enter data:");
		scanf("%d", &key2);
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp->data = key2;
		temp->next = head->next;
		head->next = temp;
		return;
	}
	head = head->next;
	while (head != thead)
	{
		if (head->data == key)
		{
			printf("Search found, Enter data:");
			scanf("%d", &key2);
			struct node *temp = (struct node *)malloc(sizeof(struct node));
			temp->data = key2;
			temp->next = head->next;
			head->next = temp;
			return;
		}
		head = head->next;
	}
	if (head == thead)
	{
		printf("Search not found!\n");
	}
}
struct node *insertlast(struct node *head, int key)
{
	if (head == NULL)
	{
		struct node *head = (struct node *)malloc(sizeof(struct node));
		head->data = key;
		head->next = head;
		return head;
	}
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->next = head;
	struct node *temp2 = head;
	while (temp2->next != head)
	{
		temp2 = temp2->next;
	}
	temp2->next = temp;
	return head;
}
struct node *createlist(struct node *head)
{
	if (head != NULL)
	{
		int case1 = 1;
		printf("List has been created before!\nDo you want combine new list with created list?(enter 1 for accept)");
		scanf("%d", &case1);
		if (case1 != 1)
		{
			return head;
		}
	}
	int i, key;
	int i2 = 1;
	printf("Do you want how many node create ? ");
	scanf("%d", &i);
	for (; i != 0; i--)
	{
		printf("%d. list data:", i2);
		scanf("%d", &key);
		head = insertlast(head, key);
		i2++;
	}
	return head;

}
struct node *deletealllist(struct node *head, struct node *thead)
{
	if(head==NULL)
	{
		return NULL;
	}
	if (head->next == thead)
	{
		free(head);
		return NULL;
	}
	deletealllist(head->next,thead);
	free(head);
	return NULL;


}
struct node *inserthead(struct node *head, int key)
{
	if (head == NULL)
	{
		struct node *head = (struct node *)malloc(sizeof(struct node));
		head->data = key;
		head->next = head;
		return head;
	}
	struct node *temph = head;
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->next = head;
	while (head->next !=temph)
	{
		head = head->next;
	}
	head->next = temp;

	return temp;
}
struct node *exchange(struct node *head)
{
	struct node *temp = head;
	while (temp->next->next != head)
	{
		temp = temp->next;
	}
	temp->next->next = head->next;
	head->next = temp->next;
	temp->next = head;
	return  head->next;
}
void printlist(struct node *head)
{
	struct node *temp = head;
	if (head == NULL)
	{
		printf("There is no List !\n");
		return;
	}
	
	while (temp->next != head)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("%d ", temp->data);
	temp = temp->next;
	printf("\n");

}
void searchdata(struct node *head, int key)
{
	int i = 1,case1=0;
	if (head == NULL)
	{
		printf("list not found!\n");
		return;
	}
	struct node *thead = head;
	if (head->data == key)
	{
		case1 = 1;
		printf("Data found in %d. node\n", i);
	}
	head = head->next;
	for (i=2; head != thead; i++)
	{
		if (head->data == key)
		{
			case1 = 1;
			printf("Data found in %d. node\n", i);
		}
		head = head->next;

	}
	if (case1 = 1)
		printf("Search not found!\n");

}
struct node *reserving(struct node *head)
{
	if (head == NULL)
	{
		printf("List is empty !");
		return head;
	}
	struct node *headtemp;
	struct node *temp = head;
	while (temp->next != head)
	{
		temp = temp->next;
	}
	head = head->next;
	struct node *temp2 = temp->next;
	while (head != temp)
	{
		headtemp = head;
		head = head->next;
		headtemp->next = temp->next;
		temp->next = headtemp;

	}

	temp2->next = head;
	return head;
}
int main()
{
	struct node *head = NULL;
	int case1, case2 = 1, key;
	while (case2 != 0)
	{
		printf("\n***************MENU**************\n");
		printf("1)Insert a node for head             \n");
		printf("2)Insert a node for last             \n");
		printf("3)Create list                        \n");
		printf("4)Deleting a given value             \n");
		printf("5)Add front Searching data           \n");
		printf("6)Count list                         \n");
		printf("7)Print list                         \n");
		printf("8)Searching the Lists                \n");
		printf("9)Delete ALL List                    \n");
		printf("10)Reserving List                    \n");
		printf("11)Exchange last and first node      \n");
		printf("12)Exit                              \n");
		scanf("%d", &case1);


		switch (case1)
		{
		case 1:
			system("CLS");
			printf("Enter node data:");
			scanf("%d", &key);
			head = inserthead(head, key);
			system("CLS");
			printf("Press Enter.");
			getch();
			system("CLS");
			break;
		case 2:
			system("CLS");
			printf("Enter node data:");
			scanf("%d", &key);
			head = insertlast(head, key);
			system("CLS");
			printf("Press Enter.");
			getch();
			system("CLS");
			break;
		case 3:
			system("CLS");
			head = createlist(head);
			printf("Press Enter.");
			getch();
			system("CLS");
			break;
		case 4:
			system("CLS");
			printf("Enter node data:");
			scanf("%d", &key);
			head = deletegivenvalue(head, key);
			printf("Press Enter.");
			getch();
			system("CLS");
			break;
		case 5:
			system("CLS");
			printf("Enter Searching data:");
			scanf("%d", &key);
			insertfrontsearch(head, key);
			printf("Press Enter.");
			getch();
			system("CLS");
			break;

		case 6:
			system("CLS");
			int i = listcounter(head);
			printf("Created list number:%d\n", i);
			printf("Press Enter.");
			getch();
			system("CLS");
			break;
		case 7:
			system("CLS");
			printlist(head);
			printf("Press Enter.");
			getch();
			system("CLS");
			break;
		case 8:
			system("CLS");
			printf("Enter Searching data:");
			scanf("%d", &key);
			searchdata(head, key);
			printf("Press Enter.");
			getch();
			system("CLS");
			break;
		case 9:
			head = deletealllist(head,head);
			system("CLS");
			printf("Press Enter.");
			getch();
			system("CLS");
			break;
		case 10:
			head = reserving(head);
			system("CLS");
			printf("Press Enter.");
			getch();
			system("CLS");
			break;
		case 11:
			head = exchange(head);
			system("CLS");
			printf("Press Enter.");
			getch();
			system("CLS");
			break;
		case 12:
			head = deletealllist(head,head);
			free(head);
			case2 = 0;
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
	return 0;
}
