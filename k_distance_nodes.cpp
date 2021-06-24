
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;
vector<int> adj[50001];
int dp[50001][501];
int n,k;
ll ans=0;

void dfs(int src,int par)
{   
    for(auto x:adj[src])
    {
        if(x!=par)
            dfs(x,src);
    }
    dp[src][0]=1;
    for(int i=1;i<=k;i++)
    {
        for(auto x:adj[src])
        {   
            if(x!=par)
            dp[src][i]+=dp[x][i-1];
        }
    }
    return;
}
void solve(int src,int par)
{   
    if(par!=0)
    {   
        for(int i=k;i>=2;i--)
        {
            dp[src][i]+=dp[par][i-1]-dp[src][i-2];
        }
        dp[src][1]=adj[src].size();
        dp[src][0]=1;

    }
    for(auto x:adj[src])
    {   
        if(x!=par)
        solve(x,src);
    }
   
    return;
}   
// 3--> 1 3 5 10 6 
// 4--> 1 3 6 11 4 
// 5--> 1 3 6 11 4 
// 6--> 1 3 6 6 4 
int main(){
    // write your code
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("otpt.txt","w",stdout);
    #endif
    ll t=1;
    //cin>>t;
    memset(dp,0,sizeof dp);
    while(t--)
    {
      cin>>n>>k;
      for(int i=0;i<n-1;i++)
      {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
      }
      dfs(1,0);
      solve(1,0);
      for(int i=1;i<=n;i++)
      { 
     
        ans+=dp[i][k];
     
      }

      cout<<ans/2<<endl;
    }
    return 0;
}




// bool cmp(pair<ll,ll> a,pair<ll,ll> b)
// {
//     if(a.first<b.first)
//         return false;
//     return true;
// }



ll n;
        cin >> n;
        ll neg = 0, pos = 0;
        unordered_map<ll, int> mp;
        vector<vector<ll>> v(n), ps(n), ng(n);
        for (ll i = 0; i < n; i++)
        {
            ll m;
            cin >> m;

            while (m--)
            {
                ll x;
                cin >> x;
                mp[abs(x)] += 1;
                if (x > 0)
                {
                    ps[i].push_back(x);
                }
                else
                    ng[i].push_back(x);
                v[i].push_back(x);
            }

        }
        ll ans = 0,sub=0;
        for (int i = 0; i < n; i++)
        {
            for (auto x : v[i])
            {

                if (x >= 0)
                {
                    if (mp[abs(x)] > 1)
                    {
                        ll a, b;
                        // a is the mckn jas
                        a = ps[i].size() - (upper_bound(ps[i].begin(), ps[i].end(), x) - ps[i].begin());
                        b = ng[i].size() - (upper_bound(ng[i].begin(), ng[i].end(), -x) - ng[i].begin());
                        cout << a << " " << b << " " << x << endl;
                        ans += a + b;
                        sub+=ng[i].size()-b;
                        // cout<<<<" "<<a+b<<" "<<x<<endl;


                    }
                    else
                        ans += ng[i].size();

                }
                else
                {
                    if (mp[abs(x)] > 1)
                    {
                        ll a, b;
                        a = (lower_bound(ps[i].begin(), ps[i].end(), -x) - ps[i].begin());
                        b = (lower_bound(ng[i].begin(), ng[i].end(), x) - ng[i].begin());
                        // ans += b + a;
                        cout << a << " " << b << " " << x << endl;

                        sub+=ps[i].size()-a;
                    }
                    else
                        ans += ps[i].size();

                }

            }
            // cout << ans << endl;

        }
        cout<<ans<<endl;
        ans/=2;
        for (auto x : mp)
        {

            if (x.second > 1)
                ans += 1;
        }
        cout << ans << endl;