#include <bits/stdc++.h>
using namespace std;

//range max segment tree implimentation
vector<int>st(40,-1);

int build(int si,int ss,int se,vector<int>&v)
{
    if(ss>se)
     return INT_MIN;
    if(ss == se)
    {
        return st[si] = v[ss];
    }
    
    int mid = (ss+se)/2;
    
    int lc = build(2*si , ss,mid,v);
    int rc = build(2*si+1,mid+1,se,v);
    
    return st[si] = max(lc,rc);
}

int query(int si,int ss,int se,int l,int r,vector<int>&v)
{
    if(ss>r || se<l) //segment range is outside of query range
      return INT_MIN;
      

    if(ss>= l && se<=r)//segment range is inside the query range
      return st[si];
      
    int mid = (ss+se)/2;
    
    int lc = query(2*si , ss, mid,l,r,v);
    int rc = query(2*si+1 , mid+1,se ,l,r,v);
    
    return st[si]=max(lc,rc);
}
int main() 
{
   vector<int>v = {-3,4,1,2,-1,5,-2,3,8,5};
    
    build(1,0,9,v);
    int t;
    cin>>t;
    
    for(int i=1;i<=t;i++)  //parent idx,segment start,segment end,query start,query end,given vector
     {
         int a ,b;
         cin>>a>>b;
         cout<<query(1,0,9,a,b,v)<<endl;
     }
	return 0;
}
