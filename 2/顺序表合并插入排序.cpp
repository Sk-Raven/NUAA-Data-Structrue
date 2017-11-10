#include <iostream>
#include <malloc.h>
using namespace std;
int *a,*b;
void insertsort(int unsort[],int length,int k)
{
    int temp;
    for (int i=0;i<length;i++)
    {if (k<*(unsort+i))
        {
            int a =length-1;
            while(a>=i)
            {
                *(unsort+a+1)=*(unsort+a);
                a--;
            }
            *(unsort+i)=k;
            break;
        }
    }
}
int main()
{
    a=(int*)malloc(5*sizeof(int));
    b=(int*)malloc(3*sizeof(int));
    for(int k=0;k<5;k++)
    {
        *(a+k)=2*k;
    }
    b[0]=1;b[1]=3;b[2]=5;
    a=(int*)realloc(a,8*sizeof(int));
    printf("a:");
    for(int k=0;k<8;k++)
        printf("%d ",a[k]);
        
    printf("\nb:1 3 5");
     for(int i=0;i<3;i++)
     insertsort(a,5+i,b[i]);
     printf("\nsort\n");
    for(int k=0;k<8;k++)
        printf("%d ",a[k]);
        free(a);
        free(b);

}
