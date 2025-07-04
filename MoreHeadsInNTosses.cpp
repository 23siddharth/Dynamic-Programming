#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int N=3000;
int n;
double dp[N][N];
double a[N];
double rec(int tossleft, int headleft)
{

    //pruning
    if(headleft>tossleft)
        return 0;
    if(headleft<0)
        return 0;
    //basecase
    if(tossleft==0)
        return 1;

    if(dp[tossleft][headleft]!=-1)
        return dp[tossleft][headleft];

    double p=0;
    //heads
    p+=a[tossleft]*rec(tossleft-1, headleft-1);
    //tails
    p+=(1-a[tossleft])*rec(tossleft-1, headleft);

    return dp[tossleft][headleft]=p;
}
void solve()
{
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++)
            dp[i][j]=-1.0;
    }
    double p=0;
    for(int i=n; i>n/2; i--)
    {
        p+=rec(n, i);
    }
    cout<<(setprecision(12))<<p<<endl;
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin. tie(0); cout.tie(0);

    ll tc=1;
    // cin>>tc;
    
    while(tc--)
    {
        solve();
    }
}
