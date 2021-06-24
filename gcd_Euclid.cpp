#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int gcd(int a,int b)
{
	return (b==0)?a:gcd(b,a%b);
}

int lcm(int a,int b)
{
	return (a*b)/gcd(a,b);			//lcm*gcd=a*b
}





int main()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	cout<<giveAns(n)<<endl;
	return 0;
}