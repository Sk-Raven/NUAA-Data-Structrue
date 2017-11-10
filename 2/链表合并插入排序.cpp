#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
void insertsort(node *a,node *b)
{   if(a->next==NULL)
    {
        a->next=b->next;
        return;
    }
    if(b->next==NULL)
    {
        return;
    }

    node *ha=a;
    node *hb=b->next;
    bool flag= false;

        while(hb&&ha->next)
        {
            if(hb->data < ha->next->data)
            { node *temp=new node();
                temp->data=hb->data;
                temp->next=ha->next;
                ha->next=temp;
                ha=temp;
                flag= true;
            }
            if(flag== false)
            ha=ha->next;
            else
            {
                hb = hb->next;
                flag= false;
            }
        }
    if(hb!=NULL)
       {
       	node *temp=b->next;
       	
       	while(temp->next!=hb)
       	temp=temp->next;
       	
       	temp->next=NULL;
       	ha->next=hb;
       	
	   }



    }

void DestroyList(node *L)
{
    node *temp;
    while(L->next)
    {
        temp=L->next;
        delete []L;
        L=temp;
    }
    delete []L;
    printf("\ndeletesucced");

}
int main()
{
    node *head=new node();
    node *ha=head;
    printf("a:");
    for(int i=0;i<5;i++)
    {
        node *temp=new node();
        temp->data=2*i;
        printf("%d ",temp->data);
        ha->next=temp;
        ha=temp;
    }
    ha->next=NULL;
    printf("\n");
    node *headb=new node();
    node *hb=headb;
    printf("b:");
    for(int i=0;i<5;i++)
    {
        node *temp=new node();
        temp->data=2*i+1;
        printf("%d ",temp->data);
        hb->next=temp;
        hb=temp;
    }
    hb->next=NULL;
    insertsort(head,headb);
    printf("\nsort\na:");
    ha=head->next;
    while(ha!=NULL)
    { 
	  printf("%d ",ha->data);
	  ha=ha->next;
	}
    DestroyList(head);
    DestroyList(headb);
}
