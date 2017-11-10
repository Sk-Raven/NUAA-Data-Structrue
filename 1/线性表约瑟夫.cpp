#include<iostream>
using namespace std;
bool a[100];
int b[100];
void ysf(int n,int s,int m)
{
	int k=s;
	int i=1;
	int num=1;
	while(1)
	{
		if(!a[k])
		{
			
		    if(i==m)
		    {
			 printf("%d ",k);
			 i=1;
			 a[k]=true;
			 num++;
			 if(k==n)
		        k=0;
			 k++;
			 	
		        
			 continue;
		    }
		    i++;
		    
		    
		    
		   
		}
		
		if(k==n)
		k=0;
		
		k++;
		if(num==n)
		break;
	
	}
}
int main()
{   for(int i=1;i<=10;i++)
    printf("%d ",i);
    printf("\n");
	ysf(10,5,3);
}
