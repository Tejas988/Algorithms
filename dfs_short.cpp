#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

vector<int> adj[100001];
int vis[100001]={0};
void dfs(int v)
{
    vis[v]=1;
    for(auto x:adj[v])
    {
        if(vis[x]==0)
            dfs(x);
    }
    return;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    ll t=1;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        while(q--)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int c=0;
        for(int i=0;i<n;i++)
        {   
            if(!vis[i])
            {
                dfs(i);
                c++;
            }
        }
        cout<<c<<endl;
    }
    return 0;
}