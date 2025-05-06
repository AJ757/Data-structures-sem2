//menu driven code to check if a number is palindrome, armstrong or perfect using DMA

#include <stdio.h>
#include "stdlib.h"
#include <math.h>

int palindrome(int *);
int armstrong(int *);
int perfect(int *);
int length(int *,int *);
int reverse(int *,int *);
int pow(int,int*,int*);

int main()
{
    int * ch=(int*)malloc(sizeof(int));
    if(ch==NULL) 
    {
        printf("Memory Allocation Failure\n");
        return -1;
    }
    int * num=(int*)malloc(sizeof(int));
    if(num==NULL) 
    {
        printf("Memory Allocation Failure\n");
        free(ch);
        return -1;
    }
    int * res=(int*)malloc(sizeof(int));
    if(res==NULL) 
    {
        printf("Memory Allocation Failure\n");
        free(ch);
        free(num);
        return -1;
    }
    do
    {
        printf("\tMENU\n1.Palindrome\n2.Armstrong\n3.Perfect\n4.Exit\n");
        printf("Enter choice:");
        scanf("%d",ch);
        switch(*ch)
        {
            case 1:
                printf("Enter number:");
                scanf("%d",num);
                *res=palindrome(num);
                switch(*res)
                {
                    case -1:
                        printf("Memory Allocation Failure\n");
                        free(ch);
                        free(num);
                        return -1;
                    case 0:
                        printf("%d is not a palindrome number\n",*num);
                        break;
                    case 1:
                        printf("%d is a palindrome number\n",*num);
                        break;
                }
                break;
            case 2:
                printf("Enter number:");
                scanf("%d",num);
                *res=armstrong(num);
                switch(*res)
                {
                    case -1:
                        printf("Memory Allocation Failure\n");
                        free(ch);
                        free(num);
                        return -1;
                    case 0:
                        printf("%d is not an armstrong number\n",*num);
                        break;
                    case 1:
                        printf("%d is an armstrong number\n",*num);
                        break;
                }
                break;
            case 3:
                printf("Enter number:");
                scanf("%d",num);
                *res=perfect(num);
                switch(*res)
                {
                    case -1:
                        printf("Memory Allocation Failure\n");
                        free(ch);
                        free(num);
                        return -1;
                    case 0:
                        printf("%d is not a perfect number\n",*num);
                        break;
                    case 1:
                        printf("%d is a perfect number\n",*num);
                        break;
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid input. Enter again.\n");
        }
    }while(*ch!=4);
    free(ch);
    free(num);
    free(res);
    return 0;
}

//checks if a number is palindrome; returns 1 if yes, 0 if not, -1 for memory allocation failure
int palindrome(int* num)
{
    int * temp=(int*)malloc(sizeof(int));
    if(temp==NULL) return -1;
    if(reverse(num,temp)!=-1)
    {
        if (*temp==*num)
        {
            free(temp);
            return 1;
        }
    }
    else return -1;
    free(temp);
    return 0;
}

//reverses a number using pointer argument to store value, returns 0 for success, -1 for failure
int reverse(int* num,int * rev)
{
    int * temp=(int*)malloc(sizeof(int));
    if(temp==NULL) return -1;
    *temp=*num;
    *rev=0;
    while(*temp)
    {
        (*rev)=10*(*rev)+(*temp)%10;
        (*temp)/=10;
    }
    free(temp);
    return 0;
}

//calculates number of digits of num and makes count pointer store value, retrurns 0 for success, -1 for failure
int length(int* num,int * count)
{
    int * temp=(int*)malloc(sizeof(int));
    if(temp==NULL) return -1;
    *temp=*num;
    *count=0;
    while(*temp)
    {
        (*count)++;
        (*temp)/=10;
    }
    free(temp);
    return 0;
}

//checks if a number is armstrong; returns 1 if yes, 0 if not, -1 for memory allocation error
int armstrong(int *num)
{
    int * count=(int*)malloc(sizeof(int));
    if(count==NULL) return -1;
    if(length(num,count)!=-1)
    {
        int * temp=(int*)malloc(sizeof(int));
        if(temp==NULL)
        {
            free(count);
            return -1;
        }
        *temp=*num;
        int * arm=(int*)malloc(sizeof(int));
        if(arm==NULL)
        {
            free(count);
            free(temp);
            return -1;
        }
        *arm=0;
        int * power=(int*)malloc(sizeof(int));
        if(power==NULL)
        {
            free(count);
            free(temp);
            free(arm);
            return -1;
        }
        while(*temp)
        {
            if(pow((*temp)%10,count,power)!=-1)
            {
                *arm+=*power;
                *temp/=10;
            }
            else 
            {
                free(count);
                free(temp);
                free(arm);
                free(power);
                return -1;
            }    
        }
        if (*arm==*num)
        {
            free(count);
            free(temp);
            free(arm);
            free(power);
            return 1;
        }
        free(temp);
        free(arm);
        free(power);
    }
    
    free(count);
    return 0;
}

//calculates num1 power num2 and stores in pointer pow, returns 0 for success,-1 for failure
int pow(int num1,int *num2,int* pow)
{
    *pow=1;
    int * i=(int*)malloc(sizeof(int));
    if(i==NULL) return -1;
    *i=0;
    while(*i<(*num2))
    {
        (*pow)*=(num1);
        (*i)++;
    }
    return 0;
}

//checks if a number is perfect; returns 1 if yes, 0 if not, -1 for memory allocation error
int perfect(int* num)
{
    int * perf=(int*)malloc(sizeof(int));\
    if(perf==NULL) return -1;
    *perf=1;
    int * i=(int*)malloc(sizeof(int));
    if(i==NULL)
    {
        free(perf);
        return -1;
    }
    *i=2;
    for (;*i<sqrt(*num);(*i)++)
    {
        if ((*num)%(*i)==0)
        {
            (*perf)+=(*i);
        }
    }
    if(*perf==*num)
    {
        free(perf);
        free(i);
        return 1;
    }
    free(perf);
    free(i);
    return 0;
}