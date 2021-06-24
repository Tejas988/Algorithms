#include <bits/stdc++.h>
using namespace std;



vector<int> adj[1000];
int in[1000],low[1000],vis[1000];
set<int> ss;

int timer=0;
void find_articpts(int cur,int par)
{
	vis[cur]=1;
	in[cur]=timer;
	low[cur]=timer;
	timer++;
	int children=0;
	for(auto nbr:adj[cur])
	{
		if(nbr==par)
			continue;
		if(vis[nbr])
		{
			//back edge
			low[cur]=min(low[cur],in[nbr]);
		}
		else
		{
			dfs(nbr,cur);
			if(low[nbr]>=in[cur] and par!=-1)
			{
				//bridge
				ss.insert(cur);
				cout<<nbr<<"-->"<<cur<<" this is a bridge\n";
			}
			children++;
			low[cur]=min(low[cur],low[nbr]);
		}
	}
	if(children>1 and par==-1)
	{	
		//parent should have more than 1 child for it being an articulation point
		ss.insert(cur);
	}
}
vector<int> adj[100001];
vector<vector<int>> ans;
int discovery[100001];
int low[100001];
int timer=0;
    
void find_bridges(int src,int par)
{
    discovery[src]=timer;
    low[src]=timer;
    timer+=1;
    for(auto x:adj[src])
    {
        if(x==par)
            continue;
        if(discovery[x]!=-1)
        {
            //backedge
            low[src]=min(low[src],discovery[x]);
        }
        else
        {
            dfs(x,src);
            if(low[x]>discovery[src])
            {
                ans.push_back({src,x});
            }
            low[src]=min(low[src],low[x]);
        }
    }
    return;
}
int main()
{	
	int n,m;
	cin>>n>>m;
	while(m--)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		dfs(1,-1);
		cout<<ss.size()<<endl;
	}
	return 0;
}