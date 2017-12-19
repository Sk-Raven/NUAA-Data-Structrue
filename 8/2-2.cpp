#include <iostream>
using namespace std;
int main()
{   int n[100];
    for(int k=0;k<100;k++)
        n[k]=100-k;

    for(int k=0;k<100;k++)
    {   int max =0;
        int temp;
        for (int l = 0; l < 100 - k; l++)
        {
            if(n[l]>max)
            {
                max=n[l];
                temp=l;
            }
        }
        swap(n[100-k],n[temp]);
    }
    for(int k=0;k<100;k++)
        printf("%d ",n[k]);
}