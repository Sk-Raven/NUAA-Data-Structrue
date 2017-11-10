#include<iostream>
using namespace std;
class ADT{
	public:
		int data;
		ADT *next;
	ADT()
	{
		data=0;
		next=NULL;
	}
};
void swp(ADT *head)
{
	if(head==NULL||head->next==NULL)
	return;
	ADT *h=head->next;
	ADT *cur=h->next;
	head->next->next=NULL;
	ADT *tmp;
	while(cur)
	{   tmp=cur->next;
		cur->next=h;
		h=cur;
		cur=tmp;
		
	}
	head->next=h;
    
	
}
int main()
{
	ADT head,p1,p2,p3,p4;
	head.next=&p1;
	p1.next=&p2;
	p2.next=&p3;
	p3.next=&p4;
	head.data=0;
	p1.data=1;
	p2.data=2;
	p3.data=3;
	p4.data=4;
	ADT *tmp=&head;
	while(tmp)
    {
    	printf("%d",tmp->data);
    	tmp=tmp->next;
	}
	printf("\n1\n");
	swp(&head);
    tmp=&head;
    while(tmp)
    {
    	printf("%d",tmp->data);
    	tmp=tmp->next;
	}
	printf("\n2\n");
	swp(&head);
	tmp=&head;
    while(tmp)
    {
    	printf("%d",tmp->data);
    	tmp=tmp->next;
	}
	
	
	
}
