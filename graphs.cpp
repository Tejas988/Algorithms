#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//array of list of size v here index represent the parent node

class Graphs
{
	 int V;
	 list<int> *l;
public:
	Graphs(int V)
	{
		this->V=V;
		l = new list<int> [V];//array of lists
	}
	void addEdge(int x,int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void printAdjList()
	{
		//iterate over all vertices
		for(int i=0;i<V;i++)
		{	cout<<"parent is "<<i<<"->";
			for(auto nbr:l[i])
			{
				cout<<nbr<<" ";
			}
			cout<<"\n";
		}
	}

	void dfs_helper(int src,vector<bool> &visited,int &cnt)
	{	
		visited[src]=true;
		int a=0;
		for(auto nbr:l[src])
		{
			if(!visited[nbr])
			{	
				cnt++;
				dfs_helper(nbr,visited,cnt);
			}
		}
		return;
	}


	int dfs()
	{
		vector<bool> visited;
		vector<int> components;
		for(int i=0;i<V;i++)
		{
			if(!visited[i])
			{	int cnt=1;
				 dfs_helper(i,visited,cnt);	
				 components.push_back(cnt);
			}	
		}
		int total=components.size();
		int ans=(total*(total-1))/2;
		int a=0;
		for(auto x:components)
		{
			a+=x*(x-1)/2;
		}
		// cout<<ans;
		return ans-a;
	}

	bool cycle_helper(int node,bool *visited,int parent)
	{
		visited[node]=true;
		for(auto nbr:l[node])
		{
			if(!visited[nbr])
			{
				bool cycle_exist=cycle_helper(nbr,visited,node);
				if(cycle_exist)
					return true;
			}
			else if(nbr!=parent)
				return true;
		}
		return false;
	}
	bool contain_cycle()
	{
		bool *visited = new bool[V];
		for(int i=0;i<V;i++)
			visited[i]=false;
		return cycle_helper(0,visited,-1);
	}
	bool bipertite_helper(int node,vector<int> &visited,int parent,int clr)
	{
		visited[node]=clr;
		for(auto nbr:l[node])
		{
			if(!visited[nbr])
			{
				bool isbipertite=bipertite_helper(nbr,visited,node,3-clr);
				if(!isbipertite)
				return false;
			}
			else if(nbr!=parent && clr==visited[nbr])
				return false;
		}
		return true;

	}
	bool bipartite(int node,vector<int> &visited,int clr,int parent)
	{
		visited[node]=clr;
		for(auto nbr:l[node])
		{
			if(!visited[nbr])
			{
				bool isBip=bipartite(nbr,visited,3-clr,node);
				if(!isBip)
					return false;
			}
			else if(nbr!=parent and visited[nbr]==clr)
				return false;
		}
		return true;
	}

	bool isBipertite()
	{

		vector<int> color(V,0);
		return bipertite_helper(0,color,-1,1);//node,colored ary,parent,clr
	}

};



int main()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif
	Graphs g(6);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,0);
	if(g.isBipertite())
		cout<<"Bipertite";
	else
		cout<<"Not Bipertite";
	return 0;
}