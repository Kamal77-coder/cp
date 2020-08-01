#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code'
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,k ; 
	    cin>>n>>k;
	    
	    bool check = (n>>k)&1;  //(n & (1<<k)l
	    check ? cout<<"Yes\n" : cout<<"No\n";
	}
	return 0;
}

//left and right shift
#include <bits/stdc++.h>
using namespace std;



int main()
{
    
    int k = 100;
    
    cout<<(k<<4)<<endl;  //  100*2^4 =1600
                         //100<<i : i 0s added in binary representation of 100 on rightmost side
    cout<<(k>>4);   //6  100/(2^4) = 6
                      //100 = (1100100) , 6 = (110)
	
	              //100>>i  : rightmost i bits are gone and rest bits are shifted accordingly
}
//power of two : leetcode
class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        /*int count = 0; 
        //fails for -2147483648
        for(int i=31 ;i>= 0 ;i--)
        {
               if( n & (1<<i))             // if((n>>i) & 1)
                count++;
        }
        return count == 1;*/
        
        return n>0 && (n & (n-1)) == 0;
    }
};
//power of 2 gfg :
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	
	while(t--)
	{
	    long long int n;
	    cin>>n;
	    //since n can be as long as 10^18
	    int count = 0;
	    for(int i = 31 ;i>=0 ;i--)
	    {
	        if( n & (1<<i))
	          count++;
	    }
	    
	    count == 1? cout<<"YES\n" : cout<<"NO\n";
	}
	return 0;
}
//gfg :counting bits

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n; 
	    cin>>n;
	    
	    int count = 0;
	    
	    for(int i=31 ;i>= 0 ;i--)
	    {
	         if((n>>i) & 1)       //if( n & (1<<i)) also worked
	          count++;
	    }
	    cout<<count<<endl;
	}
	return 0;
}

int KthOFFToON(int num, int k) // on -> on and off -> on
{
    int mask = (1 << k);
    return (num | mask);
}

int KthOnToOFF(int num, int k) // on -> oFF and off -> off
{
    int mask = (~(1 << k));
    return (num & mask);
} 
//updating the ith bit
#include <iostream>
using namespace std;

void update(int &n ,int k, int b)
{
    int mask = ~(1<<k);

    n = (n & mask);

    mask = (b<<k);

    n = n | mask;
}
int main() {
    

    int n = 125;

    cout<<"before\n :";
    for(int i= 31;i>=0 ;i--)
    {
        bool check =  (n & 1<<i);
        cout<<check<<" ";
    }
    cout<<"\n";

    update( n, 0,0);
     cout<<"after\n :";
    for(int i= 31;i>=0 ;i--)
    {
        bool check =  (n & 1<<i);
        cout<<check<<" ";
    }

   return 0;
}

