#include <iostream>
#include <stack>
using namespace std;
int c[8];
bool check(int a)
{
	 for(int j=0;j<8;j++)
              if(c[j]==a) 
              return false;
              
              
              return true;
}
int main()
{
    stack<int> a;
    int b;
    cin>>b;
    a.push(b);
    c[0]=b;
    bool flag= true;
    int k=1;
   
    for(k;k<=10;k++)
      {
      	 if(a.size()==8)
          break;
          
	      if(k==9) {
          	  k = a.top();
          	  c[a.size()-1]=0;
          	  a.pop();
          	  continue;
            
              
          }
          
          if(!check(k))
          continue;
          
          if(k!=(a.top()-1)&&k!=(a.top()+1)) {
              a.push(k);
              c[a.size()-1]=k;
              k=0;            
              continue;
          }
          
         
          
         

      }
    cout<<endl<<endl;
    for(int j=0;j<8;j++)
    {
    	cout<<a.top()<<endl;
    	a.pop();
	}
}





