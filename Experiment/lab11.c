#include<stdio.h>
struct w
{
    int high,low;
};
union testunion
{
    struct w n;
    int k;
}a;


int main()
{
    a.k=0x12345678;
    printf("%x \n %x\n",a.n.high,a.n.low);

}