/*

Program to implement following functions, working with sorted lists:
1.Insert element into list 1
2.Insert element into list 2
3.Merge lists 1 and 2 into list 3
4.Display all lists
5.Exit

*/


#include <stdio.h>
#include "sll_2.hpp"

int input_num();
int input_list(int n,class sll *);
void display(class sll,class sll,class sll);
int main()
{
    sll l1,l2,l3;
    int ch;
    do
    {
        printf("\n\tMENU\n1.Insert List 1 \n2.Insert List 2\n3.Merge into List 3\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                if (input_list(input_num(),&l1)==0)
                {
                    printf("Memory allocation failed.\n");
                }
                break;
            }
            case 2:
            {
                if (input_list(input_num(),&l2)==0)
                {
                    printf("Memory allocation failed.\n");
                }
                break;
            }
            case 3:
            {
                if (l3.merge(l1,l2)==0)
                {
                    printf("Memory allocation failed.\n");
                }
                break;
            }
            case 4:
            {
                display(l1,l2,l3);
                break;
            }
            case 5:
            {
                printf("\nExiting...\n");
                break;
            }
            default:
            {
                printf("Invalid input.\n");
            }
        }
    } while (ch!=5);
    l1.free_list();
    l2.free_list();
    l3.free_list();
    return 0;
}

//Takes input from user for number of elements in list
//returns 0 if invalid, number of elements otherwise
int input_num()
{
    printf("Enter number of elements: ");
    int num;
    scanf("%d",&num);
    if (num<0)
    {
        printf("Invalid input.\n");
        return 0;
    }
    return num;
}

//Inserts n elements from user into list
//Input:    n - int - number of elements
//          l - class sll * - pointer to list
//returns 0 if memory allocation fails, 1 otherwise
int input_list(int n,class sll * l)
{
    int num,flg=1;
    l->free_list();//clear previous memory
    for (int i=0;i<n&&flg==1;i++)
    {
        printf("Enter element: ");
        scanf("%d",&num);
        flg=(*l).insert_asc(num);
    }
    return flg;
}

//Displays all 3 lists
void display(class sll l1,class sll l2, class sll l3)
{
    printf("\nList 1:");
    l1.display();
    printf("\nList 2:");
    l2.display();
    printf("\nList 3:");
    l3.display();
}