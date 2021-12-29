#include<stdio.h>
#include<string.h>
int same(char a[],char b[])
{
    int lea=strlen(a),leb=strlen(b);
    if(a>b) return same(b,a);
    else for(int i=0;i<lea;i++)
    {
        if(!strchr(b,a[i])) return 0;
    }
    return 1;
}
char a[100],b[100];
int main()
{
    
    scanf("%s",a);
    scanf("%s",b);
    if(same(a,b)) printf("Yes\n");
    else printf("No\n");

}