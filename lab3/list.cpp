//list ADT using array implementation
#include <stdio.h>
#define SIZE 5
class list
{
    private:
        int arr[SIZE];
        int current;
    public:
        list()
        {
            current=-1;
        }
        int insertbeg(int);
        int insertend(int);
        int insertpos(int,int);
        int delbeg();
        int delend();
        int delpos(int);
        int search(int);
        int rotate1(int);
        int rotate2(int);
        int rotate3(int);
        void display();
};
void reverse(int*,int,int);

int main()
{
    list l1;
    int ch;
    do
    {
        printf("\tMENU\n1.Insert at beginning\n2.Insert at end\n3.Insert at position\n");
        printf("4.Delete at beginning\n5.Delete at end\n6.Delete at position\n");
        printf("7.Search\n8.Rotate\n9.Display\n10.Exit\n");
        printf("Enter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                int num;
                printf("Enter number (except 0 and -1) to insert:");
                scanf("%d",&num);
                if (num==0||num==-1)
                {
                    printf("Invalid input for element.\n\n");
                    break;
                }
                if(l1.insertbeg(num)==1) l1.display();
                else printf("List is full.\n\n");
                break;
            }
            
                
            case 2:
            {
                int num;
                printf("Enter number (except 0 and -1) to insert:");
                scanf("%d",&num);
                if (num==0||num==-1)
                {
                    printf("Invalid input for element.\n\n");
                    break;
                }
                if(l1.insertend(num)) l1.display();
                else printf("List is full.\n\n");
                break;
            }
            case 3:
            {
                int num,pos;
                printf("Enter number (except 0 and -1) to insert:");
                scanf("%d",&num);
                if (num==0||num==-1)
                {
                    printf("Invalid input for element.\n\n");
                    break;
                }
                printf("Enter position to insert:");
                scanf("%d",&pos);
                int res=l1.insertpos(num,pos);
                if(res==1) l1.display();
                else if (res==0) printf("List is full.\n\n");
                else printf("Invalid position.\n\n");
                break;
            }
            case 4:
            {
                int res=l1.delbeg();
                if(res!=0) 
                {
                    printf("Deleted element is %d\n\n",res);
                    l1.display();
                }
                else printf("List is already empty.\n\n");
                break;
            }
            
                
            case 5:
            {
                int res=l1.delend();
                if(res!=0) 
                {
                    printf("Deleted element is %d\n\n",res);
                    l1.display();
                }
                else printf("List is already empty.\n\n");
                break;
            }
            case 6:
            {
                int pos;
                printf("Enter position to delete:");
                scanf("%d",&pos);
                int res=l1.delpos(pos);
                if(res!=0&&res!=-1) 
                {
                    printf("Deleted element is %d\n\n",res);
                    l1.display();
                }
                else if(res==0)printf("List is already empty.\n\n");
                else printf("Invalid position.\n\n");
                break;
            }
            case 7:
            {
                int num;
                printf("Enter number to search:");
                scanf("%d",&num);
                int res=l1.search(num);
                if(res==-1)printf("Not found.\n\n");
                else printf("%d fount at index %d\n\n",num,res);
                break;
            }
            case 8:
            {
                int num;
                printf("Enter how many rotations towards right:");
                scanf("%d",&num);
                if (num<0) printf("Invalid input for rotations.\n");
                else 
                {
                    printf("\nBefore rotation: ");
                    l1.display();
                    printf("After rotation: ");
                    l1.rotate3(num);
                    l1.display();
                }
                break;
            }
            case 9:
            {
                l1.display();
                break;
            }
            case 10:
            {
                printf("Exiting...\n\n");
                break;
            }
            default:
            {
                printf("Invalid input.\n\n");
            }
        }
    }while(ch!=10);
    return 0;
}

//reverses list for indices n to m
void reverse(int * arr,int n,int m)
{
    while (n < m) {
        int temp = arr[n];
        arr[n] = arr[m];
        arr[m] = temp;
        n++;
        m--;
    }
}

//inserts element at beginning of list; returns 1 for success, 0 for failure
int list::insertbeg(int num)
{
    if (current==SIZE-1)
    {
        return 0;
    }
    for (int i=current;i>=0;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[0]=num;
    current++;
    return 1;
}

//inserts element at the end of list; returns 1 for success, 0 for failure
int list::insertend(int num)
{
    if (current==SIZE-1)
    {
        return 0;
    }
    arr[current+1]=num;
    current++;
    return 1;
}

//inserts element at position; returns 1 for success, 0 if list is full, -1 if invalid pos
int list::insertpos(int num,int pos)
{
    if (current==SIZE-1)
    {
        return 0;
    }
    if (pos<0||pos>current+1)
    {
        return -1;
    }
    if (pos==0) 
    {
        return insertbeg(num);
    }
    if (pos==current+1)
    {
        return insertend(num);
    }
    for (int i=current;i>=pos;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos]=num;
    current++;
    return 1;
}

//deletes first element; returns deleted element, and 0 if list is empty
int list::delbeg()
{
    if (current<0)
    {
        return 0;
    }
    int temp=arr[0];
    for(int i=0;i<current;i++)
    {
        arr[i]=arr[i+1];
    }
    current--;
    return temp;
}

//deletes last element and returns it, returns 0 if list is empty
int list::delend()
{
    if (current<0)
    {
        return 0;
    }
    current--;
    return arr[current+1];
}

//deletes and returns element at pos, returns 0 if list is empty and -1 if invalid pos
int list::delpos(int pos)
{
    if (current<0)
    {
        return 0;
    }
    if (pos<0||pos>current)
    {
        return -1;
    }
    if (pos==0) 
    {
        return delbeg();
    }
    if (pos==current)
    {
        return delend();
    }
    int temp=arr[pos];
    for (int i=pos;i<current;i++)
    {
        arr[i]=arr[i+1];
    }
    current--;
    return temp;
}

//searches for given element and returns its index, returns -1 if not found
int list::search(int elt)
{
    for (int i=0;i<=current;i++)
    {
        if (arr[i]==elt)
        {
            return i;
        }
    }
    return -1;
}

//rotate list by k towards right; complexity O(n), returns 1 for success, 0 for failure
int list::rotate1(int k)
{
    if (k<0)
    {
        return 0;
    }
    if(current<0) return 0;
    k%=current+1;
    if(k==0) return 1;
    int temp[current+1-k];
    int j=0;
    for(int i=k;i<=current;i++)
    {
        temp[i-k]=arr[i];
        if(j<k)
        {
            arr[i]=arr[i-k];
        }
        else
        {
            arr[i]=temp[j-k];
        }
        j++;
    }
    for(int i=0;i<k;i++)
    {
        if(k>j)
        {
            arr[i]=arr[j];
        }
        else
        {
            arr[i]=temp[j-k];
        }
        j++;
    }
    return 1;
}

//rotate list, complexity O(n)
int list::rotate2(int k)
{
    if(k<0) return 0;
    if(current<0) return 0;
    k%=current+1;
    if(k==0) return 1;
    int temp[current+1];
    for(int i=0;i<=current;i++)
    {
        temp[(i+k)%(current+1)]=arr[i];
    }
    for(int i=0;i<=current;i++)
    {
        arr[i]=temp[i];
    }
    return 1;
}

//rotates list with space complexity O(1), returns 1 for success, 0 for failure
int list::rotate3(int k)
{
    if (k<0) return 0;
    k%=(current+1);
    if (k==0) return 1;
    reverse(arr,0,current);
    reverse(arr,0,k-1);
    reverse(arr,k,current);
    return 1;
}

//displays list
void list::display()
{
    if (current==-1)
    {
        printf("List is empty\n\n");
        return;
    }
    printf("\nList is: ");
    for (int i=0;i<=current;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n\n");
}