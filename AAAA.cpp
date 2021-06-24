#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll MOD = 1e9 + 7;

void solve()
{ 
  int m,n,k;
  cin>>m>>n>>k;
  pair<int,int> row[m+1];
  pair<int,int> col[n+1];
  col[0]={0,0};
  row[0]={0,0};
  unordered_map<int,int> diag;
  for(int i=1;i<=m;i++)
    row[i]={0,i};
  for(int i=1;i<=n;i++)
    col[i]={0,i};
  for(int i=0;i<k;i++)
  {
    int r,c;
    cin>>r>>c;
    if(r==c)
    { 

      diag[r]=1;
    }
    row[r].first=row[r].first+1;
    col[c].first=col[c].first+1;
  }
  sort(row,row+(m+1),greater<pair<int,int>>());
  
  sort(col,col+(n+1),greater<pair<int,int>>());
  int h1=row[0].first;
  int h2=row[1].first;
  int s1=col[0].first;
  int s2=col[1].first;
  int val1=h1+s1+((diag[row[0].second])?-1:0);

  for(int i=1;i<=min(n,m);i++)
  { 
    int h=row[i].first;
    int s=col[i].first;
    int a=row[i].second;
    int b=row[i].second;
    if(a!=b and (h+s)==(h1+s1))
    {
      cout<<h+s<<endl;
      return;
    }
    if(a!=b)
    {cout<<max({h1+s1+((diag[row[0].second])?-1:0),h1+s2,h2+s1})<<endl;
    return;
    }
  }
  cout<<val1<<endl;
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
  // cin >> t;
  while (t-- )
  {
    solve();
  }
  return 0;

}
