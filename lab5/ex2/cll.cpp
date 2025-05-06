/*

Menu driven program to implement list ADT using circular linked list with following methods:
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

*/

#include <stdio.h>
#include <stdlib.h>

class cll
{
    private:
        struct node
        {
            int data;
            struct node * next;
        }*head,*tail;
        int size;

    public:
        cll()
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
    cll l;
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
struct cll::node * cll::createnode(int num)
{
    struct node * newnode =(struct node *)malloc(sizeof(struct node));
    if (newnode!=NULL) 
    {
        newnode->data=num;
        newnode->next=newnode;
    }
    return newnode;
}

//Checks if position value is within given bounds
//Input:    pos - int - position to check
//          beg - int - lower bound
//          end - int - upper bound
//returns 1 if valid, 0 otherwise
int cll::validpos(int pos,int beg,int end)
{
    if (pos>=beg && pos<=end) return 1;
    return 0;
}

//Inserts element in beginning of list
//Input:    num - int - number to be inserted
//returns 0 if memory allocation fails, 1 otherwise
int cll::insert_beg(int num)
{
    struct node * newnode=createnode(num);
    if (newnode==NULL) return 0;

    if (head==NULL)
    {
        tail=newnode;
    }
    else
    {
        newnode->next=head;
    }
    tail->next=newnode;
    head=newnode;
    size++;
    return 1;
}

//Inserts element in the end of list by modifying head and tail after inserting at beginning
//Input:    num - int - number to be inserted
//returns 0 if memory allocation fails, 1 otherwise
int cll::insert_end(int num)
{
    if (insert_beg(num))
    {
        tail=head;
        head=head->next;
        return 1;
    }    
    return 0;
}

//Inserts element at given position of list
//Input:    num - int - number to be inserted
//          pos - int - position at which to be inserted
//returns 0 if memory allocation fails, -1 for invalid position, 1 for success
int cll::insert_pos(int num,int pos)
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
    temp->next=newnode;
    size++;
    return 1;
}

//Deletes element in the beginning of list
//returns 0 if list is empty, deleted element if successful
int cll::del_beg()
{
    if (head==NULL) return 0;
    int num=head->data;
    size--;
    if (head==tail)
    {
        free(head);
        head=tail=NULL;
        return num;
    }
    head=head->next;
    free(tail->next);
    tail->next=head;
    return num;
}


//Deletes element in the end of list 
//uses deletion at position
//returns 0 if list is empty, deleted element if successful
int cll::del_end()
{
    return del_pos(size-1);
}

//Deletes element at a position of list
//returns -1 if invalid position, deleted element if successful
int cll::del_pos(int pos)
{
    if (head==NULL) return 0;
    if (validpos(pos,0,size-1)==0) return -1;
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
    size--;
    if (pos==size) 
    {
        tail=temp;
    }
    if (size==0) 
    {
        head=tail=NULL;
    }
    return num;
}

//Searches list for element linearly
//Input:    num - int - element to search
//returns index if found, -1 otherwise
int cll::search(int num)
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
    }while(temp!=head);
    return -1;
}

//Displays list with proper format:
//HEAD -> elt -> elt ... -> HEAD
//displays error message if list is empty
void cll::display()
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node * temp=head;
    printf("\n HEAD ->");
    while(temp!=tail)
    {
        printf(" %d ->",temp->data);
        temp=temp->next;
    }
    printf(" %d -> HEAD\n",temp->data);
}

//Clears dynamically allocated memory of list by repeatedly calling deletion at beginning
void cll::free_list()
{
    while (size!=0)
    {
        del_beg();
    }
}