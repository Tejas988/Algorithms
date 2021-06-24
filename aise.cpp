#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll MOD = 1e9 + 7;

void solve()
{ 
  ll n;
  cin>>n;
  vector<ll> v(n);
  for(ll i=0;i<n;i++)
    cin>>v[i];
  vector<vector<ll>> subs;
  for(ll i=0;i<n;i++)
  { 
    ll sum=0;
    vector<ll> d;
    for(ll j=i;j<n;j++)
    {
      sum+=v[j];
      d.push_back(v[j]);
      subs.push_back(d);
    }
    
  }
  ll ans=-1e13;
  for(auto &pat:subs)
  {
    ll M=pat.size();
    ll sum=0;
    for(auto x:pat)
    {
      // cout<<x<<" ";
      sum+=x;
    }
    // cout<<sum<<endl;
    ll lps[M]; 
    ll len = 0;
    ll i = 1;
    lps[0] = 0; 
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else 
        {
             
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else 
            {
                lps[i] = len;
                i++;
            }
        }
    }
    i = 0;
    ll j=0;
    ll res = 0;
    ll next_i = 0;
    while (i < n)
    {
        if (pat[j] == v[i])
        {
            j++;
            i++;
        }
        if (j == M)
        {
            j = lps[j - 1];
            res++;
        } 
        else if (i < n && pat[j] != v[i])
        {

            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    // cout<<sum<<" "<<res<<endl;
    ans=max(ans,res*sum);
  }
  cout<<ans<<endl;
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