#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
void solve()
{  ll n;
	cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	 vector<ll> v;
    v.push_back(arr[0]);
    for(ll i=1;i<n-1;i++)
    {
      if((arr[i]>arr[i-1] && arr[i]>arr[i+1]) || (arr[i]<arr[i-1] && arr[i]<arr[i+1]))
         v.push_back(arr[i]);
    } 
    v.push_back(arr[n-1]);
    cout<<v.size()<<endl;
    for(auto x : v)
      cout<<x<<" ";
   cout<<endl;
	return ;

}
int main()
{	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ll t;
	cin>>t;
	while(t--)
	solve();		
	return 0;
}






