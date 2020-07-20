//mussadi lal and stairs:codechef

#include<bits/stdc++.h>

using namespace std;
using ll = long long;
ll N = 100000;
ll mod = 1000000007;


void solution(){    
    
}

int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    int t, n;
    cin>>t;

    vector<int> dp(N + 1, 0);
    dp[0] = 1; dp[1] = 1; dp[2] = 2;

    for (size_t i = 3; i < N + 1; i++){
        dp[i] = (dp[i - 1] % mod + dp[i - 2] % mod + dp[i - 3] % mod) % mod;
    }
    
    while(t--){
        cin>>n;
        cout<<dp[n]<<"\n";
    }

    return 0;
}
