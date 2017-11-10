#include<iostream>
#include<memory.h>
#define INTSIZE sizeof(int)
using namespace std;
int* InitList()
{
  int *a=new int[10];
  memset(a,0,10*sizeof(int));
  return a;
}
void DestoryList(int *l)
{
	delete [] l;
}
void Clear(int *l)
{
	for(int k=0;k<10;k++)
	l[k]=0;
}
bool ListEmpty(int *l)
{
  for(int k=0;k<10;k++)
  if(l[k]!=0)
  return false;
  
  return true;
}

int ListLength(int *l)
{
	int num=0;
	
	 for(int k=0;k<10;k++)
     if(l[k]==0)
     return k;
     
    
}

void GetElem(int *l,int i,int &e)
{
	if(i>=0&&i<=ListLength(l)-1)
    e=l[i-1];
}

int LocateElem(int *l,int e,bool (*cmp)(int,int))
{
	for(int k=1;k<=ListLength(l);k++)
	if(l[k]==e)
	{
	return k+1;
	break;
    }
    return 0;
}

void PriorElem(int *l,int cur_e,int &pre_e)
{
	for(int k=0;k<ListLength(l);k++)
	if(l[k]==cur_e)
	{
	pre_e=l[k-1];
	break;
    }
    
}

void NextElem(int *l,int cur_e,int &next_e)
{
	for(int k=0;k<ListLength(l)-1;k++)
	if(l[k]==cur_e)
	{
	next_e=l[k+1];
	break;
    }
    
}

void ListInsert(int *l,const int i,int e)
{
	
	if(ListEmpty(l)||i<0||i>ListLength(l))
    return ;
    if(l[i-1]==0)
    {
	 l[i-1]=e;
	 return ;
    }
    
    int tmp=ListLength(l);
    while(tmp!=i-1)
    {
	 l[tmp]=l[tmp-1];
	 tmp--;
    }
    
    l[i-1]=e;
   
    
}

bool ListDelete( int *l,const int i,int &e)
{
	if(ListEmpty(l)||i<0||i>=(ListLength(l))||l[i-1]==0)
	return false;
	int tmp=i;
	e=l[i-1];
	while(l[tmp])
	{
		l[tmp-1]=l[tmp];
		tmp++;
	}
	
	return true;
}

bool ListTraverse(int* l,bool (*visit)(int))
{
  for(int k=0;k<ListLength(l);k++)
  if(visit(l[k]))
  return true;
  
  return false;
}
bool visit(int e)
{
	return e==2;
}

bool cmp(int a,int b)
{
  return a==b;
}

int main()
{ int *l=InitList();
    printf("ListLength %d\n",ListLength(l)); 
    l[0]=2;
	ListInsert(l,1,1);
	printf("Insert 1 to l[1]\n");
    
	printf("now l[1]=%d l[2]=%d\n",l[0],l[1]);
    int e;
	PriorElem(l,2,e);
	printf("pre-l[2] %d\n",e); 
	NextElem(l,1,e);
	printf("next-l[1] %d\n",e);

	GetElem(l,1,e);
	printf("L[1]=%d\n",e);
    ListDelete(l,1,e);
    printf("delele l[1]\n");
	GetElem(l,1,e);
	printf("after delete l1,L[1]=%d\n",e);
	if(ListTraverse(l,visit))
	printf("data=2 is find\n");
	e=2;
	printf("data=2 is on %d\n",LocateElem(l,e,cmp));
	Clear(l);
	printf("after clear,L[1].data=%d\n",l[0]);
	DestoryList(l);
	printf("Destory sucess\n");
	return 0;
}
