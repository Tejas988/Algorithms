#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int p[10000001]={0};

void prime_sieve()
{
	for(int i=3;i<=10000000;i+=2)
		p[i]=1;
	for(ll i=3;i<=10000000;i++)
	{
		if(p[i])
		{
			for(ll j=i*i;j<=10000000;j+=i)
				p[j]=0;
		}
	}
	p[2]=1;
	p[1]=p[0]=0;
}

int main()
{	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif
	prime_sieve();
	
}