#include <iostream>
#include <malloc.h>
using namespace std;
class SElemType{
public:
    SElemType *next;
    int data;
    SElemType(int e)
    {
        data=e;
    }
    SElemType()
    {}
};
typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

bool InitStack(SqStack &S){
    S.base=(SElemType*)malloc(10* sizeof(SElemType));
    if(!S.base)
        return true;
    S.top=S.base;
    S.stacksize=10;
    return true;
}

bool DestroyStack(SqStack &S){
    free(S.base);
    return true;
}

bool ClearStack(SqStack &S){
    S.top=S.base;
    return true;

}

bool StackEmpty(SqStack &S){
    if(S.base==S.top)
        return true;
    else
        return false;
}

int StackLength(SqStack &S){
    return S.top-S.base;
}

bool GetTop(SqStack S,SElemType &e){
    if(S.top==S.base)
        return false;
    e=*(S.top);
    return true;
}

bool Push(SqStack &S,SElemType e)
{
    if(S.top-S.base>=(S.stacksize-1))
    {
        S.base=(SElemType *)realloc(S.base,(S.stacksize+10)* sizeof(SElemType));
        if(!S.base)
            return false;
        S.top=S.base+S.stacksize-1;
    }
    S.top++;
    *S.top=e;
}

bool Pop(SqStack &S,SElemType &e)
{
    if(S.top==S.base)
        return false;
    e=*S.top;
    S.top--;
    return true;
}

bool  StackTraverse(SqStack S,bool (*visit)(int))
{
 SElemType *temp=S.base->next;
   while(temp>S.top)
   {
       if(visit(temp->data))
           return true;
   }
    return false;

}

bool visit(int e)
{
    if(e==2)
        return true;
    else
        return false;
}
int main()
{
    SqStack S;
    if(InitStack(S))
        printf("Init\n");
    for(int k=0;k<3;k++) {
        SElemType e=SElemType(k);
        e.next=S.top;
        Push(S,e);
    }
    printf("StackLength=%d\n",StackLength(S));
    if(!StackEmpty(S))
    printf("not Empty\n");
    SElemType e;
    GetTop(S,e);
    printf("e.data=%d\n",e.data);
    e.data=3;
    Push(S,e);
    printf("push(S,e),StackLength=%d\n",StackLength(S));
    Pop(S,e);
    printf("e=pop(S),e.data=%d\n",e.data);
    if(StackTraverse(S,visit));
    printf("data=2 exist\n");
    ClearStack(S);
    if(S.top==S.base)
        printf("clear!\n");
    if(DestroyStack(S))
        printf("Destroy\n");

}
