#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100];
vector<int> transpose[100];
int n,m;
int vis[101];
stack<int> s;

void dfs(int src)
{
	vis[src]=1;
	for(auto x:adj[src])
	{
		if(vis[x])
			continue;
		dfs(x);
	}
	s.push(src);
	return;
}
void dfs2(int src)
{
	vis[src]=1;
	for(auto x:transpose[src])
	{
		if(vis[x])
			continue;
		dfs2(x);
	}
	cout<<src<<" ";
	return;
}



int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("opts.txt", "w", stdout);
#endif
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		transpose[v].push_back(u);
	}
	for(int i=0;i<n;i++)
	{	
		if(!vis[i])
			dfs(i);
	}
	for(int i=0;i<100;i++)
		vis[i]=0;
	while(!s.empty())
	{
		if(!vis[s.top()])
		{	
			dfs2(s.top());
			cout<<endl;
		}
		s.pop();
	}
	return 0;

}