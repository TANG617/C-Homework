#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct EquationInfoStru{
	double a;	//方程系数1
	double b;	//方程系数2
	double c;  //方程系数3
    int nRootStatus;  //方程根的不同情况
	double dRoot1;//方程的第一个根
    double dRoot2;//方程的第二个根
};
int root(struct EquationInfoStru * pEquaInfo)
{
    (*pEquaInfo).nRootStatus=0;
    double temp;
    if(temp=(*pEquaInfo).b*(*pEquaInfo).b-4*(*pEquaInfo).a*(*pEquaInfo).c>=0)
    {
        (*pEquaInfo).nRootStatus=1;
    }
    if((*pEquaInfo).a==0)
    {
        (*pEquaInfo).nRootStatus=2;
    }
    if((*pEquaInfo).nRootStatus==1)
    {
        (*pEquaInfo).dRoot1=(-1*(*pEquaInfo).b+sqrt(temp))/2*(*pEquaInfo).a;
        (*pEquaInfo).dRoot2=(-1*(*pEquaInfo).b-sqrt(temp))/2*(*pEquaInfo).a;
    } 
    if((*pEquaInfo).nRootStatus==2)
    {
        (*pEquaInfo).dRoot1=-1*(*pEquaInfo).c/(*pEquaInfo).b;
        (*pEquaInfo).dRoot2=0;
    } 
}

struct people
{
    char gender;
    double height,weight;
}peo;

int main()
{
scanf("%c",&peo.gender);
scanf("%lf%lf",&peo.height,&peo.weight);
if()
}
