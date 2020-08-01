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
    
    cout<<(k>>4);   //6  100/(2^4) = 6
                      //100 = (1100100) , 6 = (110)
}
//
