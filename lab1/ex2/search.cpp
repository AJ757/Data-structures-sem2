//menu driven program to implement linear and binary search using header files for sorting
#include<stdio.h>
#include "sort.h"

int linear(int *,int ,int );
int binary(int *,int,int);
void create(int * ,int );
void display(int *,int );
void menu_search(int (*)(int *,int,int));

int main()
{
    int ch;
    do
    {
        printf("\tMENU\n1.Linear search\n2.Binary search\n3.Exit\n");
        printf("Enter choice:");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
            {
                menu_search(linear);
                break;
            }
            case 2:
            {
                menu_search(binary);
                break;
            }
            case 3:
            {
                printf("Exiting...\n");
                break;
            }
            default:
            {
                printf("Invalid input,try again.\n");
            }
        }
    }while(ch!=3);
    return 0;
}
//performs linear search on given array and element
int linear(int *arr,int len,int elt)
{
    for (int i=0;i<len;i++)
    {
        if (elt==arr[i]) return i;
    }
    return -1;
}
//performs binary search on given array and element
int binary(int * arr, int len,int elt)
{
    int beg=0,end=len-1,mid;
    while(beg<end)
    {
        mid=(beg+end)/2;
        if(arr[mid]==elt)
        {
            return mid;
        }
        if(arr[mid]<elt)
        {
            beg=mid+1;
        }
        if(arr[mid]>elt)
        {
            end=mid-1;
        }
    }
    return -1;
}
//takes inputs for elements of array
void create(int * arr,int len)
{
    for (int i=0;i<len;i++)
    {
        printf("Enter element:");
        scanf("%d",&arr[i]);
    }
}
//to display the array
void display(int *arr,int len)
{
    for (int i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
//takes one of the search fns as parameterand performes each case for menu
void menu_search(int (*s)(int *,int,int))
{
    int len;
    printf("Enter number of elements:");
    scanf("%d",&len);
    if(len>0)
    {
        int arr[len];
        create(arr,len);
        if (s==binary)
        {
            bubble_sort(arr,len);
        }
        printf("Array:");
        display(arr,len);
        int elt;
        printf("Enter number to search:");
        scanf("%d",&elt);
        int pos=s(arr,len,elt);
        if (pos==-1) printf("Not found.\n");
        else printf("Fount at index %d\n",pos);
    }
    else
    printf("Length is less than 1. Try again.\n");
}