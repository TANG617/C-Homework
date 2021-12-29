#include <stdio.h>
void swap(int *a,int*b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

struct node
{
    int forward,next;
    int self;
};

void insert_sort(struct node *array,int n)//插入排序
{

}

// void new_node(struct node *a,)

void bubble_sort(int *array,int n)//冒泡排序
{
int start=0,end=n-1,temp;
for(int i=0;i<n;i++)
{
    while(start<end-i)
    {
        if(*(array+start)>*(array+start+1))
        {
           swap(array+start,array+start+1);
        }
        start++;
    }
start=0;
}
}


void choose_sort(int *array,int n)//选择排序
{
for(int i=0;i<n-1;i++)
{
    int min=i;
    for(int p=i;p<n;p++)
    {
        if(array[p]<array[min])
        {
            min=p;
        }
    }
    swap(array+i,array+min);
}
}

int main()
{
    int ar[]={5,4,2,3,1};
    
    
    struct node array[100];
    array[0].self=ar[0];
    array[0].forward=-1;
    array[0].next=-2;
    int jmax=1;
    for(int i=1;i<sizeof(ar)/sizeof(int);i++)
    {
        for(int j=0;j<jmax;j++)
        {
            if(ar[i]>array[j].self)
            {
                if(array[j].next=-2)
                {
                    //newnode
                }
                else
                {
                    array[jmax]
                }
            }
        }
        
    }

    // for(int i=1;i<sizeof(ar)/sizeof(int)-1;i++)
    // {
    //     array.self=ar[i];
    //     array.forward=i-1;
    //     array.next=i+1;
    // }


    choose_sort(ar,sizeof(ar)/sizeof(int));
    for(int i=0;i<5;i++)
    {
        printf("%d",ar[i]);
    }
}