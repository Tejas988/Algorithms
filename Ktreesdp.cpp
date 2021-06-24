#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll MOD = 1e9+7;
ll n,k,d;
vector<vector<ll>> dp(200,vector<ll> (2,-1)); 
ll findPaths(ll pathSum,bool included)
{	

	if(pathSum > n)
		return 0;
	if(pathSum==n && included) 
		return 1;
	if(pathSum==n && !included)
		return 0;
	ll a=(included)?1LL:0LL;
	if(dp[pathSum][a]!=-1)
		return dp[pathSum][a];
	ll total=0LL;
	for(ll i=1;i<=k;i++)
	{
		if(included)
		{
			total+=findPaths(pathSum+i,included);
		}
		else
		{
			if(i>=d)
			{
				total+=findPaths(pathSum+i,true);
				
			}
			else
				total+=findPaths(pathSum+i,included);
		}
	}
	// cout<<total;
	return dp[pathSum][a]=total%MOD;

}
int main()
{	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	cin>>n>>k>>d;
	cout<<findPaths(0,false)<<endl;		
	return 0;
}




