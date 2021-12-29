#include<stdio.h>
int main()
{
    int a=0;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            printf("\n");
            printf("J:%d",j);
            // if(j>=5) continue;
            if(j>=5) break;
            printf("   a:%d",++a);
        }
        
    }
    // printf("%d",a);
}