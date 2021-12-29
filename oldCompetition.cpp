#include<iostream>
using namespace std;
int num[100000001],question[100001];
int main()
{
    // freopen("test","r",stdin);
    // freopen("test.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int position,range,temp;
        cin>>position>>range;
        // printf("%d",i);
        temp=num[position]+range;
        while(temp!=0)
        {
            num[position++]=temp--;
        }
    }
    // for(int i=0;i<10000;i++)
    // {
    //     cout<<num[i]<<' ';
    // }
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
    cin>>question[i];
    }
    for(int i=0;i<k;i++)
    {
        int temp=question[i];
        if(temp==0) 
        {
            printf("Yes\n");
            continue;
        }
        if(num[temp-1]!=0) printf("Yes\n");
        else printf("No\n");
    }
}