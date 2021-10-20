#include <bits/stdc++.h>
using namespace std;
typedef long long ll ll;

ll portfolio_profit_maximisation(ll maxSum, vector<ll> a, vector<ll> b) {
    ll n=a.size();
    ll m=b.size();
    a.push_back(1e10);
    b.push_back(1e10);
    int i=0,j=0;
    ll sum=0;
    ll ans=0;
    while(i<n and j<m)
    {
    	ll x=a[i];
    	ll y=b[j];
    	sum+=min(x);
    	if(sum>maxSum)
    	{
    		break;
    	}
    	if(x<y)
    		i+=1;
    	else
    		j+=1;
    	ans+=1;
    }	
    return ans;
}	

int main()
{
    ios::sync_with_stdio(false);

    ll n, m, x;
    cin >> n >> m >> x;

    vector<ll> a(n);
    vector<ll> b(m);

    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (ll i = 0; i < m; ++i) {
        cin >> b[i];
    }
    ll result = portfolio_profit_maximisation(maxSum, a, b);
    cout << result;
    return 0;
}