#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int p[1000001]={0};
void printFactor(int n)
{	

	vector<pair<int,int>> factor;
	for(int i=2;i*i<n;i++)//will go till root n 
	{
		if(n%i==0)
		{	int cnt=0;	
			while(n%i==0)//count no of times it is divided by that prime factor
			{
				n/=i;
				cnt++;

			}
		 factor.push_back({i,cnt});
		}
	}
	if(n!=1)//means the remaining part itself is prime
	{
		factor.push_back({n,1});
	}
	for(auto x:factor)
	{
		cout<<x.first<<"-"<<x.second<<endl;
	}
}


//using sieve (mostly used in queries)

vector<int> prime_sieve()
{
	for(int i=3;i<=1000000;i+=2)
		p[i]=1;
	for(ll i=3;i<=1000000;i++)
	{
		if(p[i])
		{
			for(ll j=i*i;j<=1000000;j+=i)
				p[j]=0;
		}
	}
	p[2]=1;
	p[1]=p[0]=0;
	vector<int> v;
	for(int i=0;i<=10000;i++)
	{
		if(p[i])
			v.push_back(i);
	}
	return v;
}

void factorize(int n,vector<int> &primes)
{
	vector<pair<int,int>> factor;
	int i=0;
	int p=primes[i];
		while(p*p<=n)
		{
			if(n%p==0)
			{
				int cnt=0;
				while(n%p==0)
				{
					n/=p;
					cnt++;
				}
				factor.push_back({p,cnt});
			}
			i++;
			p=primes[i];			
		}
		if(n!=1)
			factor.push_back({n,1});
	for(auto x:factor)
	{
		cout<<x.first<<"-"<<x.second<<endl;
	}

}
int noOfDivisors(int n,vector<int> &primes)
{
	int ans=1;
	int i=0;
	int p=primes[i];
		while(p*p<=n)
		{
			if(n%p==0)
			{
				int cnt=0;
				while(n%p==0)
				{
					n/=p;
					cnt++;
				}
				ans*=(++cnt);
			}
			i++;
			p=primes[i];			
		}
		if(n!=1)
			ans*=2;
	return ans;

}


int main()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif
	vector<int> primes;
	primes=prime_sieve();
	cout<<noOfDivisors(10,primes);	
	return 0;	
}