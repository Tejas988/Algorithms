#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool isOdd(ll x)
{
	return (x & 1)?true:false;
}

vector<string> split(const string& str, char delim) {
    vector<string> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        strings.push_back(str.substr(start, end - start));
    }
    return strings;
}

//get ith bit
ll getBit(ll x,ll i)
{
	return (x & (1<<i))?1:0;
}

void setBit(ll &x,ll i)
{	
	x= (x | (1<<i)) ;
	return; 
}

void clearBit(ll &x, ll i)
{
	ll mask = ~(1<<i);
	x = (x & mask);
	return ;
}

void updateBit(ll &n,ll i, ll v)
{	
	clearBit(n,i);
	ll mask = v<<i;
	n = (n | mask);
	return; 
}

ll clearLastIBits(ll n,ll i)
{	// i equals no of bits cleared
	ll allOnes = ~0;
	return (n & (allOnes<<i));
}

ll clearItoJBits(ll n,ll i,ll j)
{	//i<j and indexinf from 0 starting from right
	ll allOnes = ~0;
	ll OnesAfterJ = allOnes<<(j+1); //111100000
	ll OnesBeforeI = (1<<i)-1; //000000011 where i is 2;
	ll mask = (OnesBeforeI | OnesAfterJ );//111100011
	return n & mask;	
}
int countSetBits(ll n)
{
	int ans=0;
	while(n>0)
	{
		ans += (n & 1);
		n=n>>1;
	}
	return ans;
}
int countSetBitsFast(ll n)
{
	int ans=0;
	while(n>0)
	{
		n = n & (n-1);//will remove the LSB
		ans++;
	}
	return ans;
	//__builtin_popcount() can also be used;
}
ll decimalToBin(ll n)
{
	ll ans=0,p=1;
	while(n>0)
	{
		ll currBit = n & 1;
		n=n>>1;
		ans+=p*currBit; 
		p*=10;
	}
	return ans;
}
ll fast_expo(int a,int n)
{
	ll ans=1;
	while(n>0)
	{
		int last_bit = n & 1;
		if(last_bit)
		{
			ans*=a;
		}
		n = n>>1;
		a = a*a;
	}
	return ans;
}

int main()
{	
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("opps.txt","w",stdout);
	#endif
	int n,a;
	cin>>a>>n;	
	cout<<fast_expo(a,n)<<endl;
	return 0;
}