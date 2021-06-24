






#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


class DSU
{
	vector<int> par;
	vector<int> rank;
	int total_compo;
public:
	void init(int n)
	{
		par.resize(n);
		rank.resize(n);
		total_compo=n;
		for(int i=0;i<n;i++)
		{	
			par[i]=i;
			rank[i]=1;
		}
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
		if(x_par==y_par)
			return;
		if(rank[x_par]>rank[y_par])
		{
			par[y_par]=x_par;
			rank[x_par]+=rank[y_par];
		}
		else
		{	
			par[x_par]=y_par;
			rank[y_par]+=rank[x_par];
		}
		total_compo--;
	}

};






int main()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	DSU d;
	d.init(6);
	
	return 0;
}