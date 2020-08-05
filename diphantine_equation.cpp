#include<bits/stdc++.h>

using namespace std;

int x,y;
void extend_euclid(int a,int b)
{
    if(b == 0)
    {

        x = 1, y= 0;

       // cout<<__gcd(a,b)<<" ="<<a<<"*"<<x<<"+"<<b<<"*"<<y<<endl;
        return ;
    }
    int x1,y1;
    
    extend_euclid(b ,a%b) ;
    x1 = y;
    y1 = x - (a/b)*y;

    x = x1;
    y = y1;
   // cout<<"__gcd(a,b) = "<<__gcd(a,b)<<" ="<<a<<"*"<<x<<" + "<<b<<"*"<<y<<endl;
}

void set1()
{
     extend_euclid( 70 , 50);
}

int main()
{
    set1();
}
