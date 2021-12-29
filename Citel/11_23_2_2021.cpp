#include<iostream>
using namespace std;
int main()
{
    int number_of_pages,number_of_lost_pages,lost_pages[500001],number_of_people,r,result_of_people[100001];
    cin>>number_of_pages>>number_of_lost_pages>>number_of_people;
    for(int i=0;i<number_of_lost_pages;i++)
    {
        cin>>lost_pages[i];
    }
    for(int i=0;i<number_of_people;i++)
    {
        cin>>r;
        int temp;
        temp=number_of_pages/r;
        for(int j=0;j<number_of_lost_pages;j++)
        {
            if(lost_pages[j]%r==0)temp--;
        }
        result_of_people[i]=temp;
    }
    for(int i=0;i<number_of_people;i++)
    {
        printf("%d\n",result_of_people[i]);
    }
}