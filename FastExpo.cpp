#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll MOD = 1e9 + 7;
// fast exponentation
// basic idea is to divide the problem in sub problems 
// if the power of the number is odd then we can split that number as
// ODD POWER eg a^n where n is odd then we divide it as a*(a^(n-1)/2) ka sq 
// EVEN POWER ef a^n where n is even then we divide it as a^(n)/2 ka sq
ll fastExpo(int a,int n)
{	
	if(n==0)
		return 1;//base case
	ll subproblem = fastExpo(a,n/2);
	if(n & 1)
	return subproblem*subproblem*a;
	else
	return subproblem*subproblem; 
}
ll fastExpo(int a,int n)
{	
	if(n==0)
		return 1;//base case
	ll subproblem = fastExpo(a,n/2)%MOD;
	if(n & 1)
	return (((subproblem*subproblem)%MOD)*a)%MOD;
	else
	return (subproblem*subproblem)%MOD; 
}
// log n
// Linear recurrence eg f(i) = f(i-1) + f(i-2) (fibonacci)
/* 
	To solve LR we use matrix exponentation which will solve it in O(k^3 LogN)
	for fibonacci its O(2^3 LogN) where k is 2
	S-1) Find k
	S-2) Find first k terms of the sequence
	S-3) Find Matrix T (kxk) which is also known as transformation matrix
		

   */
int main()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n,a;
	cin>>a>>n;
	cout<<fastExpo(a,n);
	return 0;
}