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
