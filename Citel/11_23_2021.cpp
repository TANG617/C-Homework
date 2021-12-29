#include<iostream>
using namespace std;
//0-127
//192
//224
int que[10000],j=0;
void way1(int hex1)
{

    // scanf("%x",&hex);
    // printf("%d",hex);
    que[j++]=hex1;

}
void way2(int hex1)
{
        int hex2,hex;
        scanf("%x",&hex2);
        hex1=hex1%32;
        hex2=hex2%64;
        // printf("%d:%d\n",hex1,hex2);
        hex=hex1*64+hex2;
        // printf("%d",hex);
        que[j++]=hex;
}void way3(int hex1)
{
    int hex2,hex3,hex;
        scanf("%x%x",&hex2,&hex3);
        hex1=hex1%8;
        hex2=hex2%64;
        hex3=hex3%64;
        hex1*=4096;
        hex2*=64;
        hex=hex1+hex2+hex3;
        // printf("%d",hex);
        que[j++]=hex;
}
int main()
{
    int n,hex1;
    freopen("in.txt","r",stdin);
    freopen("out3.txt","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%x",&hex1);
        if(hex1<=127) way1(hex1);
        else if(hex1>=192 && hex1<224) 
        {
            way2(hex1);
            i++;
        }
        else if(hex1>=224) 
        {
            way3(hex1);
            i++;
            i++;
        }

    }
    printf("%d\n",j);
    for(int i=0;i<j;i++)
    {
        printf("%d",que[i]);
        if(i!=j-1) printf(" ");
    }
}