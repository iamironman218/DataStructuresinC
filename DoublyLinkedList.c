#include<stdio.h>
#include<math.h>

struct node
{
    int info;
    struct node* next;
    struct node* prev;
};

struct node *createList(struct node *start);
struct node *insertionInBeginning(struct node *start,int data);
void insertAtEnd(struct node *start,int data);
void displayList(struct node *start);

int main()
{
    int data;
    struct node *start;
    start = NULL;

    start = createList(start);
    displayList(start);
    return 0;
}

struct node *createList(struct node *start)
{
    int n ,data;
    printf("Enter the numbers of node : ");
    scanf("%d",&n);

    if (n == 0)
        return start;

    printf("Enter the first element to be inserted : ");
    scanf("%d",&data);
    start = insertionInBeginning(start,data);

    for (int i = 2;i <= n;i++)
    {
        printf("Enter the next element to be inserted : ");
        scanf("%d",&data);
        insertAtEnd(start,data);
    }
    return start;
}

struct node *insertionInBeginning(struct node *start,int data)
{
    struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node));
        temp -> info = data;
    if(start == NULL)
    {
        temp -> prev = NULL;
        temp -> next = NULL;
        start = temp;
    }
    /*else
    {
        temp -> next = start -> next;
        start -> prev = temp;
        temp -> prev = NULL;
        start = temp;
    }*/
    return start;
}

void insertAtEnd(struct node *start,int data)
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp -> info = data;

    p = start;
    while (p -> next != NULL)
    {
        p = p -> next;
    }
    temp -> next = NULL;
    p -> next = temp;
    temp -> prev = p;


}
void displayList(struct node *start)
{
    struct node *p;
    p = start;
    while (p != NULL)
    {
        printf(" %d ",p -> info);
        p = p -> next;
    }
}



