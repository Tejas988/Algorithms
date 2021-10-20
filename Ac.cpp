#include <bits/stdc++.h>
typedef long long  ll;
using namespace std;
const ll MOD = 1e9 + 7;


ll check(ll x,vector<array<ll,4>> &v)
{ 
  ll tot=0;
  for(int i=0;i<v.size();i++)
  { 
    
    tot+=min(abs(v[i][0]-x),abs(v[i][2]-x));
  }
  return tot;
}

ll val(ll x,ll y,vector<array<ll,4>> &v)
{ 
  ll tot=0;
  for(int i=0;i<v.size();i++)
  {
    if(x>=v[i][0] and x<=v[i][2] and y>=v[i][1] and y<=v[i][3])
      continue;
    tot+=min(abs(v[i][0]-x),abs(v[i][2]-x));
    tot+=min(abs(v[i][1]-x),abs(v[i][3]-x));
  }
  return tot; 
}

void solve()
{
  vector<array<ll,4>> vp;
  int n;
  cin>>n;
  ll mnx=0;
  ll mny=0;
  for(int i=0;i<n;i++)
  {
    ll x,y;
    cin>>x>>y;
    ll x1,y1;
    cin>>x1>>y1;
    mnx=min({mnx,x1,x});
    mny=min({mny,y,y1});
    vp.push_back({x,y,x1,y1});
  }
  mnx=abs(mnx);
  mny=abs(mny);
  for(int i=0;i<n;i++)
  {
    vp[i][0]+=mnx;
    vp[i][2]+=mnx;
    vp[i][1]+=mny;
    vp[i][3]+=mny;
  }
  ll l=0,r=2e9+1;
  ll xc=0;
  vector<int> xs;
  while(l<=r)
  {
    ll mid=l+(r-l)/2;
    ll a=check(mid-1,vp);
    ll b=check(mid,vp);
    ll c=check(mid+1,vp);
    // cout<<a<<" "<<b<<" "<<c<<" "<<mid<<endl;
    if(b<=a and b<=c)
    { 
      xs.push_back(mid);
    }
    if(a<=b and b<=c)
    {
      r=mid-1;
    }
    else
      l=mid+1;
  }
  // cout<<xc<<" ";
  sort(xs.begin(),xs.end());
  ll i=0,j=0;
  ll ans=2e9+1;
  for(auto x:xs)
  {
    l=0,r=2e9+1;
    ll ys=2e9+1;
    while(l<=r)
    {
      ll mid=l+(r-l)/2;
      ll a=val(x,mid-1,vp);
      ll b=val(x,mid,vp);
      ll c=val(x,mid+1,vp);
      // cout<<a<<" "<<b<<" "<<c<<" "<<mid<<endl;
      if(b<=a and b<=c)
      {   
        if(mid<ys)
        ys=mid;
      }
      if(a<=b and b<=c)
      {
        r=mid-1;
      }
      else
        l=mid+1;
    }
    ll cur=val(x,ys,vp);
    if(cur<ans)
    {  
      ans=cur;
      i=x;
      j=ys;
    }
    
  }
  cout<<i-mnx<<" "<<j-mny<<endl;
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
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    cout<<"Case #"<<i<<": ";
    solve();

  }
  return 0;

}