/* selection of mulltiple rows and multiple columns of matrix and doing suitable operation using bitmasking */

/* atcoder 173 problem c*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int n,m,k;

char a[6][6];
char b[6][6];
void same()
{
    for(int i= 0 ;i<n ;i++)
    {
        for(int j =0 ; j<m ;j++)
         b[i][j] = a[i][j];
    }
}
void set2(int i , int j)
{
    for(int x = 0 ; x < n ; x++)
    {
        if(i & (1<<x))
        {
            for(int y = 0 ; y<m ; y++)
             b[x][y] =  '$';
        }
    }

    for(int p =0 ; p<m ;p++)
    {
        if(j & (1 << p))
        {
            for(int q =0 ; q<n ;q++)
            b[q][p] = '$';
        }
    }
}
bool check()
{
    int p =0 ;
    for(int i =0 ;i<n ;i++)
    {
        for(int j =0 ; j<m ;j++)
        {
            if(b[i][j] == '#')
             p++;
        }
    }
    return p == k ;
}
int main()
{
    
    cin>>n>>m>>k;
    

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ;j++)
        {
            cin>>a[i][j];
        }
    }
    int count =0;
    for(int i = 0 ; i < (1 << n) ; i++)
    {
        for(int j = 0 ; j< (1 << m); j++)
        {
            same();
            set2(i , j);

            if(check())
            {
                count++;
            }
        }
    }
    cout<<count<<endl;
}
