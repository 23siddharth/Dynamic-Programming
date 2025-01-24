#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vt vector<ll>
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define pll pair<ll,ll>
#define vpl vector<pair<ll,ll>>
#define cno cout<<"NO"<<endl
#define cyes cout<<"YES"<<endl
#define ct(t) cout<<t<<endl
#define forn for(ll i=0;i<n;++i)
#define forx(i,x) for(ll i=0;i<x;++i)
#define fory(i,x,y) for(ll i=x;i<=y;++i)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define inp(a,n) for(ll i=0;i<n;++i) cin>>a[i];
#define out(a,n) for(ll i=0;i<n;++i) {cout<<a[i]<<" ";} cout<<endl;
#define INF 1000000000
#define M (ll)(1e9+7)

void solve()
{
    ll n;
    cin >> n;
    string s[2];
    cin >> s[0];
    cin >> s[1];
    // Using 1 based indexing...did not plan to but I had to declare the first dp as 1 which would otherwise be dp[-1][0]=1

    s[0]=" "+s[0];
    s[1]=" "+s[1];
/*
Benefits of Using 1 based Indexing
    it got rid of all if conditions checking i>0
    was able to declare first value in dp as 1
*/
    vector<vector<ll>>dp (n+1, vt(3,0));
    dp[0][0]=1;
    for(int i=1; i<=n; i++)
    {
        if(s[0][i]=='.' && s[1][i]=='.')
        {
            dp[i][0]+=dp[i-1][0];
            if(i>1 && s[0][i-1]=='.' && s[1][i-1]=='.')
                dp[i][0]+=dp[i-2][0];
            dp[i][1]+=dp[i-1][2];
            dp[i][2]+=dp[i-1][1];

        }
        if(s[0][i]=='.' && s[1][i]=='#')
        {
            dp[i][2]+=dp[i-1][0];
            dp[i][0]+=dp[i-1][2];
        }

        if(s[0][i]=='#' && s[1][i]=='.')
        {
            dp[i][1]+=dp[i-1][0];
            dp[i][0]+=dp[i-1][1];
        }

        if(s[0][i]=='#' && s[1][i]=='#')
            dp[i][0]+=dp[i-1][0];

/*
        storing all possible no of ways gave
        overflow even in ll. So setting all higher
        values equal to 2
*/
        for(int j=0; j<3; j++)
            dp[i][j]=min(2ll, dp[i][j]);
    }
    // ct(dp[n][0]);
    // forx(j,3)
    // forx(i, n+1)
    //     cout<<dp[i][j]<<" \n"[i==n];

    ll ans=dp[n][0];
    if(ans>1)
        ct("Multiple");
    else if(ans==1)
        ct("Unique");
    else
        ct("None");
}




int main()
{
    ll tc=1;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
}


