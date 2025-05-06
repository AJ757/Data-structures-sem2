/*

Menu driven program to implement list ADT using doubly linked list with following methods:
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
    
*/

#include <stdio.h>
#include <stdlib.h>

class dll
{
    private:
        struct node
        {
            int data;
            struct node * next;
            struct node * prev;
        }*head,*tail;
        int size;

    public:
        dll()
        {
            head=NULL;
            tail=NULL;
            size=0;
        }
        struct node * createnode(int);
        int validpos(int,int,int);
        int insert_beg(int);
        int insert_end(int);
        int insert_pos(int,int);
        int del_beg();
        int del_end();
        int del_pos(int);
        int search(int);
        void display();
        void free_list();
};

int take_input();
int take_pos();
int take_num_search();

int check_input(int);

void disp_error_pos(int);
void del_display(int);
void search_display(int,int);

int main()
{
    dll l;
    int ch,num,pos;
    do
    {
        printf("\n\tMENU\n1.Insert at beginning\n2.Insert at end\n3.Insert at position\n");
        printf("4.Delete at beginning\n5.Delete at end\n6.Delete at position\n");
        printf("7.Search\n8.Display\n9.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
            {
                num=take_input();
                if (num!=0)
                {
                    disp_error_pos(l.insert_beg(num));
                }
                break;
            }
            case 2:
            {
                num=take_input();
                if (num!=0)
                {
                    disp_error_pos(l.insert_end(num));
                }
                break;
            }
            case 3:
            {
                num=take_input();
                if (num!=0)
                {
                    pos=take_pos();
                    disp_error_pos(l.insert_pos(num,pos));
                }
                break;
            }
            case 4:
            {
                del_display(l.del_beg());
                break;
            }
            case 5:
            {
                del_display(l.del_end());
                break;
            }
            case 6:
            {
                pos=take_pos();
                del_display(l.del_pos(pos));
                break;
            }
            case 7:
            {
                num=take_num_search();
                search_display(num,l.search(num));
                break;
            }
            case 8:
            {
                l.display();
                break;
            }
            case 9:
            {
                printf("Exiting...\n");
                break;
            }
            default:
            {
                printf("Invalid input.\n");
            }
        }
    }while(ch!=9);
    l.free_list();
    return 0;
}

//Takes input from user to insert element
//returns 0 if invalid, element otherwise
int take_input()
{
    printf("\nEnter element (except 0 and -1): ");
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
int take_num_search()
{
    int num;
    printf("\nEnter element to search: ");
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
void disp_error_pos(int num)
{
    if (num==0)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    if (num==-1)
    {
        printf("\nInvalid position.\n");
    }
}

//Displays message according to result of deletion method
void del_display(int num)
{
    if (num==0)
    {
        printf("\nList is already empty.\n");
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
void search_display(int num,int pos)
{
    if (pos==-1)
    {
        printf("%d not found.\n",num);
        return;
    }
    printf("%d found at index %d\n",num,pos);
}

//Creates a new node dynamically and assigns its data, next and prev initialized to NULL
//Input:    num - int - data to be inserted
//returns 0 if memory allocation fails, pointer to new node otherwise
struct dll::node * dll::createnode(int num)
{
    struct node * newnode =(struct node *)malloc(sizeof(struct node));
    if (newnode!=NULL) 
    {
        newnode->data=num;
        newnode->prev=NULL;
        newnode->next=NULL;
    }
    return newnode;
}

//Checks if position value is within given bounds
//Input:    pos - int - position to check
//          beg - int - lower bound
//          end - int - upper bound
//returns 1 if valid, 0 otherwise
int dll::validpos(int pos,int beg,int end)
{
    if (pos>=beg && pos<=end) return 1;
    return 0;
}

//Inserts element in beginning of list
//Input:    num - int - number to be inserted
//returns 0 if memory allocation fails, 1 otherwise
int dll::insert_beg(int num)
{
    struct node * newnode=createnode(num);
    if (newnode==NULL) return 0;
    newnode->next=head;
    if (head==NULL)
    {
        tail=newnode;
    }
    else
    {
        newnode->next->prev=newnode;
    }
    head=newnode;
    size++;
    return 1;
}

//Inserts element in the end of list
//Input:    num - int - number to be inserted
//returns 0 if memory allocation fails, 1 otherwise
int dll::insert_end(int num)
{
    if (head==NULL) return insert_beg(num);
    struct node * newnode=createnode(num);
    if (newnode==NULL) return 0;
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
    size++;
    return 1;
}

//Inserts element at given position of list
//Input:    num - int - number to be inserted
//          pos - int - position at which to be inserted
//returns 0 if memory allocation fails, -1 for invalid position, 1 for success
int dll::insert_pos(int num,int pos)
{
    if (validpos(pos,0,size)==0) return -1;
    if (pos==0) return insert_beg(num);
    if (pos==size) return insert_end(num);
    
    struct node * newnode=createnode(num);
    if (newnode==NULL) return 0;

    struct node * temp=head;
    for (int i=0;i<pos-1;i++)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next=newnode;
    newnode->next->prev=newnode;
    size++;
    return 1;
}

//Deletes element in the beginning of list
//returns 0 if list is empty, deleted element if successful
int dll::del_beg()
{
    if (head==NULL) return 0;

    struct node * temp = head;
    head=head->next;
    if (head==NULL)
    {
        tail=NULL;
    }
    else
    {
        head->prev=NULL;
    }
    int num=temp->data;
    free(temp);
    size--;
    return num;
}

//Deletes element in the end of list 
//returns 0 if list is empty, deleted element if successful
int dll::del_end()
{
    if (size<=1) return del_beg();
    int num=tail->data;
    tail=tail->prev;
    free(tail->next);
    tail->next=NULL;
    size--;
    return num;
}

//Deletes element at a position of list
//returns -1 if invalid position, deleted element if successful
int dll::del_pos(int pos)
{
    if (head==NULL) return 0;
    if (validpos(pos,0,size-1)==0) return -1;
    if (pos==0) return del_beg();
    if (pos==size-1) return del_end();

    struct node * temp=head;
    for (int i=0;i<pos-1;i++)
    {
        temp=temp->next;
    }
    struct node * temp2=temp->next;
    temp->next=temp2->next;
    temp2->next->prev=temp;
    int num=temp2->data;
    free(temp2);
    size--;
    return num;
}

//Searches list for element linearly
//Input:    num - int - element to search
//returns index if found, -1 otherwise
int dll::search(int num)
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

//Displays list with proper format in forward and backward direction:
//NULL <--> elt <--> elt ... --> NULL
//displays error message if list is empty
void dll::display()
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node * temp=head;
    printf("\nForward : NULL <--");
    while(temp!=tail)
    {
        printf(" %d <-->",temp->data);
        temp=temp->next;
    }
    printf(" %d --> NULL\n",temp->data);
    printf("Backward : NULL <--");
    while(temp!=head)
    {
        printf(" %d <-->",temp->data);
        temp=temp->prev;
    }
    printf(" %d --> NULL\n",temp->data);
}

//Clears dynamically allocated memory of list by repeatedly calling deletion at beginning
void dll::free_list()
{
    while (head!=NULL)
    {
        del_beg();
    }
}