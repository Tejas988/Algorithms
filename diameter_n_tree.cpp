#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
 
vector<int> adj[200001];
int height[200001];
 
int calc_heights(int src,int par)
{   
    int maxH=0;
    bool leaf=true;
    for(auto x:adj[src])
    {
        if(x!=par)
        {   
            leaf=false;
            maxH=max(maxH,calc_heights(x,src));
        }
    }
    if(leaf)
        return height[src]=0;
    return height[src]=maxH+1;
}
 
int calc_diameter(int src,int par)
{   
    vector<int> child_heights;
    int k=0;
    int isthere=0;
    for(auto x:adj[src])
    {
        if(x!=par)
        {   
            isthere=max(isthere,calc_diameter(x,src));
            child_heights.push_back(height[x]);
            k++;
        }
    }
    sort(child_heights.begin(),child_heights.end());
    if(!k)
    {
        return 0;
    }
    if(child_heights.size()==1)
    {
        return max(isthere,1+child_heights[0]);
    }
    int ans=max(isthere,2+child_heights[k-1]+child_heights[k-2]);
    return ans;
 
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("otpt.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll t = 1;
    // cin >> t;
    while (t--)
    {   
        memset(adj,0,sizeof adj);
        memset(height,0,sizeof height);
        int n;
        cin>>n;
        for(int i=1;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        height[1]=calc_heights(1,-1);
        cout<<calc_diameter(1,-1)<<endl;
    }
    return 0;
}
 
 