#include <stdio.h>
#include <process.h>

void insert();
void delet();
void display();

int front, rear;
int q[5];

int main()
{
    int choice;
    char ch;
    front = -1;
    rear = -1;

    do
    {
        printf("\n\t 1. INSERT");
        printf("\n\t 2. DELETE");
        printf("\n\t 3. DISPLAY");
        printf("\n\t 4. EXIT");
        printf("\nEnter your choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delet();
            break;

        case 3:
            display();
            break;
        case 4:
           exit(0);

        default:
            printf("\nBAD CHOICE");
        }
        printf("\ndo you want to continue y/n ");

    } while (ch == 'y' || 'Y');

    return 0;
}
void insert()
{
    int item;
    if (((front == 1) && (rear == 5)) || (front == rear + 1))
    {
        printf("QUEUE IS FULL");
    }
    else
    {
        printf("Enter the element");
        scanf("%d", &item);
        if (front == -1)
        {
            front = 1;
            rear = 1;
        }
        else if (rear == 5)
        {
        }
        else
        {
        }

        rear = 0;

        rear = rear + 1;

        q[rear] = item;
    }
}
void delet()
{
    int item;
    if (front == -1)
    {
        printf("QUEUE IS EMPTY");
    }
    else
    {
        item = q[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == 5)
        {
            front = 0;
        }
        else
            front = front + 1;
        printf("%d is deleted", item);
    }
}
void display()
{
    int i;
    if (front == -1)
        printf("QUEUE IS EMPTY");
    else
    {
        for (i = front; i <= rear; i++)
        {
            printf(" \n%d", q[i]);
        }
    }
}