/*

Program to implement list ADT using singly linked list
Methods implemented:
1.Insert 
    -beginning
    -end
    -position
2.Delete
    -beginning
    -end
    -position
3.Search
4.Display
    -normal
    -reverse
5.Reverse links

*/

#include <stdio.h>
#include <stdlib.h>

class sll
{
    private:
        struct node
        {
            int data;
            struct node * next;
        }*head,*tail;
        int length;
    public:
        sll()
        {
            head=NULL;
            tail=NULL;
            length=0;
        }
        struct node * createnode(int);
        int validpos(int,int,int);
        void store_arr(int *);
        int insert_beg(int);
        int insert_end(int);
        int insert_pos(int,int);
        int del_beg();
        int del_end();
        int del_pos(int);
        int search(int);
        void display();
        void display_rev();
        void reverse();
        void free_list();
};

//input functions
int take_input();
int take_pos();
int input_num_search();

//utility 
int check_input(int);

//display functions
void disp_empty_pos(int);
void display_del(int);
void display_search(int,int);
void display_list(class sll,int);

int main()
{
    int ch,num,pos;
    sll list;
    do
    {
        printf("\n\tMENU\n1.Insert at beginning\n2.Insert at end\n3.Insert at position\n");
        printf("4.Delete at beginning\n5.Delete at end\n6.Delete at position\n");
        printf("7.Search\n8.Display\n9.Display Reverse\n10.Reverse link\n11.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                num=take_input();
                if (num!=0)
                {
                    list.insert_beg(num);
                }
                break;
            }
            case 2:
            {
                num=take_input();
                if (num!=0)
                {
                    list.insert_end(num);
                }
                break;
            }
            case 3:
            {
                num=take_input();
                if (num!=0)
                {
                    pos=take_pos();
                    disp_empty_pos(list.insert_pos(num,pos));
                }
                break;
            }
            case 4:
            {
                display_del(list.del_beg());
                break;
            }
            case 5:
            {
                display_del(list.del_end());
                break;
            }
            case 6:
            {
                pos=take_pos();
                display_del(list.del_pos(pos));
                break;
            }
            case 7:
            {
                num=input_num_search();
                display_search(num,list.search(num));
                break;
            }
            case 8:
            {
                display_list(list,0);
                break;
            }
            case 9:
            {
                display_list(list,-1);
                break;
            }
            case 10:
            {
                list.reverse();
                break;
            }
            case 11:
            {
                printf("\nExiting...\n");
                break;
            }
            default:
            {
                printf("\nInvalid input.\n");
            }
        }
    }while(ch!=11);
    list.free_list();
    return 0;
}


//Takes input from user to insert element
//returns 0 if invalid, element otherwise
int take_input()
{
    printf("Enter element (except 0 and -1) to insert: ");
    int num;
    scanf("%d",&num);
    if (check_input(num)==0)
    {
        printf("Invalid input for element.\n");
        return 0;
    }
    return num;
}

//Takes input from user for position
//returns value to be inserted
int take_pos()
{
    printf("Enter position: ");
    int num;
    scanf("%d",&num);
    return num;
}

//Takes input from user for search
//returns element to search for
int input_num_search()
{
    printf("Enter element to search: ");
    int num;
    scanf("%d",&num);
    return num;
}

//Checks if number to be inserted is not a boundary case
//returns 0 if cannot be inserted, 1 if okay
int check_input(int num)
{
    if (num==0 || num==-1) return 0;
    return 1;
}

//Displays message for boundary cases of memory allocation faillure or invalid position
void disp_empty_pos(int num)
{
    if (num==-1)
    {
        printf("\nInvalid position.\n");
        return;
    }
    if (num==0)
    {
        printf("\nMemory allocation failure.\n");
        return;
    }
}

//Displays message according to result of deletion methods
void display_del(int num)
{
    if (num==0)
    {
        printf("\nList is already empty\n");
        return;
    }
    if (num==-1)
    {
        printf("\nInvalid position.\n");
        return;
    }
    printf("\nDeleted element is %d\n",num);
}

//Displays message accoring to result of search method
void display_search(int num,int pos)
{
    if (pos==-1) 
    {
        printf("\n%d not found.\n",num);
        return;
    }
    printf("\n%d found at index %d\n",num,pos);
}

//Displays list in forward/reverse order
//Input:    l - singly linked list (class sll)
//          num - int - 0 for normal display, -1 for reverse
void display_list(class sll l,int num)
{
    printf("\n");
    if (num==0) 
    { 
        l.display();
    }
    else if (num==-1)
    {
        l.display_rev();
    }
}

//Creates a new node (sll::node) dynamically and assigns its data
//Input:    num - int - data to be inserted
//returns 0 if memory allocation fails, pointer to new node otherwise
struct sll::node * sll::createnode(int num)
{
    struct node * newnode =(struct node *)malloc(sizeof(struct node));
    if (newnode==NULL) return 0;
    newnode->data=num;
    return newnode;
}

//Checks if position value is within given bounds
//Input:    pos - int - position to check
//          beg - int - lower bound
//          end - int - upper bound
//returns 1 if valid, 0 otherwise
int sll::validpos(int pos,int beg,int end)
{
    if (pos>=beg && pos<=end) return 1;
    return 0;
}

//Creates a deep copy of list as an array
//Input:    arr - int * - empty array of proper size to be stored in
//modifies arr
void sll::store_arr(int * arr)
{
    struct node * temp=head;
    for(int i=0;temp!=NULL;i++)
    {
        arr[i]=temp->data;
        temp=temp->next;
    }
}

//Inserts element in beginning of list
//Input:    num - int - number to be inserted
//returns 0 if memory allocation fails, 1 otherwise
int sll::insert_beg(int num)
{
    struct node * newnode=createnode(num);
    if (newnode==0) return 0;
    newnode->next=head;
    if (head==NULL)
    {
        tail=newnode;
    }
    head=newnode;
    length++;
    return 1;
}

//Inserts element in the end of list
//Input:    num - int - number to be inserted
//returns 0 if memory allocation fails, 1 otherwise
int sll::insert_end(int num)
{
    if (head==NULL)
    {
        return insert_beg(num);
    }
    struct node * newnode=createnode(num);
    if (newnode==0) return 0;
    newnode->next=NULL;
    tail->next=newnode;
    tail=newnode;
    length++;
    return 1;
}

//Inserts element at given position of list
//Input:    num - int - number to be inserted
//          pos - int - position at which to be inserted
//returns 0 if memory allocation fails, -1 for invalid position, 1 for success
int sll::insert_pos(int num,int pos)
{
    if (validpos(pos,0,length)==0) return -1;
    if (pos==0) return insert_beg(num);
    if (pos==length) return insert_end(num);
    
    struct node * newnode=createnode(num);
    if (newnode==0) return 0;

    struct node * temp=head;
    for (int i=0;i<pos-1;i++)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    length++;
    return 1;
}

//Deletes element in the beginning of list
//returns 0 if list is empty, deleted element if successful
int sll::del_beg()
{
    if (head==NULL) return 0;

    struct node * temp = head;
    head=head->next;
    if (head==NULL)
    {
        tail=NULL;
    }
    int num=temp->data;
    free(temp);
    length--;
    return num;
}

//Deletes element in the end of list 
//uses deletion at position
//returns 0 if list is empty, deleted element if successful
int sll::del_end()
{
    return del_pos(length-1);
}

//Deletes element at a position of list
//returns -1 if invalid position, deleted element if successful
int sll::del_pos(int pos)
{
    if (validpos(pos,0,length-1)==0) return -1;
    if (pos==0) return del_beg();
    struct node * temp=head;
    for (int i=0;i<pos-1;i++)
    {
        temp=temp->next;
    }
    struct node * temp2=temp->next;
    temp->next=temp2->next;
    int num=temp2->data;
    free(temp2);
    length--;

    if (pos==length) tail=temp;
    if (length==0) head=NULL;
    return num;
}

//Searches list for element linearly
//Input:    num - int - element to search
//returns index if found, -1 otherwise
int sll::search(int num)
{
    if (head==NULL) return -1;
    struct node * temp=head;
    int i=0;
    do
    {
        if (temp->data==num)
        {
            return i;
        }
        temp=temp->next;
        i++;
    }while(temp!=NULL);
    return -1;
}

//Displays list with proper format:
//HEAD -> elt -> elt ... -> NULL
//displays error message if list is empty
void sll::display()
{
    if(head==NULL)
    {
        printf(" List is empty\n");
        return;
    }
    struct node * temp=head;
    printf(" HEAD ->");
    while(temp!=tail)
    {
        printf(" %d ->",temp->data);
        temp=temp->next;
    }
    printf(" %d -> NULL\n",temp->data);
}

//Displays list in reverse with proper format:
//NULL <- elt <- elt ... <- HEAD
//displays error message if list is empty
void sll::display_rev()
{
    if (head==NULL)
    {
        printf(" List is empty\n");
        return;
    }
    int arr[length];
    store_arr(arr);
    printf(" NULL <-");
    for (int i=length-1;i>0;i--)
    {
        printf(" %d <-",arr[i]);
    }
    printf(" %d <- HEAD\n",arr[0]);
}

//Reverses the list in place using arrays
void sll::reverse()
{
    if (length<=1) return;
    int arr[length];
    store_arr(arr);
    struct node * temp=head;
    for (int i=length-1;temp!=NULL;i--)
    {
        temp->data=arr[i];
        temp=temp->next;
    }
}

//Clears dynamically allocated memory of list by repeatedly calling deletion at beginning
void sll::free_list()
{
    while (length!=0)
    {
        del_beg();
    }
}