#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=100000;
vector<ll> primes;//will have the primes till 1e5

ll p[100001]={0};//to exclude primes from range m to n

//  main idea is to mark all multiples of primes till n in a given range to find primes in that range 
void sieve()
{	
	for(int i=2;i<=N;i++)
	{	
		if(p[i]==0)//mark all multiples as not prime
		{	primes.push_back(i);
			for(int j=2*i;j<=N;j+=i)
			{
				p[j]=1;//not prime
			}
		}
	}
}


int main()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif
	sieve();

	int t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>m>>n;//find primes between m and n
		bool segment[n-m+1];//as n-m<=1e5
		for(int i=0;i<=n-m+1;i++)
		{
			segment[i]=0;//initialising
		}

		//segment sieve logic
		for(auto x:primes)
		{	if(x*x>n)
			break;
			int start=(m/x)*x;//will give the first multiple of x
			if(x>=m && x<=n)
			{
				start=2*x;
			}
			for(int i=start;i<=n;i+=x)
			{
				segment[i-m]=1;//lets say number is 50 then index 0 will be start which is 50-m=0
			}
		}
		for(int i=m;i<=n;i++)
		{
			if(!segment[i-m] && i!=1)
			{
				cout<<i<<endl;
			}
		}
	}
	return 0;
}