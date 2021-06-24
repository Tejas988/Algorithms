#include<bits/stdc++.h>
using namespace std;

//works on directed graph with no negative cycle
//can detect negative cycle
//works on unweighted graph with no negative edge coz unweighted edge eg A - B can be converted
//to A->B and B->A
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("opts.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> adj[n];
	vector<array<int, 3>> edges;
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		edges.push_back({u, v, w});
	}
	int dist[n];
	for (int i = 0; i < n; i++)
	{
		dist[i] = INT_MAX;
	}
	dist[0] = 0; //distance of src is 0
	for (int i = 0; i < n - 1; i++)
	{
		for (auto x : edges)
		{
			if (dist[x[0]] + x[2] < dist[x[1]])
			{
				dist[x[1]] = dist[x[0]] + x[2];
			}
		}
	}
	bool f = false;
	for (auto x : edges)
	{
		if (dist[x[0]] + x[2] < dist[x[1]])
		{
			f = true;
			dist[x[1]] = dist[x[0]] + x[2];
		}
	}
	if (f)
	{
		cout << "Negative cycle detected" << endl;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			cout << "Distance from " << 0 << " to " << i << " is : " << dist[i] << endl;
		}
	}

}