/****************************************************************
╰（‵□′）╯
Referring code made by SFMSupersanta.
Program: Quickshort
version #
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

//bublesort
void bubs(int arr[], int size);

//swap function 
void swap(int *a, int *b);

//partitioning-quick-sort
int partition(int arr[], int low,int high);

//quick sort
void quickSort(int arr[], int low, int high);

//quick sort reversed
void qsortR(int arr[], int low, int high);

void print(int arr[], int size);

//main
int main()
{
    int sort[] = {3,456,323,641,472,431,165,2347,36,346,445,24,2,34,3,4,5,6,7,8,9,10,1100,65};
    int size = sizeof(sort) / sizeof(int);
    quickSort(sort,0,size-1);
    printf("sorted array: ");
    print(sort,size);

    bubs(sort,size);
    printf("\narr buble sort: ");
    print(sort,size);
    quickSort(sort,0,size-1);//reverse arr

    

    return 0;
}

void print(int arr[], int size)
{
    for(int i = 0; i < size;i++)
    {
        printf("%d",arr[i]);
        if(i!=size) printf(" ");
    }
}

//swap function
void swap(int *a, int *b)
{
    int c=*a;
    *a=*b;
    *b=c;
}

//bublesort
void bubs(int arr[], int size)
{
    //printf("\n");
    //print(arr,size);
    //printf("\n%d\n",size);
    for(int i = 0; i < size-1; i++)
    {
        //rintf(" %d ",i);
        for (int j = size-1; j>i; j--)
        {
            //printf("%d ",j);
            if(arr[j] > arr[j-1]) 
            {
                swap(&arr[j],&arr[j-1]);
                //printf("swaped: %d,%d\n",arr[j], arr[j-1]);
            }
        }
    }
}

//partitioning
int partition(int arr[], int low,int high)
{
    //printf("size: %d,%d\n",low,high);
    int i=low-1, middle=arr[high];
    //printf("low,midle: %d, %d\n",i,middle);
    for(int j = low; j < high; j++)
    {
        if(arr[j] < middle)
        {
            i++;
            swap(&arr[i], &arr[j]);
            //printf("swaped: %d,%d\n",arr[j], arr[i]);
        }
    }

    //swap arr[high] in place
    swap(&arr[++i], &arr[high]);

    return i;
}

void qsortR(int arr[], int low, int high)
{

}

//quick sort
void quickSort(int arr[], int low, int high)
{
    if(low<high)
    {
        int pi = partition(arr,low,high);
        //because arr[pi] is already in it's place
        quickSort(arr,low, pi-1);
        quickSort(arr,pi+1,high);
    }
}