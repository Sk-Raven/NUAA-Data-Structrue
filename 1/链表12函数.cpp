#include<iostream>
using namespace std;
bool cmp(int a,int b)
{return a==b;
}
class ADT
{   public:
	int data;
	ADT *next;
	bool operator==(const ADT &p)
	{
		this->data=p.data;
		this->next=p.next;
	}
	ADT()
	{data=0;
	 next=NULL;
	}

};
bool visit(ADT e)
{
	return e.data==2;
}
void InitList(ADT *L)
{
 L->data=0;
 L->next=NULL;
 cout<<"Init success"<<endl;
}
void DestroyList( ADT *L)
{  
    ADT *temp;
	while(L->next)
	{
    temp=L->next;
	delete []L;
	L=temp;
    }
    delete []L;
	cout<<"Destroy success"<<endl;
}
void ClearList( ADT *L)
{
	ADT *temp=L;
	while(temp)
	{
     temp->data=0;
     temp=temp->next;	
    }
	cout<<"Clear success"<<endl;
}
bool ListEmpty( ADT L)
{
	if(L.next!=NULL)
	return true;
	else
	return false;
}
int ListLength(ADT *L)
{    ADT *temp;
    if(L->next)
    temp=L->next;
	else
	return 0;
	int length=0;
	while(temp&&temp!=L)
	{
		length++;
		temp=temp->next;
	}

	return length;
}
bool GetElem(ADT L,const int i, ADT *e)
{   if(ListLength(&L)==0)
    return false;
    int num=0;
    ADT *temp=L.next;
    while(temp)
   {num++;
    if(num==i)
    {
	e->data=temp->data;
	return true;
    } 
	temp=temp->next;
	
   }
   return false;
}
int LocateElem( ADT L,ADT e,bool (*cmpare)(int,int))
{
  ADT *temp=&L;
  temp=temp->next;
  int k=0;
  while(temp)
  {  k++;
	 if(cmpare(temp->data,e.data))
	 return k;
	 else
	 temp=temp->next;
  }
    return 0;
}
bool PriorElem( ADT &L, ADT cur_e,ADT &pre_e)
{

	ADT *temp=&L;
    while(temp->next)
	{pre_e=*temp;
	 temp=temp->next;
	 if(temp->data==cur_e.data)
	 return true;
    }
    pre_e.next=NULL;
    return false;
}
bool NextElem( ADT L, ADT cur_e,ADT &next_e)
{
	
	ADT *temp=&L;
    while(temp->next)
	{
	 temp=temp->next;
	 if(temp->data==cur_e.data)
	 if(temp->next)
	 {next_e=*(temp->next);
	  return true;
     }
    }
    next_e.next=NULL;
    return false;
}
bool ListInsert(ADT &L,const int i, ADT e)
{ if(!ListEmpty(L)||i<1||i>(ListLength(&L)+1))
  return false;
  ADT insert;
  insert=e;
  
    ADT *temp=&L;
	for(int k=0;k!=i-1;k++)
	temp=temp->next;
  if(temp->next)
  insert.next=temp->next;
  else
  insert.next=NULL;
  temp->next=&insert;
  return true;  
}
bool ListDelete( ADT &L,const int i, ADT &e)
{
if(!ListEmpty(L)||i<1||i>(ListLength(&L)+1))
   return false;
    ADT *temp=&L;
	for(int k=0;k!=i-1;k++)
	temp=temp->next;
	e.data=temp->next->data;
    temp->next=temp->next->next;
  return true;  
}
bool ListTraverse(ADT L,bool (*visit)(ADT))
{
	ADT *temp=&L;
	while(temp)
	{if(visit(*temp))
	 return true;
	 temp=temp->next;
	}
	return false;
	
}

int main()
{
	ADT *L=new ADT();
	InitList(L);
	ADT *L1=new ADT();;

	L1->data=1;
	ADT *L2=new ADT();
	
	L2->data=2;
	L->next=L2;	
	printf("ListLength %d\n",ListLength(L)); 
	ListInsert(*L,1,*L1);
	printf("Insert L1 to 1\n");
	printf("ListLength %d\n",ListLength(L)); 
	ADT e;
	
	if(PriorElem(*L,*L1,e))
	printf("pre-L1 %d\n",e.data); 
	if(NextElem(*L,*L2,e))
	printf("next-l2 %d\n",e.data);
	else
	printf("next-L2 is NULL\n");
	if(GetElem(*L,1,&e))
	printf("L[1]=%d\n",e.data);
	if(ListDelete(*L,1,e))
	if(GetElem(*L,1,&e))
	printf("after delete l1,L[1]=%d\n",e.data);
	if(ListTraverse(*L,visit))
	printf("data=2 is find\n");
	e.data=2;
	printf("data=2 is on %d\n",LocateElem(*L,e,cmp));
	ClearList(L);
	printf("after clear,L[1].data=%d\n",L->next->data);
	DestroyList(L);
	
	
	
	
	
	

}
