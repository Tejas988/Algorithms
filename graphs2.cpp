// hashmap implementation (weighted graph)
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



template<typename T>
class WeightedGraphs
{
	//Adj list
	unordered_map<T,list<pair<T,int>>> adj;
public:
	void addEdge(T parent,T child,bool biDir,int weight)
	{
		adj[parent].push_back(make_pair(child,weight));
		if(biDir)
		{
			adj[child].push_back(make_pair(parent,weight));
		}
	}
	void printAdjList()
	{
		//iterate over all vertices
		for(auto ver:adj)
		{	cout<<"parent is "<<ver.first<<"->";
			for(auto nbr:ver.second)
			{
				cout<<nbr.first<<"--"<<nbr.second<<",";
			}
			cout<<"\n";
		}
	}

	void djkstra_SET(T src,int n)
	{
		unordered_map<T,int> distance;
		unordered_map<>
		for(ll i=0;i<n;i++)
        {
            distance[i]=INT_MAX;
        }
		distance[src]=0;
		set<pair<int,T>> s;
		s.insert(make_pair(0,src));
		while(!s.empty())
		{
			auto p=*(s.begin());
			T node=p.second;
			int dist=p.first;
			s.erase(s.begin());
			for(auto child:adj[node])
			{
				if(dist+child.second<distance[child.first])
				{	
					if(distance[child.first]!=INT_MAX)
					{auto f = s.find({distance[child.first],child.first});
					if(f!=s.end())
					{
						s.erase(f);
					}
				}
					s.insert({dist+child.second,child.first});
					distance[child.first]=dist+child.second;
				}
			}
		}
		for(auto x:distance)
      {
      	cout<<"distance of "<<x.first<<" is "<<x.second<<"\n";
      }

	}
	 void djkstra_PQ(T src,int  n)
   {
      unordered_map<T,ll> distance;
      unordered_map<T,bool> visited;
      for(ll i=1;i<n;i++)
        {
            distance[i]=INT_MAX;
            visited[i]=false;
        }
      distance[src]=0;
      priority_queue< pair<int,T>, vector < pair<int,T>> , greater< pair<int,T>> > pq; 
      pq.push(make_pair(0,src));
      while(!pq.empty())
      {	
         auto p=pq.top();
         while(visited[p.second])
         {	pq.pop();
         	p=pq.top();
         }
         visited[p.second]=1;
         T node=p.second;
         ll dist=p.first;
         pq.pop();
         for(auto child:adj[node])
         {
            if((dist+child.second)<distance[child.first])
            {
               
               pq.push({dist+child.second,child.first});
               distance[child.first]=dist+child.second;
            }
         }
      }
      for(auto x:distance)
      {
      	cout<<"distance of "<<x.first<<" is "<<x.second<<"\n";
      }
   }
};




template<typename T>
class MyGraph{

	map<T,list<T>> adj;
public:
	void addEdge(T x,T y)
	{
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	void bfs(T src)
	{
		unordered_map<T,bool> visited;
		queue<T> q;
		q.push(src);
		visited[src]=true;

		while(!q.empty())
		{
			T node = q.front();
			q.pop();
			cout<<node<<"--";
			for(auto nbr: adj[node])
			{
				if(!visited[nbr])
				{
					q.push(nbr);
					visited[nbr]=true;
				}
			}

		}
	}
	void mybfs(T root)
	{
		unordered_map<T,int> visited;
		queue<T> q;
		q.push(root);
		visited[root]=true;
		int cnt=0;
		while(!q.empty())
		{
		int s=q.size();
		cout<<" "<<cnt++<<"->";
		for(int i=0;i<s;i++)
		{
			T node = q.front();
			q.pop();
			cout<<node<<" ";
			for(auto nbr: adj[node])
			{
				if(!visited[nbr])
				{
					q.push(nbr);
					visited[nbr]=true;
				}
			}

		}
	}
	}
	void shrtPath(T src,T des)//gives shortest dist between two nodes in unweighted graph
	{
		unordered_map<T,int> dist;
		unordered_map<T,T> parent;
		queue<T> q;
		for(auto node: adj)
		{
			dist[node.first]=INT_MAX;
		}
		q.push(src);
		dist[src]=0;
		while(!q.empty())
		{
			T node = q.front();
			q.pop();
			// cout<<node<<"--";
			for(auto nbr: adj[node])
			{
				if(dist[nbr]==INT_MAX)
				{
					q.push(nbr);
					dist[nbr]=dist[node]+1;
					parent[nbr]=node;
				}
			}

		}

		T temp =des;
		while(temp!=src)
		{
			cout<<temp<<"-->";
			temp=parent[temp];
		}
		cout<<src;
	}

	void dfs_helper(T src,unordered_map<T,bool> &visited)
	{
		cout<<src<<" ";
		visited[src]=true;

		for(auto nbr:adj[src])
		{
			if(!visited[nbr])
			{
				dfs_helper(nbr,visited);
			}
		}
		return;
	}



	void dfs(T src)
	{
		unordered_map<T,bool> visited;
		for(auto node:adj)
		{
			visited[node.first]=false;
		}

		dfs_helper(src,visited);
	}


	bool cycle_helper(T node,unordered_map<T,bool> &visited,unordered_map<T,bool> &mstack)
	{
		visited[node]=true;
		mstack[node]=true;

		for(auto nbr:adj[node])
		{
			if(!visited[nbr])
			{
				bool hai_kya=cycle_helper(nbr,visited,mstack);
				if(hai_kya)
					return true;
			}
			else if(mstack[nbr])
			{
				return true;
			}


		}
		mstack[node]=false;
		return false;
	}



	bool contains_cycle_dir()
	{
		unordered_map<T,bool> visited;
		unordered_map<T,bool> mstack;
		for(auto node:adj)
		{
			visited[node.first]=false;
			mstack[node.first]=false;
		}
		return cycle_helper(0,visited,mstack);
	}
		
};
int main()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	WeightedGraphs<int> g;
	g.addEdge(0,1,true,12);
	g.addEdge(1,2,true,22);
	g.addEdge(2,3,true,21);
	g.addEdge(3,4,true,10);
	g.addEdge(4,0,true,9);
	g.djkstra_SET(0,5);

	
	return 0;
}
// distance of 0 is 0
// distance of 4 is 9
// distance of 3 is 19
// distance of 1 is 12
// distance of 2 is 34