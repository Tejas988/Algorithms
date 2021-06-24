
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


class DSU
{
	vector<int> par;
	int total_compo;
public:
	void init(int n)
	{
		total_compo=n;
		for(int i=0;i<n;i++)
			par.push_back(i);
	}

	int get_superParent(int child)
	{
		if(child == par[child])
		{
			return child;
		}
		return par[child]=get_superParent(par[child]);//path compression
	}

	void make_union(int x,int y)
	{
		int x_par=get_superParent(x);
		int y_par=get_superParent(y);
		if(x_par!=y_par)
		{
			par[x_par]=y_par;
		}
		total_compo--;
	}

};



bool cmp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b)
{
	if(a.first<b.first)
		return true;
	return false;
}


int main()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n,m,w;
	cin>>n>>m;
	vector<pair<int,pair<int,int>>> edges;
	for(int i=0;i<m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		edges.push_back({w,{x,y}});
	}
	sort(edges.begin(),edges.end(),cmp);
	DSU g;
	g.init(n);
	int ans=0,cnt=0;
	for(int i=0;i<m;i++)
	{
		int x,y,w;
		x=edges[i].second.first;
		y=edges[i].second.second;
		w=edges[i].first;
		//cout<<x<<" "<<y<<" "<<w<<"\n";
		if(g.get_superParent(x)!=g.get_superParent(y))
		{	
			//belong to different parent
			g.make_union(x,y);
			ans+=w;
			cnt++;
			if(cnt==n-1)
				break;
		}
	}
	cout<<ans;
	
	return 0;
}


