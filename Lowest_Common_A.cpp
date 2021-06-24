#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
ll up[100001][17]; //up[node][i] where i is power of 2
ll lvl[100001];
void dfs(ll src,ll par,vector<ll> adj[],ll l=0)
{   
    lvl[src]=l;
    for(auto x:adj[src])
    {
        if(x!=par)
            dfs(x,src,adj,l+1);
    }
}
void binary_lifting(ll src,ll par,vector<ll> adj[])
{   
    up[src][0]=par;//ancestor at height 2 pow 0 ie 1 is its direct parent
    for(ll i=1;i<17;i++)
    {
        if(up[src][i-1]!=-1)
        {
            up[src][i]=up[up[src][i-1]][i-1]; // 2 pow x-1 + 2 pow x-1 = 2 pow x
            //up[src][i-1] is par at x-1 now the parof(par at x-1) at x-1 will give us par at x
        }
        else
            up[src][i]=-1;
    }
    // when finish building calculate for children
    for(auto x:adj[src])
    {
        if(x!=par)
        {
            binary_lifting(x,src,adj);
        }
    }
    return;
}
//lifting without recusrion
ll lift_node(ll src,ll jumps)
{
    for(ll i=16;i>=0;i--)
    {
        if(jumps==0 or src==-1)
            break;
        ll k = (ll)(log2(jumps)); 
        src=up[src][k];
        jumps=jumps-(1<<k);
    }
    return src;
}
 
//lifting with recusrion
ll lift_node_recurse(ll src,ll jumps)
{
    if(src==-1 or jumps==0)
        return src;
   
   ll k = (ll)(log2(jumps)); 
    // k is leftmost set bit in jumps so we will make jump equal to
    // 2 pow k and reach that ancestor and recurse from there for remaining jump
    return lift_node_recurse(up[src][k],jumps-(1<<k));
}
 
ll LCA(ll a,ll b)
{   
    if(lvl[a]<lvl[b])
        swap(a,b);
    // a is deeper than b so we need to bring it to b's level
    a = lift_node(a,lvl[a]-lvl[b]);
    if(a==b)
        return a;
    for(ll i=16;i>=0;i--)
    {
        if(up[a][i]!=up[b][i])
        {
            // that means they are below the ancestor coz if they are same
            // then that means they went pass their lowest ancestor as they have same height
            a=up[a][i];
            b=up[b][i];
        }
    }
    return lift_node(a,1);
}
 
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("opts.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin >> t;
    while (t--)
    {   
       memset(up,0,sizeof up);
       memset(lvl,0,sizeof lvl);
       ll n,q;
       cin>>n>>q;
       vector<ll> adj[n+1];

       for(ll i=2;i<=n;i++)
       {
            ll a,b;
            cin>>a;
            cin>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
       }
       binary_lifting(1,-1,adj);
       dfs(1,0,adj);
       while(q--)
       {    
 
           ll a,b,c;
           cin>>a>>b>>c;
          ll x=LCA(a,b);
          // cout<<x<<" "<<lvl[x]<<endl;
          ll d1=lvl[a]-lvl[x];
          ll d2=lvl[b]-lvl[x];
          // cout<<a<<" "<<d1<<endl;
          // cout<<b<<" "<<d2<<endl;

          
          if(d1+d2<=c)
            cout<<"YES"<<endl;
            else
            cout<<"NO"<<endl;
       }       
       
    }
    return 0;
}








