#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;


ll sum[200001];
vector<ll> adj[200001];
ll ans[200001];
ll subnodes[200001];
ll n;


void calc_sum(ll src,ll par)
{   
    ll maxH=0;
    bool leaf=true;
    ll cnt=1;
    for(auto x:adj[src])
    {
        if(x!=par)
        {
            leaf=false;
            calc_sum(x,src);
            cnt+=subnodes[x];
            maxH+=sum[x]+subnodes[x];
        }
    }
    if(leaf)
    {   subnodes[src]=1;
        sum[src]=0;
        return;
    }
    subnodes[src]=cnt;
    sum[src]=maxH;
    return;
}

void calc_maxDist(ll src,ll par,ll partial_ans)
{
    ans[src]=sum[src]+partial_ans+(n-subnodes[src]);
    for(auto x:adj[src])
    {
        if(x!=par)
        {
            calc_maxDist(x,src,ans[src]-sum[x]-subnodes[x]);
        }
    }
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("otpt.txt", "w", stdout);
#endif

    ll t = 1;
    // cin >> t;
    while (t--)
    {   
       memset(adj,0,sizeof adj);
       memset(ans,0,sizeof ans);
       memset(sum,0,sizeof sum); 
       memset(subnodes,0,sizeof subnodes); 
       n=0;
       cin>>n;
       for(ll i=0;i<n-1;i++)
       {
            ll a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
       }
       calc_sum(1,0);
       
       calc_maxDist(1,0,0);
       for(ll i=1;i<=n;i++)
       {
        cout<<ans[i]<<" ";
       }
       cout<<endl;
    }
    return 0;
}



