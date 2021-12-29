 #include<stdio.h>
 #include<string.h>
 struct xp
 {
  char name[20];
  int  piao;
 }peo[100];
 int main()
 {
     int n,m;
     scanf("%d",&n);
     for(int i=0;i<n;i++)
     {
         scanf("%s",peo[i].name);
         peo[i].piao=0;
     }
     scanf("%d",&m);
    //  printf("YES\n");
     for(int i=0;i<m;i++)
     {
         char temp[20];
         scanf("%s",temp);
         for(int j=0;j<n;j++)
         {
             if(strstr(temp,peo[j].name) && strstr(peo[j].name,temp)) peo[j].piao++;
         }
     }
     for(int i=0;i<n;i++)
     {
         printf("%s %d\n",peo[i].name,peo[i].piao);
     }
     
 }
 // A       B    
 //00010010 00110100
 //
