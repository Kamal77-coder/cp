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
 
//leetcode 307: range query mutable

class NumArray {
public:
    vector<int>st;
    int n;
    vector<int>v;
    NumArray(vector<int>& nums) {
        v = nums;
         n = nums.size();
        st.resize(nums.size()*4+1,0);
         build(1,0,n-1);
    }
    
    int build(int si ,int ss,int se )
    {
        if(ss>se)
            return 0;
        if(ss == se)
             return st[si] = v[ss];
        
        int mid = (ss+se)/2;
        
        int lc = build(2*si,ss,mid);
        int rc = build(2*si+1,mid+1,se);
        
        return st[si] = st[2*si] + st[2*si+1];
    }
    //in this version we handle invalid recursive calls in base case
    int update2(int si,int ss ,int se , int i,int val)
    {
        
        if(ss>i || se<i)return 0;
        
       if(ss == se)
           return st[si] = val;
        
        int lc=0,rc=0;
        int mid = (ss+se)/2;
        
            lc = update2(2*si,ss,mid,i,val);
            rc = update2(2*si+1,mid+1,se,i,val);
        
        return st[si] = st[2*si] + st[2*si+1];
    }
    
   //2nd type of update
//in this version we don't make the invalid recursive callls
    /*int update2(int si,int ss ,int se , int i,int val)
    {
       if(ss == se)
           return st[si] = val;
        int lc=0,rc=0;
        int mid = (ss+se)/2;
        if(i<=mid)
            lc = update2(2*si,ss,mid,i,val);
        else
            rc = update2(2*si+1,mid+1,se,i,val);
        
        return st[si] = st[2*si]+st[2*si+1];
    }*/
    void update(int i, int val) {
        
        v[i]=val;
        update2(1,0,n-1,i,val) ;
    }
    
    int query(int si ,int ss,int se ,int l,int r)
    {
        
        if(ss>r || se<l)
            return 0;
        
        if(ss >= l && se <= r)
            return st[si];
        
        int mid= (ss+se)/2;
        
        int lc = query(2*si,ss,mid,l,r);
        
        int rc =  query(2*si+1,mid+1,se,l,r);
        
        st[si] = st[2*si] + st[2*si+1];
        
        return lc+rc;  //this was the error in earlier cases 
                      // while returning answer to query return the answer of
                     // left and right child.
    }
    
    int sumRange(int i, int j) {
        
        return query(1,0,n-1,i,j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */



//================help ashu hackerearth problem===============

//finding the number of odd and even numbers in a range ========
#include <bits/stdc++.h>

using namespace std;

vector<int>st(400004,0);

void build(int si ,int ss,int se,vector<int>&v)
{
	if(ss == se)
	{
		 if(v[ss]&1)
		   st[si] = 1;
		  else
		  st[si] = 0;
		  return;
	}

	int mid = (ss+se)/2;
	build(2*si,ss,mid,v);
	build(2*si+1,mid+1,se,v);

	st[si] = st[2*si] + st[2*si+1];
}

void update(int si,int ss,int se,int idx,vector<int>&v)
{
	if(ss == se)
	{
		 if(v[ss]&1)
		   st[si] = 1;
		  else
		  st[si] = 0;
		  return;
	}

	int mid = (ss+se)/2;

	if(idx<= mid)
	  update(2*si,ss,mid,idx,v);
	
	else
	  update(2*si+1,mid+1,se,idx,v);
	
	st[si] = st[si*2]+st[2*si+1];
}

int query(int si,int ss,int se,int qs,int qe)
{
	if(ss>qe || qs>se)
	  return 0;
	
	if(qs<=ss && qe>= se)
	 return st[si];
	
	int mid = (ss+se)/2;
	int l = query(2*si ,ss,mid,qs,qe);

	int r = query(2*si+1,mid+1,se,qs,qe);

	return l+r;
}
int main() {
	int n;
	cin >> n;										
			
	vector<int>v(n,0);
	for(int i=0;i<n ;i++)
	{
		cin>>v[i];

	}
	build(1,0,n-1,v);
	int q;
	cin>>q;

	while(q--)
	{
        int t,a,b;

		cin>>t>>a>>b;

		if(t == 0)
		{
			a--;
			v[a] = b;
			update(1 ,0,n-1,a,v);

		}

		if(t == 2)
		{
			a--;   //1 based indexing
			b--;
			int ans = query(1,0,n-1,a,b);
			cout<<ans<<endl;
		}
        
		if(t == 1)
		{
			a--;b--;//1 based indexing
			int ans = query(1,0,n-1,a,b);
			int ele = b-a+1;
			 
			cout<<(ele-ans)<<endl;
		}
	}
	return 0;
}

