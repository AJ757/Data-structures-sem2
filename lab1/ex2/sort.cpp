
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
            if(arr[j]>key)
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            j--;
        }
    }
}