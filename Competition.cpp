#include<iostream>
using namespace std;
int main()
{
    int n,max;
    int pos,dis;
    // freopen("test","r",stdin);
    // freopen("test.out","w",stdout);
    scanf("%d",&n);
    scanf("%d%d",&pos,&dis);
    max=dis;
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&pos,&dis);
        if(pos<=max)
        {
            max=max+dis;
        }
        else break;
    }
    // printf("%d",max);
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        int temp;
        scanf("%d",&temp);
        if(temp<=max) printf("Yes\n");
        else printf("No\n");
    }
}