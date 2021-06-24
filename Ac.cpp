#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll MOD = 1e9 + 7;

ll fastExpo(int a,int n)
{ 
  if(n==0)
    return 1;//base case
  ll subproblem = fastExpo(a,n/2)%MOD;
  if(n & 1)
  return (((subproblem*subproblem)%MOD)*a)%MOD;
  else
  return (subproblem*subproblem)%MOD; 
}
void solve()
{       
  int n;
  cin>>n;
  vector<int> a(n),vis(n+1,0);
  for(int i=0;i<n;i++)
    cin>>a[i];
  unordered_map<int,int> mp;
  for(int i=0;i<n;i++)
  { 
    int x;  
    cin>>x;
    mp[a[i]]=x;
  }
  int cnt=0;
  for(int i=1;i<=n;i++)
  { 
    int src=i;
    if(vis[src])
      continue;
    cnt+=1;
    // cout<<endl;
    while(mp[src]!=i)
    { 
      // cout<<src<<" -> ";
      vis[src]=1;
      src=mp[src];
    }
    vis[src]=1;
  }
  // cout<<cnt;
  cout<<fastExpo(2,cnt)<<endl;
  return;
}
    
 
 
int main()
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("opts.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 1;
  cin >> t;
  while (t-- )
  {
    solve();
  }
  return 0;
 
}