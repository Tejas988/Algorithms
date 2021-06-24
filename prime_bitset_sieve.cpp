#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


const long n=1e7;
bitset<1000005> b;
ll ncr(int n, int r) 
{ 
    ll  p = 1, k = 1;  
    if (n - r < r) 
        r = n - r; 
    if (r != 0) { 
        while (r) { 
            p *= n; 
            k *= r; 
            ll m = __gcd(p, k); 
  
            p /= m; 
            k /= m; 
  
            n--; 
            r--; 
        } 
    } 
    else
        p = 1; 
    return p;
} 
vector<ll> primes;
void sieve()
{
	b.set();//made all bits 1
	b[0]=0;
	b[1]=0;
	cout<<"s";
	for(int i=2;i<=n;i++)
	{	
		if(b[i])//means it is a prime now mark its multiples as 0
		{	
			primes.push_back(b[i]);
			for(int j=i;j<=n;j+=i)
			{
				b[j]=0;
			}
		}
	}
}

bool isPrime(ll No)//works for greater nos as well coz we basically check till root n of that no
{
	if(No<=n)
	{
		return (b[No])?true:false;
	}
	for(ll i=0;primes[i]*(ll)primes[i]<No;i++)
	{
		if(No%primes[i]==0)
		{
			return false;
		}
	}
	return true;
}
int main()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif
	sieve();
	if(isPrime(2147483647))
		cout<<"YES";
	else
		cout<<"No";
	return 0;
}