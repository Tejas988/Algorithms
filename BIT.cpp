#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int inp[10000];
int BIT[10001]={0};


//odd indexes store single value of that particular index


void update(int i,int inc,int N)
{
	while(i<=N)
	{
		BIT[i]+=inc;
		i += (i & -i); //adding the rightmost set bit val
	}
}
//sqrt decomp
https://www.youtube.com/watch?v=yjHDwnONdI8&feature=youtu.be
https://www.youtube.com/watch?v=AcvVlneAYZE&feature=youtu.be
int query(int i)
{
	int ans=0;
	while(i>=0)
	{
		ans+=BIT[i];
		i -= (i & -i);
	}
	return ans;
}
int main()
{
	#ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n;
    cin>>n;	
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	update(i,a[i],n);
    }
    //inversion count
    int ans=0;
    for(int i=n;i>=1;i--)
    {
    	ans+=query(a[i]-1);
    	update(a[i],1,n);
    }
}