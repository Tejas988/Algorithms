#include <bits/stdc++.h>
using namespace std;

vector<int> ar[1001];
const int maxN=10;
int level[1001],LCA[1001][maxN+1];

//calculating 0th parent of each node
void dfs(int cur,int lvl,int par)
{
	level[node]=lvl;
	LCA[node][0]=par;
	for(int child:ar[cur])
	{
		if(child!=par)
		{
			dfs(child,lvl+1,cur);
		}
	}
}

int getLCA(int a,int b)
{
	if(level[a]<level[b])
		swap(a,b);
	int d=level[b]-level[a];//calculating difference 
	int i=0;
	while(d)
    {
        if(d&1)
        {
            b=LCA[b][i];
        }
        d>>=1;
        i+=1;
    }
	if(a==b)
		return a;
	for(int i=maxN;i>=0;i--)
	{
		if(LCA[a][i]!=LCA[b][i] and LCA[a][i]!=-1)
		{
			a=LCA[a][i];
			b=LCA[b][i];
		}
	}
	return LCA[a][0];
}

void init(int n)
{
	dfs(1,0,-1);
	for(int i=1;i<=maxN;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(LCA[j][i-1]!=-1)//if lca of n-1th power of 2 exists
			{	
				int parent=LCA[j][i-1];
				LCA[j][i]=LCA[parent][i-1];
			}
		}
	}
}

int main()
{	
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		ar[a].push_back(b);
		ar[b].push_back(a);
	}
	memset(LCA,-1,sizeof(LCA));
	init(n);//initialise lca array
	return 0;
}