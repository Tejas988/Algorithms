#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll MOD = 1e9 + 7;
ll dp[501][501][11];
ll v[501][501];
ll h[501][501];
ll n,m,k;

bool isvalid(ll i,ll j)
{
  if(i>=0 and i<n and j>=0 and j<m)
    return true;
  return false;
}


ll dfs(ll i,ll j,ll c)
{
  if(c==0)
    return 0;
  if(dp[i][j][c]!=-1)
  {     
   
    return dp[i][j][c];
  }
  //up
  ll u=1e9;
  ll d=1e9;
  ll l=1e9;
  ll r=1e9;
  if(isvalid(i-1,j))
  {
    u=v[i-1][j]+dfs(i-1,j,c-1);
  }
  if(isvalid(i+1,j))
  {
    d=v[i][j]+dfs(i+1,j,c-1);
  }
  if(isvalid(i,j+1))
  {
    r=h[i][j]+dfs(i,j+1,c-1);
  }
  if(isvalid(i,j-1))
  {
    l=h[i][j-1]+dfs(i,j-1,c-1);
  }
  int x=min({u,d,l,r});
  if(x==0)
  {
    // cout<<i<<" "<<j<<" "<<c<<endl;
  }
  return dp[i][j][c]=x;
}


void solve()
{ 
  
  cin>>n>>m>>k;
  memset(dp,-1,sizeof dp);
  for(ll i=0;i<=n;i++)
  {
    for(ll j=0;j<=n;j++)
    {
      v[i][j]=0;
      h[i][j]=0;
     
    }
  }

  for(ll i=0;i<n;i++)
  {
    for(ll j=0;j<m-1;j++)
    { 
      cin>>h[i][j];
    }
  }
  for(ll i=0;i<n-1;i++)
  {
    for(ll j=0;j<m;j++)
    {
      cin>>v[i][j];
    }
  }
  for(ll i=0;i<n;i++)
  {
    for(ll j=0;j<m;j++)
    {
      if(k&1)
      {
        cout<<-1<<" ";
      }
      else
      { 
        // cout<<k<<" ";
        
        cout<<2LL*dfs(i,j,k/2)<<" ";
      }
    }
    cout<<endl;
  }
  return;
}





signed main()
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("o.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 1;
  // cin >> t;
// init();
  for (ll i = 1; i <= t; i++)
  {
    solve();
  }
  return 0;
}