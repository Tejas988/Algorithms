#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll k,n;
int longSubarrWthSumDivByK(ll arr[]) 
{ 
   ll div[n+1];
   div[0]=0;
   bool f=true;
   for(ll i=0;i<n;i++)
   {
   		div[i+1]=(arr[i]%k);
         if(div[i+1])
            f=false;
   }
   if(f)
      return -1;
   int i=0,j=n;
   while(i<=j)
   {
   	if(div[i]!=0 || div[j]!=0)
   	{     
            if(i==j)
            return 1;  
   			return j-i;
   	}
   	else
   	{
   		if(div[i+1]==0 && div[j-1]==0)
   		{
   			i++;
   			j--;
   		}
   		else
   		{
   			return j-1-i;
   		}

   	}

   }
    return -1; 
}   
void solve()
{
	ll l=0,x;
	cin>>n>>k;
	ll arr[n];
	for(ll i=0;i<n;i++)
	{
		cin>>x;
		arr[i]=x+l;
		l=arr[i];
	}
	cout<<longSubarrWthSumDivByK(arr)<<endl;
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






