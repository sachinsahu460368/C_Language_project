#include <stdio.h>

int top = -1, item;
#define N 5
int stack[N];
int isEmpty()
{
    if (top == -1)
    {
        printf("----The Stack is empty ,So no element is Pop ----");
        return 1;
    }
    return 0;
}
int isFull()
{
    if (top == N - 1)
    {
        printf("----The Stack is Full----\n");
        return 1;
    }

    return 0;
}
void push()
{
    if (isFull())
    {
    }
    else
    {
        printf("Enter value stored in stack\n");
        scanf("%d", &item);
        top = top + 1;
        stack[top] = item;
    }
}
int pop()
{
    if (isEmpty())
    {
        return -1;
    }
    else
    {
        int value = stack[top];
        top = top - 1;
        return value;
    }
}
int peek()
{
    return stack[top];
}
int Display()
{
    printf("The Element in the Stack is : \n");
    for (int i = 0; i <= top; i++)
    {
        printf("%d\t", stack[i]);
    }
}
int main()
{
    int choice, d, p;
    char order;
    do

    {
        printf("Enter your choices\n 1 for push \n 2 for pop\n 3 for peek \n 4 for Display \n5 for exit\t");
        scanf("%d", &choice);

        if (choice == 5)
            break;
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            d = pop();
            if (d != -1)
            {
                printf("The value is deleted from Stack is : %d\n", d);
            }
            break;
        case 3:
            p = peek();
            printf("The top element is %d\n", p);
            break;
        case 4:
            Display();
            break;
        default:
            printf("---- Please Enter correct chooice---- \n");
            break;
        }
        printf("\nWant to perform more operation (y or n)");
        scanf(" %c", &order);

    } while (order == 'y' || order == 'Y');
    printf("Program finished.\n");
    return 0;
}
