#include<iostream>
using namespace std;
int a[10];
void insertsort(int unsort[],int length,int k)
{
int temp;
for (int i=k+1;i<length;i++)
{if (unsort[i-1]>unsort[i]) 
{
temp=unsort[i];
int a =i;
while(a>0&&unsort[a-1]>temp)
{
unsort[a]=unsort[a-1];
a--;
}
unsort[a]=temp;
}
}
}
int main()
{ 
	for(int i=0;i<10;i++)
	a[i]=10-i;
	
	for(int i=0;i<10;i++)
	cout<<a[i]<<" ";
	
	insertsort(a,10,0);
	cout<<endl<<"insertsort"<<endl;
	
	for(int i=0;i<10;i++)
	cout<<a[i]<<" ";
}

