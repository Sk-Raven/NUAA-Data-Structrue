#include <iostream>
#include <cmath>

using namespace std;
int hashmap[100];
int myhash(int a)
{
    int temp=a%20;
    if(hashmap[temp]!=0)
    {   int k=1;
        while(hashmap[temp+(int)pow(k,2)]!=0)
            k++;

        temp+=(int)pow(k,2);
    }
    return temp;

}

int main()
{
    for(int k=0;k<30;k++)
        hashmap[myhash(k)]=k;

    for(int k=0;k<100;k++)
        if(hashmap[k]!=0)
            printf("%d->%d\n",k,hashmap[k]);
}