#include <stdio.h>
struct node {
    int next;
    int last;
    int self;
};

int main()
{
    // freopen("test","r",stdin);
    struct node array[100];
    int first=0;
    int i=0;
    array[0].last=-1;
    // while(scanf("%d",&(array[i++].self)!=EOF));
    for(i=0;i<5;i++)
    {
        array[i].self=5-i;
    }
    for(i=0;i<5;i++)
    {
        printf("%d",array[i].self);
    }
    array[i-1].next=-2;
    
    for(i=1;i<5;i++)//取数
    {
        
        // else{
            for(int j=0;j<i;j++)//比较
        {
            // if(array[i].self>array[j].self);//new node
            if(array[i].self>array[j].self)//new node 
            {
                if(array[j].next==-2)
                {
                    array[j].next=i;
                    array[i].last=j;
                    array[i].next=-2;
                }
                else if(array[i].self<array[array[j].next].self)
                {
                    array[i].next=array[j].next;
                    array[j].next=i;
                    array[array[j].next].last=i;
                    array[i].last=j;
                }
                else break;
            }
            if(array[i].self<=array[j].self)
            {
                if(array[j].last==-1)
                {
                    array[i].last=-1;
                    array[i].next=j;
                    array[j].last=i;
                    first=i;
                }
                else if(array[i].self>=array[array[j].last].self)
                {
                   array[i].next=i;
                   array[i].last= array[j].last;
                   array[j].last=i;
                   array[array[j].last].next=i;
                }

            }
            
        



        }
        
    }
    while(first!=-2)
    {
        printf("%d",array[first].self);
        first=array[first].next;
    }

}