#include <iostream>
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int n,m,a,b,c;
vector<int> bfs(vector<ll> *adj,int src)
{
		vector<int> dist;
		queue<int> q;
		for(int i=0;i<=n;i++)
		{
			dist.push_back(INT_MAX);
		}
		q.push(src);
		dist[src]=0;
		while(!q.empty())
		{
			int node = q.front();
			q.pop();
			for(auto nbr: adj[node])
			{
				if(dist[nbr]==INT_MAX)
				{
					q.push(nbr);
					dist[nbr]=dist[node]+1;
				}
			}

		}
		return dist;
}

int main()
{	
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("otpt.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>a>>b>>c;
		vector<ll> p;
		p.push_back(0);
		for(int i=1;i<=m;i++)
		{
			ll x;
			cin>>x;
			p.push_back(x);
		}
		sort(p.begin(),p.end());
		for(int i=1;i<=m;i++)
			p[i]+=p[i-1];
		vector<ll> adj[n+1];
		for(int i=0;i<m;i++)
		{
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		vector<int> da=bfs(adj,a);
		vector<int> db=bfs(adj,b);
		vector<int> dc=bfs(adj,c);
		ll ans=LLONG_MAX;
		for(int i=1;i<=n;i++)
		{
			ll dbv=p[db[i]];
			if(db[i]+da[i]+dc[i]>m)
				continue;
			ll dtv=p[db[i]+da[i]+dc[i]];
			ans=min(ans,dbv+dtv);
		}	
 		cout<<ans<<endl;
	}
}