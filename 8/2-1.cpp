#include <iostream>
using namespace std;
int main()
{   int n[100];
    for(int k=0;k<100;k++)
        n[k]=100-k;

    for(int k=0;k<100;k++)
        for(int l=0;l<100-k;l++)
            if(n[l]>n[l+1])
                swap(n[l],n[l+1]);

    for(int k=0;k<100;k++)
        printf("%d ",n[k]);
}