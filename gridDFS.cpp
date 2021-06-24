#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
pair<int,int> s,e;
bool f=false;
bool isvalid(int x,int y)
{
    if(x>=0 and x<=n-1 and y>=0 and y<=n-1)
    return true;
    return false;
}
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int dxx[8]={1,0,-1,0,1,1,-1,-1};
int dyy[8]={0,1,0,-1,1,-1,-1,1};
void dfs(int i,int j,vector<vector<int>> &visited,vector<vector<int>> &m)
{
    visited[i][j]=1;
    if(m[i][j]==2)
    {
        bool f=true;
        return;
    }
    if(m[i][j]==0)
    return;
   for(int k=0;k<4;k++)
    {
        if(isvalid(i+dx[k],j+dy[k]))
        {
            if(!visited[i+dx[k]][j+dy[k]])
            {
                dfs(i+dx[k],j+dy[k],visited,m);
            }
        }
    }
    return ;
}
int main() {
	//code
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("otpt.txt","w",stdout);
    #endif
	int t;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    vector<vector<int>> m(n, vector<int> (n,0));
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cin>>m[i][j];
                cout<<m[i][j]<<" ";
	            if(m[i][j]==1)
	            s=make_pair(i,j);
	            if(m[i][j]==2)
	            e=make_pair(i,j);
	        }
            cout<<endl;
	    }
	    vector<vector<int>> visited(n, vector<int> (n,0));
	    dfs(s.first,s.second,visited,m);
	    if(f)
	    {
	        cout<<1<<endl;
	        f=false;
	    }
	    else
	    cout<<0<<endl;
	}
	return 0;
}
//connected components in matrix
#include<bits/stdc++.h>
using namespace std;
 
int N , M;
int ar[1001][1001];
bool vis[1001][1001];
 
 
bool isValid(int x , int y)
{
    if(x < 1 || x > N || y < 1 || y > M)
    return false;
 
    if(vis[x][y] == true || ar[x][y] == 0)
    return false;
 
    return true;
}
 
int dx[4] = {-1 , 0 , 1 , 0};
int dy[4] = {0 , 1 , 0 , -1};
 
void dfs(int x ,int y)
{
    vis[x][y] = 1;
 
    for(int i=0;i<4;i++)
    if(isValid(x + dx[i] , y + dy[i]))
    dfs(x + dx[i] , y + dy[i]);
}
 
 
int main()
{
    cin>>N>>M;
 
    for(int i=1;i<=N;i++)
    for(int j=1;j<=M;j++)
    cin>>ar[i][j];
 
    int cc = 0;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        if(vis[i][j] == 0 && ar[i][j] == 1)
        dfs(i , j) ,cc++;
    }
 
    cout<<"CC = "<<cc<<endl;
}
