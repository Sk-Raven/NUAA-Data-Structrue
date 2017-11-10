#include<iostream>
using namespace std;
class ADT
{
	public:
		int data;
		ADT *next;
		
}; 
ADT *head;

void ysf(int n,int s,int m)
{   ADT *temp=head;
	
	int i=1;
	int num=1;
	
	for(int l=1;l<s;l++)
	temp=temp->next;
	
	while(1)
	{
		if(temp->data!=0)
		{
			
		    if(i==m)
		    {
			 printf("%d ",temp->data);
			 i=1;
			 temp->data=0;
			 num++;
			 
			 if(!temp->next)
			 temp=head;
			 	
		     temp=temp->next;   
			 continue;
		    }
		    
		    i++;
		    
		    
		    
		   
		}
		
		if(!temp->next)
		{
		 temp=head;
		 continue;
	    }
	
	    

		temp=temp->next;
		if(num==n)
		break;
	
	}
}
int main()
{
 ADT *h=new ADT();
 head=h;
 h->data=1;
 
for(int k=0;k<9;k++)
{
	ADT *tmp=new ADT();
	tmp->data=k+2;
	h->next=tmp;
	h=tmp;
}

h->next=NULL;
h=head;

while(h)
{
	printf("%d ",h->data);
	h=h->next;
}
 printf("\n");
 ysf(10,1,3);
    ADT *temp;
	while(head->next)
	{
    temp=head->next;
	delete []head;
	head=temp;
    }
    delete []head;

 
}
