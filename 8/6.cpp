#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
int tree[10];
int a=9999;
int b=9999;
int search(int n,int t)
{
  if(tree[t]==n)
      return t;
  else if(tree[t]>n&&(2*t+1)<10&&tree[t]!=0)
      return search(n,2*t+1);
  else if((2*t+2)<10&&tree[t]!=0)
      return search(n,2*t+2);

    if(abs(n-tree[t])<a)
        a=tree[t];
    else if(abs(n-tree[t])<b)
        b=tree[t];


    return 0;
}
int main()
{
 tree[0]=45;
    tree[1]=12;
    tree[2]=53;
    tree[3]=3;
    tree[4]=37;
    tree[6]=100;
    tree[9]=24;

   int temp=search(37,0);
        printf("%d\n",temp);

    temp=search(38,0);
    if(temp==0);
       printf("%d %d",search(a,0),search(b,0));

}