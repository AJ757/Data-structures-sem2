//menu driven program to sort array using bubble,selection and insertion sorts
#include<stdio.h>

void bubble_sort(int *,int);
void select_sort(int*,int);
void insert_sort(int *,int);
void create(int *,int);
void display(int *,int);
void menu_sort(void (*)(int *,int));

int main()
{
    int ch;
    do{
    printf("\tMENU\n1.Bubble sort\n2.Selection sort\n3.Insertion sort\n4.Exit\n");
    printf("Enter choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            menu_sort(bubble_sort);
            break;
        case 2:
            menu_sort(select_sort);
            break;
        case 3:
            menu_sort(insert_sort);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid input, try again.\n");
    }
    }while(ch!=4);
    return 0;
}
//bubble sort
void bubble_sort(int * arr,int len)
{
    for (int i=0;i<len;i++)
    {
        for (int j=0;j<len-i-1;j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
//selection sort
void select_sort(int *arr,int len)
{
    for(int i=0;i<len-1;i++)
    {
        //to find i th smallest number in arr
        int min=i;
        for(int j=i;j<len;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}
//insertion sort
void insert_sort(int * arr,int len)
{
    for(int i=0;i<len;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>=key)
        {
            
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            j--;
        }
    }
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
//takes sort fns as parameter and performes each case for menu
void menu_sort(void (*s)(int *,int))
{
    int len;
    printf("Enter number of elements:");
    scanf("%d",&len);
    if(len>0)
    {
        int arr[len];
        create(arr,len);
        printf("Before sort:");
        display(arr,len);
        s(arr,len);
        printf("After sort:");
        display(arr,len);
    }
    else
    printf("Length is less than 1. Try again.\n");
}