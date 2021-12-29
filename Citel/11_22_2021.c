#include<stdio.h>
int search(int nArray[], int n, int x)//n为位数，x为需要查找的数
{
    int start =0,end = n-1,mid;
   if(nArray[start]==x ||nArray[end]==x) return 1;
    while(start!=end || start+1!=end)
    {
    mid=(start+end)/2;
    if(nArray[mid]>x) end=mid;
    else if (nArray[mid]<x) start = mid;
    else return 1;
    }
    //1 2 3(4)5 6 
    //0 1 2 3 4 5
    //    | .    | 
    return 0;
}
int main()
{
    int A[6]={1,2,3,4,5,6};
    printf("%d",search(A,6,6));
    return 0;
}
