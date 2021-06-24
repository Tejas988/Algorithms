#include <bits/stdc++.h>
typedef long long ll;
using namespace std;





template<typename T>
class WeightedGraphs
{

	unordered_map<T, list<pair<T, int>>> adj;
public:
	void addEdge(T parent, T child, bool biDir, int weight)
	{
		adj[parent].push_back(make_pair(child, weight));
		if (biDir)
		{
			adj[child].push_back(make_pair(parent, weight));
		}
	}
	void printAdjList()
	{

		for (auto ver : adj)
		{	cout << "parent is " << ver.first << "->";
			for (auto nbr : ver.second)
			{
				cout << nbr.first << "--" << nbr.second << ",";
			}
			cout << "\n";
		}
	}

	void djkstra_SET(T src, int n)
	{
		unordered_map<T, int> distance;
		for (ll i = 0; i < n; i++)
		{
			distance[i] = INT_MAX;
		}
		distance[src] = 0;
		set<pair<int, T>> s;
		s.insert(make_pair(0, src));
		while (!s.empty())
		{
			auto p = *(s.begin());
			T node = p.second;
			int dist = p.first;
			s.erase(s.begin());
			for (auto child : adj[node])
			{
				if (dist + child.second < distance[child.first])
				{

					auto f = s.find({distance[child.first], child.first});
					if (f != s.end())
					{
						s.erase(f);
					}
					s.insert({dist + child.second, child.first});
					distance[child.first] = dist + child.second;
				}
			}
		}
		for (auto x : distance)
		{
			cout << "distance of " << x.first << " is " << x.second << "\n";
		}

	}
	void djkstra_PQ(T src, int  n)
	{
		unordered_map<T, ll> distance;
		unordered_map<T, bool> visited;
		for (ll i = 1; i < n; i++)
		{
			distance[i] = INT_MAX;
			visited[i] = false;
		}
		distance[src] = 0;
		priority_queue< pair<int, T>, vector < pair<int, T>> , greater< pair<int, T>> > pq;
		pq.push(make_pair(0, src));
		while (!pq.empty())
		{
			auto p = pq.top();
			while (visited[p.second])
			{	pq.pop();
				p = pq.top();
			}
			visited[p.second] = 1;
			T node = p.second;
			ll dist = p.first;
			pq.pop();
			for (auto child : adj[node])
			{
				if ((dist + child.second) < distance[child.first])
				{

					pq.push({dist + child.second, child.first});
					distance[child.first] = dist + child.second;
				}
			}
		}
		for (auto x : distance)
		{
			cout << "distance of " << x.first << " is " << x.second << "\n";
		}
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("otpt.txt", "w", stdout);
#endif
	WeightedGraphs<int> g;
	for (int i = 0; i < 12; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		g.addEdge(x, y, 0, w);
	}
	g.djkstra_PQ(6, 8);

	return 0;
}
