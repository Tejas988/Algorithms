#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



int indegree[n+1];
memset(indegree,0,sizeof indegree);
indegree[1]=n-1;
vector<int> graph[n+1];
for(int i=2;i<=n;i++)
{
    int x;
    cin>>x;
    indegree[x]+=1;
    graph[i].push_back(x);
}
queue<int> q;
for(int i=1;i<=n;i++)
{
    if(!indegree[i])
    {
        q.push(i);
    }
}
while(!q.empty())
{
    int cur=q.front();
    q.pop();
    for(auto x:graph[cur])
    {
        indegree[x]-=1;
        ans[x]+=1+ans[cur];
        if(!indegree[x])
        {   
            q.push(x);
        }
    }
}


       
template<typename T>
class MyGraph{

	map<T,list<T>> adj;
public:
	void addEdge(T x,T y)
	{
		adj[x].push_back(y);
	}
	void dfs_helper(T src,unordered_map<T,bool> &visited,list<T> &ordering)
	{

		visited[src]=true;
		// cout<<src<<"R";
		for(auto nbr:adj[src])
		{
			if(!visited[nbr])
			{
				dfs_helper(nbr,visited,ordering);
			}
		}
		ordering.push_front(src);
		return;
	}



	void topology()
	{
		unordered_map<T,bool> visited;
		list<T> ordering;
		for(auto node:adj)
		{
			visited[node.first]=false;
		}
		for(auto node:adj)
		{
			if(!visited[node.first])
			{
				dfs_helper(node.first,visited,ordering);
			}
		}
		for(auto node:ordering)
			cout<<node<<" ";
	}



	void topology_bfs()
	{
		unordered_map<T,int> indegree;

		for(auto node:adj)
		{
			indegree[node.first]=0;
		} 
		for(auto node:adj)
		{
			for(auto nbr:node.second)
			{
				indegree[nbr]++;
			}
		}
		queue<T> q;
		for(auto node:adj)
		{
			if(indegree[node.first]==0)
			{
				q.push(node.first);
			}
		}
		while(!q.empty())
		{
			T node = q.front();
			cout<<node<<" ";
			q.pop();
			for(auto nbr:adj[node])
				{
					indegree[nbr]-=1;
					if(!indegree[nbr])
						q.push(nbr);
				}

		}

	}
	
};

int main()
{	
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("otpt.txt","w",stdout);
	#endif
	MyGraph<int> g; 
    g.addEdge(3, 1); 
    g.addEdge(2, 3); 
    g.addEdge(1, 2); 
    g.addEdge(4, 1); 
    g.topology();
	
	return 0;
}