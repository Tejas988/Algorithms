#include<bits/stdc++.h>
using namespace std;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

int N,M;
bool isValid(int x , int y)
{
    if(x < 1 || x > N || y < 1 || y > M)
    return false;
 
    if(vis[x][y] == true || ar[x][y] == 0)
    return false;
 
    return true;
}

void BFS(int x,int y,vector<vector> &grid)
{
	visited[x][y]=1;
	queue<pair<int,int>> q;
	dist[x][y]=0;
	q.push({x,y});
	while(!q.empty())
	{
		int curX=q.front().first;
		int curY=q.front().second;
		q.pop();
		for(int k=0;k<4;k++)
		{
			int nX=curX+dx[k];
			int nY=curY+dy[k];
			if(isValid(nX,nY))
			{
				if(!visited[nX][nY])
				{
					dist[nX][nY]=dist[curX][curY]+1;
					q.push({nX,nY});
					visited[nX][nY]=1;
				}
			}

		}

	}
}



int main()
{	



	return 0;
}