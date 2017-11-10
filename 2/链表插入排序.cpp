#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node *next;
};

void insertsort(node *a)
{  
 node *p,*pre,*temp;
 p=a->next->next;
 a->next->next=NULL;
 
 while(p!=NULL)
 {
 	temp=p->next;
 	pre=a;
 	while(pre->next!=NULL&&pre->next->data<p->data)
 	pre=pre->next;
 	p->next=pre->next;
 	pre->next=p;
 	p=temp;
 	
 }
}
int main()
{    
	node *head=new node();
	node *h=head; 
		node *temp;
	for(int k=0;k<10;k++)
	{   
		temp=new node();
		h->next=temp;
		temp->data=10-k;
        h=temp;	
	}
     h->next=NULL;
     h=head;
     for(int k=0;k<10;k++)
     {  h=h->next;
     	printf("%d ",h->data);
     }
     printf("\nsort\n");
     insertsort(head);
     h=head;
      for(int k=0;k<10;k++)
     {  h=h->next;
     	printf("%d ",h->data);
     }

h=head;
for(int k=0;k<11;k++)
{
	temp=h->next;
	delete []h;
	h=temp;
}

} 
